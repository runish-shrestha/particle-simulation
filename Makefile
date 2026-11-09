CC     := clang
BUILD  := build
TARGET := $(BUILD)/app

BASE_CFLAGS   := -std=c23 -Wall -Werror -g -Isrc -MMD -MP
RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)
RAYLIB_LDLIBS := $(shell pkg-config --libs raylib)

CFLAGS := $(BASE_CFLAGS) $(RAYLIB_CFLAGS)
LDLIBS := $(RAYLIB_LDLIBS) -lm

# == App ==

SRCS := $(shell find src -name '*.c')
OBJS := $(SRCS:src/%.c=$(BUILD)/%.o)

# == Tests ==

TEST_CFLAGS := $(CFLAGS) -Itests
TEST_LDLIBS := $(LDLIBS)

# Library code the tests link against (everything except main.o)
TEST_LIB_OBJS := $(filter-out $(BUILD)/main.o,$(OBJS))

# Every .c file under tests/ is its own executable
TEST_SRCS := $(shell find tests -name '*.c')
TEST_OBJS := $(TEST_SRCS:tests/%.c=$(BUILD)/tests/%.o)
TEST_BINS := $(TEST_SRCS:tests/%.c=$(BUILD)/tests/%)

ifeq ($(strip $(TEST_SRCS)),)
$(warning No test sources found under tests/)
endif

DEPS := $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)

# Keep test objects instead of deleting them as intermediates
.SECONDARY: $(TEST_OBJS)

# == App rules ==

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDLIBS)

$(BUILD)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# == Test rules ==

$(BUILD)/tests/%.o: tests/%.c
	@mkdir -p $(@D)
	@$(CC) $(TEST_CFLAGS) -c $< -o $@

$(BUILD)/tests/%: $(BUILD)/tests/%.o $(TEST_LIB_OBJS)
	@$(CC) $^ -o $@ $(TEST_LDLIBS)

# == Phony targets ==

.PHONY: run test clean

run: $(TARGET)
	./$(TARGET)

test: $(TEST_BINS)
	@for t in $(TEST_BINS); do \
	  ./$$t || exit 1; \
	done

clean:
	rm -rf $(BUILD)

-include $(DEPS)
