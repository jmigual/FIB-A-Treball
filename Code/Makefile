
DIRS 	= $(wildcard */)
FILES 	= $(foreach dir, $(DIRS), $(wildcard $(dir)*.cpp))
OBJS 	= $(foreach file, $(FILES), $(basename $(file)).o) main.o
EXECS 	= $(foreach dir, $(DIRS), $(subst /,,$(dir)))

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

all: $(EXECS)

$(EXECS): main.o $(filter $@%, $(OBJS))
	$(CXX) $(LDFLAGS) main.o $(filter $@%, $(OBJS)) -o $@/$@.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
	
clean:
	-rm $(OBJS) $(foreach dir, $(DIRS), $(dir)*.exe)

Makefile.deps: $(FILES)
	$(CXX) $(CXXFLAGS) -c -MM $(FILES) > Makefile.deps

-include Makefile.deps