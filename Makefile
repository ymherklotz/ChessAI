CC := g++ # this is the main compiler
# CC := clange --analyze # and comment out the linker last line
SRCDIR := src
BUILDDIR := build
TARGET := bin/chess_ai

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
<<<<<<< HEAD
CFLAGS := -g -Wall -Wextra -std=c++14
=======
CFLAGS := -g -Wall -Wextra -Wpedantic -std=c++14
>>>>>>> 95f75aa7aacf5e0e1ef11e8d200f84de44bd891f
LIB := 
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	@echo " $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester"; $(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	@echo " $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket"; $(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
