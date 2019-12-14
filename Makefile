# make file
# make / make ALL for making everything (except fs)
# make init to compile init
# make utils to make utilites
# make fs to make fs

ALL:
	echo compiling all
	rm -rf bin
	mkdir bin
	mkdir bin/utils/
	make init
	make utils
	gcc -o bin/circa src/ank/main.c src/utils/shell.c src/ank/syscall.c -I src/headers
	echo done
init:
	echo compiling init
	gcc -o bin/init src/ank/init.c

utils:
	echo compiling utils
	gcc -o bin/utils/cat src/utils/cat.c
	gcc -o bin/utils/cp src/utils/cp.c
	gcc -o bin/utils/chmod src/utils/chmod.c
	gcc -o bin/utils/date src/utils/date.c
	gcc -o bin/utils/df src/utils/df.c src/ank/syscall.c -I src/headers
	gcc -o bin/utils/head src/utils/head.c src/ank/syscall.c -I src/headers
	gcc -o bin/utils/ln src/utils/ln.c
	gcc -o bin/utils/ls src/utils/ls.c src/ank/syscall.c -I src/headers
	gcc -o bin/utils/mkdir src/utils/mkdir.c
	gcc -o bin/utils/mv src/utils/mv.c
	gcc -o bin/utils/rm src/utils/rm.c src/ank/syscall.c -I src/headers
	gcc -o bin/utils/tail src/utils/tail.c src/ank/syscall.c -I src/headers
	gcc -o bin/utils/xxd src/utils/xxd.c
	gcc -o bin/utils/yes src/utils/yes.c

fs:
	rm -rf cfs
	mkdir cfs
	echo making fs
	mkdir cfs/binaries/
	cp bin/utils/* cfs/binaries
	cp bin/circa   cfs/binaries/
	cp bin/init    cfs/init

clean:
	rm -rf cfs bin
