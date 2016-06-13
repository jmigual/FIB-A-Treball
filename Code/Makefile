
DIRS 	= $(wildcard */)
# $(foreach dir, $(DIRS), $(wildcard $(dir)*.cpp))
FILES 	= $(wildcard *.cpp) 
OBJS 	= $(foreach file, $(FILES), $(basename $(file)).o)
EXEC    = SuperSopa.exe

# Config
OPTIMIZE = 2 # Optimization level (0 to 3)
DEBUG    = 1 # Compile for debugging (0 or 1)
PROFILE  = 0 # Compile for profile (0 or 1)

# Flags

ifeq ($(strip $(PROFILE)),1)
	PROFILEFLAGS=-pg
endif
ifeq ($(strip $(DEBUG)),1)
	DEBUGFLAGS=-DDEBUG -g -rdynamic
endif
ifeq ($(strip $(32BITS)),1)
	ARCHFLAGS=-m32 -L/usr/lib32
endif

CXXFLAGS = -Wall -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE)) #-Wextra
LDFLAGS  = -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE))

.PHONY: all

all: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	-rm $(OBJS) SuperSopa.exe

Makefile.deps: $(FILES)
	$(CXX) $(CXXFLAGS) -c -MM $(FILES) > Makefile.deps

-include Makefile.deps
