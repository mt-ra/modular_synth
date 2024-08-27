# READ ME:
# These directories might have to change depending on where you installed your libraries
BOOST_INCLUDE := /usr/local/boost_1_82_0
PORTAUDIO_INCLUDE := lib/portaudio/include 
PORTAUDIO_LIB := lib/portaudio/lib/.libs/libportaudio.a

# These directories should be fine
INCLUDE_DIR := include
BUILD_DIR := build
SRC_DIR := src

CXX := g++
CPPFLAGS := -I$(INCLUDE_DIR) -I$(BOOST_INCLUDE) -I$(PORTAUDIO_INCLUDE)
CXXFLAGS := -pthread
LDFLAGS := -lrt -lasound -ljack -pthread

# Linking the Application with the Engine
all: $(BUILD_DIR)/main.o $(BUILD_DIR)/AppExample.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o app
	echo "success linking"

$(BUILD_DIR)/main.o: main.cpp $(INCLUDE_DIR)/app/AppExample.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making main.o"

$(BUILD_DIR)/AppExample.o: $(SRC_DIR)/app/AppExample.cpp $(INCLUDE_DIR)/app/AppExample.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making AppExample.o"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o app