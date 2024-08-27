# READ ME:
# These directories might have to change depending on where you installed your libraries
BOOST_INCLUDE := /usr/local/boost_1_82_0
PORTAUDIO_INCLUDE := lib/portaudio/include 
PORTAUDIO_LIB := lib/portaudio/lib/.libs/libportaudio.a

CXX := g++
CPPFLAGS := -Iinclude -I$(BOOST_INCLUDE) -I$(PORTAUDIO_INCLUDE)
CXXFLAGS := -pthread -std=c++20
LDFLAGS := -lrt -lm -lasound -ljack -pthread

Modules := src/engine/Modules/*.cpp
Controllers := src/engine/Controllers/*.cpp
App := src/app/AppExample.cpp

all: $(wildcard $(Modules)) $(wildcard $(Controllers)) $(App) main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ $(PORTAUDIO_LIB) -o app


.PHONY: clean
clean:
	rm -rf build/*