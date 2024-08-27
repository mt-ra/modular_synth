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
CXXFLAGS := -pthread -std=c++20
LDFLAGS := -lrt -lasound -ljack -pthread

# Main Application #####
all: $(BUILD_DIR)/main.o $(BUILD_DIR)/AppExample.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o app
	echo "success linking"

$(BUILD_DIR)/main.o: main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making main.o"

$(BUILD_DIR)/AppExample.o: $(SRC_DIR)/app/AppExample.cpp $(INCLUDE_DIR)/app/AppExample.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making AppExample.o"

# Controllers #####
$(BUILD_DIR)/Controllers.o: $(BUILD_DIR)/Controller.o $(BUILD_DIR)/MidiStream_PortAudio.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	echo "success making combined Controllers object file"

$(BUILD_DIR)/Controller.o: $(SRC_DIR)/engine/Controllers/Controller.cpp $(INCLUDE_DIR)/engine/Controllers/Controller.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making Controller.o"

$(BUILD_DIR)/MidiStream_PortAudio.o: $(SRC_DIR)/engine/Controllers/MidiStream_PortAudio.cpp $(INCLUDE_DIR)/engine/Controllers/MidiStream_PortAudio.hpp $(INCLUDE_DIR)/engine/Controllers/Controller.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making MidiStream_PortAudio.o"

# Modules #####
$(BUILD_DIR)/Modules.o: $(BUILD_DIR)/Module.o $(BUILD_DIR)/VoltageModule.o $(BUILD_DIR)/MidiModule.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
	echo "success making combined Modules object file"

$(BUILD_DIR)/Module.o: $(SRC_DIR)/engine/Modules/Module.cpp $(INCLUDE_DIR)/engine/Modules/Module.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making Module.o"

$(BUILD_DIR)/VoltageModule.o: $(SRC_DIR)/engine/Modules/VoltageModule.cpp $(INCLUDE_DIR)/engine/Modules/VoltageModule.hpp $(INCLUDE_DIR)/engine/Modules/Module.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making VoltageModule.o"

$(BUILD_DIR)/MidiModule.o: $(SRC_DIR)/engine/Modules/MidiModule.cpp $(INCLUDE_DIR)/engine/Modules/MidiModule.hpp $(INCLUDE_DIR)/engine/Modules/Module.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@
	echo "success making MidiModule.o"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o app