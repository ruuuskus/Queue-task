CXX = g++


CXXFLAGS = -std=c++17 -Wall -Wextra -g


TARGET = app


SRCS = main.cpp Queue.cpp


OBJS = $(SRCS:.cpp=.o)




all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


%.o: %.cpp Queue.h
	$(CXX) $(CXXFLAGS) -c $< -o $@




run: $(TARGET)
	./$(TARGET)


clean:
	rm -f $(OBJS) $(TARGET)


.PHONY: all run clean