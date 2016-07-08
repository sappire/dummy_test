CC = g++
CCFLAGS = -std=c++0x -g -Wall 
LDFLAGS = -pthread
HEADERS = data_structures.h ll.h
SOURCES = ll.cc main.cc
OBJECTS = $(SOURCES:.cc=.o)
#OBJECTS = ll.o
##### ll target
default: test

%.o: %.cc $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

#ll.o: ll.cc $(HEADERS)
#	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

#ll: ll.o
#	$(CC) ll.o -o $@

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

ll_clean:
	-rm -f $(OBJECTS)
	-rm -f ll 

clean:
	-rm -f *.o
	-rm -f ll 
	-rm -f test 
