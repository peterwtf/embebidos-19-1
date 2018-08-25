PROYECTO=muestreo
DESTDIR=/usr/local/bin
CFLAGS=-Wall
LDFLAGS=-lm
CC=gcc

all: $(PROYECTO)

%.o: %.c
					$(CC) -c $< $(CFLAGS)

$(PROYECTO): procesamiento.o archivos.o muestreo.o
					$(CC) $^ -o $@	$(LDFLAGS)

.PHONY: clean

install: all
					if [ ! -d $(DESTDIR) ] ; then \
					sudo mkdir $(DESTDIR); \
					fi; \
					sudo cp $(PROYECTO) $(DESTDIR)

uninstall:
					sudo rm $(DESTDIR)/$(PROYECTO)

clean:
					rm -f *.o $(PROYECTO)