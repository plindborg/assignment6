all:
	gcc -shared -o libpower.so power.c
	gcc -o power main.c -L. -lpower
	export LD_LIBRARY_PATH=.
