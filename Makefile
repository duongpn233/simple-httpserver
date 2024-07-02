CXX = g++
CXXFLAGS = -I./src/socket -I./src/httpserver -std=c++11 -Wall -Wextra
SRC_DIR = ./src
SOCKET_DIR = ./src/socket
HTTP_SERVER_DIR = ./src/httpserver
BUILD_DIR = ./build
SOURCES = $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SOCKET_DIR)/*.cc) $(wildcard $(HTTP_SERVER_DIR)/*.cc)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, \
          $(patsubst $(SOCKET_DIR)/%.cc, $(BUILD_DIR)/%.o, \
          $(patsubst $(HTTP_SERVER_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SOURCES))))
TARGET = $(BUILD_DIR)/main

build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SOCKET_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(HTTP_SERVER_DIR)/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: build
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build clean run
