
test:	pmsort
	./pmsort

pmsort: par_merge.c test_sort.c merge_sort.h
	gcc -o pmsort test_sort.c par_merge.c -pthread -Wall

clean:
	rm -f pmsort *~
