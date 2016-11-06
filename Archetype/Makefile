#Makefile for Programming Contests

CC=g++
CFLAGS=-g -std=c++14 -O0 -Wall -Wextra
# CXXS = $(wildcard *.cpp)

# all: $(CXXS: %.cpp)

.PHONY: all
all: A B C D E

A: A.o
	$(CC) $(CFLAGS) -o $@.out $<

A.o: A.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

B: B.o
	$(CC) $(CFLAGS) -o $@.out $<

B.o: B.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

C: C.o
	$(CC) $(CFLAGS) -o $@.out $<

C.o: C.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

D: D.o
	$(CC) $(CFLAGS) -o $@.out $<

D.o: D.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

E: E.o
	$(CC) $(CFLAGS) -o $@.out $<

E.o: E.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: templates
templates:
	cp -r template.cpp A.cpp
	cp -r template.cpp B.cpp
	cp -r template.cpp C.cpp
	cp -r template.cpp D.cpp
	cp -r template.cpp E.cpp
	touch A.txt
	touch B.txt
	touch C.txt
	touch D.txt
	touch E.txt

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
	rm -r *~ *.out *.o *.dSYM

.SUFFIXES:
