all: BufferEntrada BufferSaida Utils ordena
	gcc -g main.c -o main *.o
	rm *.o
	
Utils:
	gcc -g -c Utils.c

BufferEntrada:
	gcc -g -c BufferEntrada.c

BufferSaida:
	gcc -g -c BufferSaida.c

teste:
	gcc teste.c -o teste

ordena:
	gcc -g -c ordena.c