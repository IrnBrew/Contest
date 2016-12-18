#Makefile for Programming Contests

CC=g++
CXXFLAGS=-g -std=c++14 -O0 -Wall -Wextra

# all: $(CXXS: %.cpp)

.PRECIOUS: %.out

%.run: %.out
	./$< < $(patsubst %.run, %.txt, $@)

%.out: %.cpp
	$(CC) $(CXXFLAGS) -o $@ $<

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

.PHONY: clean
clean:
	rm -r *~ *.out *.o *.dSYM

.SUFFIXES:
