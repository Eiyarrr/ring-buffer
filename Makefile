BUILD_DIR = build
TARGET = test_ring_buffer

.PHONY: all build run clean

all: build

build:
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
