connect_4: main.o helpers.o board.o fileManager.o game.o player.o human.o computer.o utility.o
	g++ connect_4 main.o helpers.o board.o fileManager.o game.o player.o human.o computer.o utility.o
main.o: main.cpp helpers.h board.h fileManager.h game.h player.h human.h computer.h utility.helper
	g++ -c main.cpp
helpers.o: helpers.h helpers.cpp
	g++ -c helpers.cpp
board.o: board.h board.cpp
	g++ -c board.cpp
fileManager.o: fileManager.h fileManager.cpp
	g++ -c fileManager.cpp
game.o: game.h game.cpp
	g++ -c game.cpp
player.o: player.h player.cpp
	g++ -c player.cpp
human.o: human.h human.cpp
	g++ -c human.cpp
computer.o: computer.h computer.cpp
	g++ -c computer.cpp
utility.o: utility.h utility.cpp
	g++ -c utility.cpp
clean:
	rm *.o connect_4