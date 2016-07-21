CC = g++
CCFLAGS = -std=c++0x -g -Wall 
LDFLAGS = -pthread
HEADERS = data_structures.h ll.h bm.h
SOURCES = ll.cc bm.cc main.cc
OBJECTS = $(SOURCES:.cc=.o)
#THREAD_HEADERS = data_structures.h ll.h bm.h
THREAD_SOURCES = thread_main.cc
THREAD_OBJECTS = $(THREAD_SOURCES:.cc=.o)
#OBJECTS = ll.o
##### ll target
default: test

%.o: %.cc $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

thread%.o: thread%.cc
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)
#ll.o: ll.cc $(HEADERS)
#	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

#ll: ll.o
#	$(CC) ll.o -o $@

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

thread_test: $(THREAD_OBJECTS)
	$(CC) $(THREAD_OBJECTS) -o $@

ll_clean:
	-rm -f $(OBJECTS)
	-rm -f ll 

clean:
	-rm -f *.o
	-rm -f ll 
	-rm -f bm 
	-rm -f test 
	-rm -f thread_test 
