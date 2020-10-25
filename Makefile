all: BufferEntrada BufferSaida Utils Gerador
	gcc -g main.c -o main *.o
	rm *.o
	
BufferEntrada:
	gcc -g -c ./Modules/BufferEntrada/BufferEntrada.c

BufferSaida:
	gcc -g -c ./Modules/BufferSaida/BufferSaida.c

Utils:
	gcc -g -c ./Modules/Utils/Utils.c

Gerador:
	gcc -g -c ./Modules/Gerador/big_file.c

teste:
	gcc teste.c -o teste