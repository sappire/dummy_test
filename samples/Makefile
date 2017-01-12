CC = g++
CCFLAGS = -std=c++0x -g -Wall 
LDFLAGS = -pthread
HEADERS = data_structures.h ll.h bm.h
SOURCES = ll.cc main.cc
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
SORT_HEADERS = data_structures.h sort.h
SORT_SOURCES = sort.cc sort_main.cc
SORT_OBJECTS = $(SORT_SOURCES:.cc=.o)
BM_HEADERS = data_structures.h bm.h
BM_SOURCES = bm.cc bm_main.cc
BM_OBJECTS = $(BM_SOURCES:.cc=.o)
STRING_HEADERS = string_h.h
STRING_SOURCES = string_h.cc string_main.cc
STRING_OBJECTS = $(STRING_SOURCES:.cc=.o)
DP_HEADERS = dp.h
DP_SOURCES = dp.cc dp_main.cc
DP_OBJECTS = $(DP_SOURCES:.cc=.o)
STACK_HEADER = stack.h
STACK_SOURCES = stack_main.cc
STACK_OBJECTS = $(STACK_SOURCES:.cc=.o)
FILE_HEADER = file_io.h
FILE_SOURCES = file_io.cc file_main.cc
FILE_OBJECTS = $(FILE_SOURCES:.cc=.o)
ARRAY_HEADER = arr.h
ARRAY_SOURCES = arr.cc arr_main.cc
ARRAY_OBJECTS = $(ARRAY_SOURCES:.cc=.o)
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

sort%.o: sort%.cc $(SORT_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

bm%.o: bm%.cc $(BM_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

string%.o: string%.cc $(STRING_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

dp%.o: dp%.cc $(DP_HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

stack%.o: stack%.cc $(STACK_HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

file%.o: file_io%.cc $(FILE_HEADER)
	$(CC) $(CCFLAGS) -c $< -o $@ $(LDFLAGS)

arr%.o: arr%.cc $(ARRAY_HEADER)
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

sort_test: $(SORT_OBJECTS)
	$(CC) $(SORT_OBJECTS) -o $@

bm_test: $(BM_OBJECTS)
	$(CC) $(BM_OBJECTS) -o $@

string_test: $(STRING_OBJECTS)
	$(CC) $(STRING_OBJECTS) -o $@

stack_test: $(STACK_OBJECTS)
	$(CC) $(STACK_OBJECTS) -o $@

file_test: $(FILE_OBJECTS)
	$(CC) $(FILE_OBJECTS) -o $@

arr_test: $(ARRAY_OBJECTS)
	$(CC) $(ARRAY_OBJECTS) -o $@

ll_clean:
	-rm -f $(OBJECTS)
	-rm -f ll 

clean:
	-rm -f *.o
	-rm -f ll 
	-rm -f bm 
	-rm -f test 
	-rm -f *_test 
