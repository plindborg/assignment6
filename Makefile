all: 
	gcc -c -Wall -Werror -fpic component/component.c
	gcc -shared -o libcomponent.so component.o
	gcc -c -Wall -Werror -fpic -std=c99  resistance/resistance.c
	gcc -shared -o libresistance.so resistance.o
	gcc -c -Wall -Werror -fpic -std=c99  power/power.c
	gcc -shared -o libpower.so power.o
	gcc -L/home/pi/ass6/resistance/assignment6 -Wall -o test main.c -lcomponent -lresistance -lpower


 
 
