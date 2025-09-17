
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = submission

# Source files .cpp and .h files
SRC = cheng_p2.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Gate Directions
ARG1 = LLLLL

# Input String
ARG2 = 01010101

# Default rule
all: $(TARGET)

# Compile the main executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET) $(ARG1) $(ARG2)