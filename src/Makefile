a.out:service.o config_array.o file_operations.o str_operations.o
	gcc -o a.out service.o config_array.o file_operations.o str_operations.o
service.o: config_array.h
	gcc -c service.c
config_array.o:config_array.h file_operations.h str_operations.h
	gcc -c config_array.c
str_operations.o:str_operations.h
	gcc -c str_operations.c
file_operations.o:file_operations.h
	gcc -c file_operations.c

clear:
	rm *.o
