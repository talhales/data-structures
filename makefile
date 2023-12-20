tum: derleme calistirma


derleme:
	g++ -I ./include/ -o ./lib/baglilist.o -c ./src/baglilist.cpp
	g++ -I ./include/ -o ./lib/kromozom.o -c ./src/kromozom.cpp
	g++ -I ./include/ -o ./bin/main ./lib/baglilist.o ./lib/kromozom.o ./src/main.cpp




calistirma:
	./bin/main
