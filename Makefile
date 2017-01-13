CC := g++ # this is the main compiler
# CC := clange --analyze # and comment out the linker last line
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := main

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -Wextra -Wpedantic -std=c++14
LIB :=
INC := -I include

$(TARGETDIR)/$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(TARGETDIR)
	@echo " $(CC) $^ -o $(TARGETDIR)/$(TARGET) $(LIB)"; $(CC) $^ -o $(TARGETDIR)/$(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGETDIR)/$(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGETDIR)/$(TARGET)

# Tests
tester:
	@echo " $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester"; $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	@echo " $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket"; $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
