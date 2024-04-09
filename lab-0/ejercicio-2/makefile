CC = g++
CFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = a.h b.h c.h

TARGET = myprogram

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)