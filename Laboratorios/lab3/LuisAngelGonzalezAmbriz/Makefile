#Archivo Makefile con onjetivos falsos y valriables

comodin=$(patsubst %.c,%.o,$(wildcard *.c))
PROYECTO=muestreo
DESTDIR=/usr/local/bin
LDFLAGS=-lm
CC=gcc

all: $(PROYECTO)

$(PROYECTO): $(comodin)
	$(CC) $^ -o $@ $(LDFLAGS)

.PHONY: clean

install: all
	if [ ! -d $(DESTDIR) ] ; then \
		sudo mkdir $(DESTDIR) ; \
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm $(DESTDIR)/$(PROYECTO)

clean:
	rm -f *.o $(PROYECTO)
