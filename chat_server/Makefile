CFLAGS =	-g -Wall
LIBS =		-levent -lpthread

chat-server: chat-server.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f chat-server *~
