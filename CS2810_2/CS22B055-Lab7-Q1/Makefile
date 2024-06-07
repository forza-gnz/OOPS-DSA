CC = g++
CFLAGS = -O3 -std=c++17
TARG = L7Q1
#Change CS22B200 to your filename: CS22Bxyc-Labx-Q1.cpp 
DEPS = CS22B200.o Graph.o GraphAdjList.o

$(TARG): $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(DEPS)

CS22B200.o: CS22B055-lab7-Q1.cpp 
	$(CC) $(CFLAGS) -c -o $@ $<

#General rule for all other files with header to generate
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o *Q1