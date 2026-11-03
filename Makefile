CC 			:= clang
BUILD		:= build
TARGET 	:= $(BUILD)/app

CFLAGS 	:= -std=c23 -Wall -Werror -g -Isrc\
					 -MMD -MP\
					 $(shell pkg-config --cflags raylib)
LDLIBS 	:= $(shell pkg-config --libs raylib) -lm

SRCS := $(shell find src -name '*.c')
OBJS := $(SRCS:src/%.c=$(BUILD)/%.o)
DEPS := $(OBJS:.o=.d)

$(TARGET): $(OBJS)
	$(CC) $^ -o $@ $(LDLIBS)

$(BUILD)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run clean
run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD)

-include $(DEPS)
