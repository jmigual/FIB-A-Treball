# Config
OPTIMIZE = 2 # Optimization level (0 to 3)
DEBUG    = 1 # Compile for debugging (0 or 1)
PROFILE  = 0 # Compile for profile (0 or 1)
WINDOWS  = 0 # Compile for windows (0 or 1)

BUILD_FOLDER = build/

FILES 	= $(wildcard *.cpp) $(wildcard */*.cpp)
OBJS 	= $(FILES:%.cpp=$(BUILD_FOLDER)%.o)
EXEC    = SuperSopa.exe
DEPDIR 	= $(BUILD_FOLDER).d/
FOLDERS = $(foreach file, $(FILES), $(DEPDIR)$(dir $(file)) $(BUILD_FOLDER)$(dir $(file))) 


MKDIR_P = mkdir -p
RM 		= rm -R
MV 		= mv
ifeq ($(strip $(WINDOWS)), 1)
	FOLDERS := $(subst /,\, $(FOLDERS))
	MKDIR_P := mkdir
	RM 		:= del
	MV 		:= move
endif
$(shell $(MKDIR_P) $(FOLDERS))


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

CXXFLAGS = -Wall -Wextra -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE)) -I.
LDFLAGS  = -std=c++11 $(PROFILEFLAGS) $(DEBUGFLAGS) -O$(strip $(OPTIMIZE))
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)$*.d

.PHONY: all

all: $(OBJS) $(DEPS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(BUILD_FOLDER)$(EXEC)

$(BUILD_FOLDER)%.o: %.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@ 

clean:
	-$(RM) $(BUILD_FOLDER)

$(BUILD_FOLDER)%.d: %.cpp
	$(CXX) $(CXXFLAGS) -c -MM $< -o $@

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

-include $(patsubst %,$(DEPDIR)/%.d,$(basename $(FILES)))
