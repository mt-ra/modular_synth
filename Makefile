INCLUDE_DIR := include
BUILD_DIR := build
SRC_DIR := src

CXX := g++
CPPFLAGS := -I$(INCLUDE_DIR)
CXXFLAGS :=

# Linking the Application with the Engine
all: $(BUILD_DIR)/main.o $(BUILD_DIR)/AppExample.o
	$(CXX) $(CXXFLAGS) $^ -o app
	echo "success linking"

$(BUILD_DIR)/main.o: main.cpp $(INCLUDE_DIR)/app/AppExample.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making main.o"

$(BUILD_DIR)/AppExample.o: $(SRC_DIR)/app/AppExample.cpp $(INCLUDE_DIR)/app/AppExample.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making AppExample.o"

clean:
	rm -rf $(BUILD_DIR)/*.o app