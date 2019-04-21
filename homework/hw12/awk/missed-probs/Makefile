
# in a Makefile, two $ are needed for a bash variable
test:
	for t in test*.sh; do ./$$t; echo $$?; done

clean:
	rm -f temp* gold-out* diffs.txt

