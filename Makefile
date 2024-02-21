CC=g++
CFLAGS=-Wall -Wextra -O2
LIBS=-lpapi

all: fibonacci papi_fibonacci

fibonacci: fibonacci.cpp
	$(CC) $(CFLAGS) -o fibonacci fibonacci.cpp

papi_fibonacci: papi_fibonacci.cpp
	$(CC) $(CFLAGS) -o papi_fibonacci papi_fibonacci.cpp $(LIBS)

.PHONY: clean
clean:
	rm -f fibonacci papi_fibonacci
