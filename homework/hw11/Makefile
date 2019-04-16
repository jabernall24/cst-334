
test-sem: sem
	./sem | awk -f test-sem.awk

sem: sem.c
	gcc -pthread -lm -o sem sem.c

