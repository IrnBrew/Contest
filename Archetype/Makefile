#Makefile for Programming Contests

CC=g++
CFLAGS=-g -std=c++11 -Wall -Wextra -O2
# CXXS = $(wildcard *.cpp)

# all: $(CXXS: %.cpp)

.PHONY: all
all: A.out B.out C.out D.out E.out

A.out: A.o
	$(CC) $(CFLAGS) -o $@ $<

A.o: A.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

B.out: B.o
	$(CC) $(CFLAGS) -o $@ $<

B.o: B.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

C.out: C.o
	$(CC) $(CFLAGS) -o $@ $<

C.o: C.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

D.out: D.o
	$(CC) $(CFLAGS) -o $@ $<

D.o: D.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

E.out: E.o
	$(CC) $(CFLAGS) -o $@ $<

E.o: E.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: molds
molds:
	cp -r mold.cpp A.cpp
	cp -r mold.cpp B.cpp
	cp -r mold.cpp C.cpp
	cp -r mold.cpp D.cpp
	cp -r mold.cpp E.cpp

.PHONY: runA
runA:
	./A.out < A.txt

.PHONY: runB
runB:
	./B.out < B.txt

.PHONY: runC
runC:
	./C.out < C.txt

.PHONY: runD
runD:
	./D.out < D.txt

.PHONY: runE
runE:
	./E.out < E.txt

.PHONY: clean
clean:
	rm *~ *.o
