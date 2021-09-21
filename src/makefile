CPP = g++
 
# compiler flags:
# Any additional compiler flags to add
CPPFLAGS  = 
 
# The build target 
TARGET = testProgram
 
all: $(TARGET)
 
$(TARGET): $(TARGET).cpp
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(TARGET).cpp
 
clean:
	$(RM) $(TARGET)

test: $(TARGET)
	echo "### Failed Test ###"
	./$(TARGET) || echo "FAILED"


	echo "### Successful Test ###"
	./$(TARGET) firstArgment || echo "FAILED"

