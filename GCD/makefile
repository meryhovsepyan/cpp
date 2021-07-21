.ONESHELL:
SHELL := /bin/bash
all: create_bin  bin/out
.PHONY: clean create_bin bin/out
bin/out: ./src/main.cpp ./src/gcd.cpp
	g++ $^ -o $@
create_bin:
	@mkdir -p bin
release: bin/out

diff:
	@if   diff -q  ./tst/goutput.txt ./tst/output.txt 	 
	@then
		echo "PASSED"
	@else
		echo "FAILED"
	@fi
	
debug:
	g++ ./src/main.cpp ./src/gcd.cpp -g -o bin/gout
	gdb ./bin/gout

test_run:
	@mkdir -p test_run

clean:
	rm -rf *.o main  bin/out bin  test_run gout
