WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memchek.text --leak-check=full --verbose
TESTFLAGS = -DTEST_MAIN -DTEST_SHUFFLE -DTEST_DIVIDE -DTEST_INTERLEAVE
SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw11

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

	testmemory: hw11
		$(VAL) ./hw11 11

testall: test4 test8 test11

test4: hw11
	./hw11 4 | sort > output4
	diff -w output4 expected/expected4

test8: hw11
	./hw11 8 | sort > output8
	diff -w output8 expected/expected8

test11: hw11
	./hw11 11 | sort > output11
	diff -w output11 expected/expected11

clean:
	rm -f hw11 *.o output?
