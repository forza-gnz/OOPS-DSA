CC = g++
CFLAGS = -O3 -std=c++17
TARG = L10Q1
#Change CS22B200 to your filename: CS22Bxyc-Labx-Q1.cpp 
DEPS = CS22B055-Lab10-Q1.o Graph.o GraphAdjList.o

$(TARG): $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(DEPS)

CS22B055-Lab10-Q1.o: CS22B055-Lab10-Q1.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

Graph.o: Graph.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

GraphAdjList.o: GraphAdjList.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

#General rule for all other files with header to generate
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o *Q1
