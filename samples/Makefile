CC = g++
CCFLAGS = -std=c++0x -g -Wall 
LDFLAGS = -pthread
HEADERS = data_structures.h ll.h bm.h
SOURCES = ll.cc bm.cc main.cc
OBJECTS = $(SOURCES:.cc=.o)
THREAD_HEADERS = thread_t.h
THREAD_SOURCES = thread_t.cc thread_main.cc
THREAD_OBJECTS = $(THREAD_SOURCES:.cc=.o)
BT_HEADERS = data_structures.h bin_t.h 
BT_SOURCES = bin_t.cc bin_t_main.cc
BT_OBJECTS = $(BT_SOURCES:.cc=.o)
GRAPH_HEADERS = data_structures.h graph.h
GRAPH_SOURCES = graph.cc graph_main.cc
GRAPH_OBJECTS = $(GRAPH_SOURCES:.cc=.o)
#OBJECTS = ll.o
##### ll target
default: test

%.o: %.cc $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

thread%.o: thread%.cc
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

bin_t%.o: bin_t%.cc $(BT_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

graph%.o: graph%.cc $(GRAPH_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)
#ll.o: ll.cc $(HEADERS)
#	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

#ll: ll.o
#	$(CC) ll.o -o $@

test: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

thread_test: $(THREAD_OBJECTS)
	$(CC) $(THREAD_OBJECTS) -o $@

bin_t_test: $(BT_OBJECTS)
	$(CC) $(BT_OBJECTS) -o $@

graph_test: $(GRAPH_OBJECTS)
	$(CC) $(GRAPH_OBJECTS) -o $@

ll_clean:
	-rm -f $(OBJECTS)
	-rm -f ll 

clean:
	-rm -f *.o
	-rm -f ll 
	-rm -f bm 
	-rm -f test 
	-rm -f thread_test 
	-rm -f bin_t_test 
	-rm -f graph_test 
