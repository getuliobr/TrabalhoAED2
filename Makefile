all: BufferEntrada BufferSaida Utils
	gcc -g main.c -o main *.o
	rm *.o
	
BufferEntrada:
	gcc -g -c BufferEntrada.c

BufferSaida:
	gcc -g -c BufferSaida.c

Utils:
	gcc -g -c Utils.c

teste:
	gcc teste.c -o teste