a.out:service.o config.o file_operations.o
	gcc -o a.out service.o config.o file_operations.o
service.o: config.h
	gcc -c service.c
config.o:config_array.h file_operations.h
	gcc -c config_array.c
file_operations.o:file_operations.h
	gcc -c file_operations.c
