all:	WebServer rmobj
LIBS=-I/usr/local/include/ -pthread
CC=g++
CFLAGS=-std=c++11

WebServer:	*.o 
	$(CC) $(CFLAGS) *.o -o WebServer $(LIBS)

*.o: *.cpp
	$(CC) $(CFLAGS) -c *.cpp

.PHONY: clean
clean:
	rm -f *.o WebServer
rmobj:
	rm -f *.o   