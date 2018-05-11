test-static: test.c libstrace.a
	gcc -O2 test.c -L. -lstrace -o test-static -static

test-dynamic: test.c libstrace.so
	gcc -O2 test.c -L. -lstrace -o test-dynamic

libstrace.a: strace.c
	gcc -O2 -c strace.c
	ar rcs libstrace.a strace.o

libstrace.so: strace.c
	gcc -O2 -shared -fPIC strace.c -o libstrace.so

.PHONY: clean
clean:
	rm -f libstrace.* test-* *.o
