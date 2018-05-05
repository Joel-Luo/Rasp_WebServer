all:	client rmobj
LIBS=-I/usr/local/include/ 
CC=g++
CFLAGS=

client:	*.o 
	$(CC) $(CFLAGS) *.o -o client $(LIBS)

*.o: *.cpp
	$(CC) $(CFLAGS) -c *.cpp

.PHONY: clean
clean:
	rm -f *.o WebSerclientver
rmobj:
	rm -f *.o   