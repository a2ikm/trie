vector: vector.c
	clang -o vector.out vector.c

clean:
	rm -rf *.out
