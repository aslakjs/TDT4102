# Name of the executable
EXECUTABLE := program

# Library path
GRAPH_LIB_DIR := /Library/tdt4102/Graph_lib
GRAPH_LIB_INCLUDE := $(GRAPH_LIB_DIR)/include
GRAPH_LIB_LIB := $(GRAPH_LIB_DIR)/lib

FLTK_DIR := /Library/tdt4102/FLTK
FLTK_INCLUDE := $(FLTK_DIR)/include
FLTK_LIB := $(FLTK_DIR)/lib

# Output directories
DEBUG_OUT := Debug
RELEASE_OUT := Release

# Use clang as compiler and linker
# Use C++14 and suppress false positive warnings
CXX = clang++
CXXFLAGS = -std=c++14 -Wall -Wno-overloaded-virtual -I$(GRAPH_LIB_INCLUDE)
LDFLAGS = -L$(GRAPH_LIB_LIB) -l$(GRAPH_LIB)
LINK = $(CXX)

# fltk-config returns compiler and linker flags needed to successfully
# build fltk programs.
CXXFLAGS += -I$(FLTK_INCLUDE) -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT #$(shell fltk-config --use-images --cxxflags) 
LDFLAGS += -L$(FLTK_LIB) -lfltk_images -lfltk_jpeg -lfltk_png -lfltk_z -lfltk -lpthread -framework Cocoa #$(shell fltk-config --use-images --ldflags) 

SOURCES := $(wildcard *.cpp)

ifdef DEBUG
CXXFLAGS += -g -O0 -DDEBUG
OUT := $(DEBUG_OUT)
GRAPH_LIB := Graph_libd
else
CXXFLAGS += -O3 -DNDEBUG
OUT := $(RELEASE_OUT)
GRAPH_LIB := Graph_lib
endif

OBJECTS := $(SOURCES:%.cpp=$(OUT)/%.o)

$(OUT):
	mkdir -p $@

$(OUT)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUT)/$(EXECUTABLE): $(OUT) $(OBJECTS)
	$(LINK) $(OBJECTS) -o $@ $(LDFLAGS)

.PHONY: runrelease rundebug
runrelease: release
	./$(RELEASE_OUT)/$(EXECUTABLE)
rundebug: debug
	./$(DEBUG_OUT)/$(EXECUTABLE)

.PHONY: clean cleandebug cleanrelease
clean: cleanrelease cleandebug
cleandebug:
	$(RM) -r $(DEBUG_OUT)
cleanrelease:
	$(RM) -r $(RELEASE_OUT)

# Helpers to build release and debug binaries
.PHONY: debug release
debug:
	DEBUG=1 $(MAKE) $(DEBUG_OUT)/$(EXECUTABLE)
release:
	$(MAKE) $(RELEASE_OUT)/$(EXECUTABLE)

# Helper to clear console before compilation
.PHONY: clearscreen

clearscreen:
	clear
