# Compiler
CC = gcc

# Compiler flags, Assuming Python.h is located in this path.
CFLAGS = -I/usr/include/python3.12

# Linker flags, Assuming python lib is located in this path.
LDFLAGS = -L/lib/x86_64-linux-gnu -lpython3.12

# Source files
SRCS = inpy_demo.c interface_py.c

# Dependencies
DEPS = interface_py.h
$(TARGET): $(SRCS) $(DEPS)

# Output binary
TARGET = inpy_demo

# Target
all: $(TARGET)

# Linking
$(TARGET): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)

# Clean up 
clean:
	rm -f $(TARGET)
