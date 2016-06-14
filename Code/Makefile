BUILD_FOLDER = build/

ifeq ($(strip $(WINDOWS)), 1)
	MKDIR_P = mkdir
	BUILD_FOLDER := $(subst /,\, $(BUILD_FOLDER))
endif

FILES 	= $(wildcard *.cpp) $(wildcard */*.cpp)
OBJS 	= $(foreach file, $(FILES), $(BUILD_FOLDER)$(basename $(file)).o)
EXEC    = SuperSopa.exe
FOLDERS = $(BUILD_FOLDER) $(foreach file, $(FILES), $(BUILD_FOLDER)$(dir $(file)))
DEPS 	= $(foreach file, $(FILES), $(BUILD_FOLDER)$(basename $(file)).d)

# Config
OPTIMIZE = 2 # Optimization level (0 to 3)
DEBUG    = 1 # Compile for debugging (0 or 1)
PROFILE  = 0 # Compile for profile (0 or 1)
WINDOWS  = 0 # Compile for windows (0 or 1)

MKDIR_P = mkdir -p

# Flags

ifeq ($(strip $(PROFILE)),1)
	PROFILEFLAGS=-pg
endif
ifeq ($(strip $(DEBUG)),1)
	DEBUGFLAGS=-DDEBUG -g
endif
ifeq ($(strip $(32BITS)),1)
	ARCHFLAGS=-m32 -L/usr/lib32
endif

CXXFLAGS = -Wall -Wextra -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE)) -I./
LDFLAGS  = -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE))

.PHONY: all folders

all: folders $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(BUILD_FOLDER)/$(EXEC)

$(BUILD_FOLDER)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	-rm $(OBJS) $(BUILD_FOLDER)/SuperSopa.exe Makefile.deps

folders:
	$(MKDIR_P) $(FOLDERS)

Makefile.deps: $(FILES)
	rm Makefile.deps
	$(CXX) $(CXXFLAGS) -c -MM $(FILES) -MT $(OBJS) > Makefile.deps
