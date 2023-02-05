GCC=-Wall -Werror -Wextra

all: graph.o polish_decoder.o stack.o
	gcc $(GCC) *.o -o ../build/graph
	make clean

graph.o: graph.c graph.h
	gcc $(GCC) -c graph.c

polish_decoder.o: polish_decoder.c polish_decoder.h
	gcc $(GCC) -c polish_decoder.c

stack.o: stack.c stack.h
	gcc $(GCC) -c stack.c

clean:
	rm -rf *.o

check:
	cp ../materials/linters/CPPLINT.cfg ../src
	python3 ../materials/linters/cpplint.py --extensions=c ../src/*.[ch]
	cppcheck --enable=all --suppress=missingIncludeSystem ../src/*.[ch]