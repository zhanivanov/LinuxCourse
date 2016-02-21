# initializig variables
CC=gcc #compiler
CFLAGS=-c -Wall -O
LDFLAGS=
SOURCES=main.c calc.c figure.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=myexecutabe #output filename

all: 
	$(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	-rm -f *.o core *.core
