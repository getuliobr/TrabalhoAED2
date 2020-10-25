all: BufferEntrada BufferSaida Utils
	gcc -g main.c -o main *.o
	rm *.o
	
BufferEntrada:
	gcc -g -c ./Modules/BufferEntrada/BufferEntrada.c

BufferSaida:
	gcc -g -c ./Modules/BufferSaida/BufferSaida.c

Utils:
	gcc -g -c ./Modules/Utils/Utils.c

gerar:
	gcc -g ./Modules/Gerador/*.c -o gerar_arquivo

teste:
	gcc teste.c -o teste