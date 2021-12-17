CFLAGS =	-g -Wall
LDFLAGS= -levent -lpthread

libevent_echosrv_buffered: libevent_echosrv_buffered.c
	$(CC) $(CFLAGS) -o $@ libevent_echosrv_buffered.c $(LDFLAGS)
clean:
	rm -f libevent_echosrv_buffered *~
