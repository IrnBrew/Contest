#Makefile for Programming Contests

CC=g++
CXXFLAGS=-g -std=c++14 -O0 -Wall -Wextra
# CXXS = $(wildcard *.cpp)

# all: $(CXXS: %.cpp)

%.run: %.out
	./$< < $(patsubst %.run, %.txt, $@)

%.out:
	$(CC) $(CXXFLAGS) -o $@ $(patsubst %.out, %.cpp, $@)

.PHONY: all
all: A B C D E

A: A.o
	$(CC) $(CXXFLAGS) -o $@.out $<

A.o: A.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

B: B.o
	$(CC) $(CXXFLAGS) -o $@.out $<

B.o: B.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

C: C.o
	$(CC) $(CXXFLAGS) -o $@.out $<

C.o: C.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

D: D.o
	$(CC) $(CXXFLAGS) -o $@.out $<

D.o: D.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

E: E.o
	$(CC) $(CXXFLAGS) -o $@.out $<

E.o: E.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

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
