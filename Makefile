all: BufferEntrada BufferSaida Utils Ordena
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

Ordena:
	gcc -g -c Ordena.c