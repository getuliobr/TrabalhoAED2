all: BufferEntrada BufferSaida Utils
	gcc -g main.c -o main *.o
	rm *.o
	
BufferEntrada:
	gcc -g -c ./modules/BufferEntrada/BufferEntrada.c

BufferSaida:
	gcc -g -c ./modules/BufferSaida/BufferSaida.c

Utils:
	gcc -g -c ./modules/Utils/Utils.c

teste:
	gcc teste.c -o teste