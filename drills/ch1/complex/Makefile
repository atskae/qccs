PROG = complex
CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11
OBJS = main.o

all: drill

%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)

drill: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROG)

clean:
	rm *.o $(PROG)
