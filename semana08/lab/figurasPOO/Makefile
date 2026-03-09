CXX := g++
SRC_DIR := src
BUILD_DIR := build
TARGET := $(BUILD_DIR)/main
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	@mkdir -p $(BUILD_DIR) 
	$(CXX) $(SOURCES) -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)
	rm -f *.o
