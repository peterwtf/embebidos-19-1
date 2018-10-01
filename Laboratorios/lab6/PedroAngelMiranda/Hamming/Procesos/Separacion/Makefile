# Archivo Makefile simple
# En cada procesador diferente se debe recompilar porque tienen arquitecturas diferentes

PROYECTO=hpcProc
DESTDIR=/usr/local/bin
CFLAGS=-Wall
LDFLAGS=-lm -pthread
CC=gcc

all: $(PROYECTO)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

$(PROYECTO): $(patsubst %.c,%.o,$(wildcard *.c)) #muestreo.o procesamiento.o archivos.o  #WILDCARD, Funciones y sustitucion de cadenas
	$(CC) $^ -o $@ $(LDFLAGS)

.PHONY: clean

install: all
	if[ ! -d $(DESTDIR) ] ; then \
		sudo mkdir $(DESTDIR) ; \
	fi  \
		sudo cp $(PROYECTO) $(DESTDIR)

uninstall: 
	sudo rm $(DESTDIR)/$(PROYECTO)

clean: 
	rm -f *.o $(PROYECTO)
