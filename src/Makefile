a.out:service.o config_list.o nest_list.o file_operations.o str_operations.o
	gcc -g service.o config_list.o nest_list.o file_operations.o str_operations.o -o a.out
service.o: config_list.h
	gcc -c service.c
config_array.o:config_list.h file_operations.h str_operations.h nest_list.h
	gcc -c config_list.c
nest_list.o:nest_list.h
	gcc -c nest_list.c
str_operations.o:str_operations.h
	gcc -c str_operations.c
file_operations.o:file_operations.h
	gcc -c file_operations.c
clear:
	rm *.o
