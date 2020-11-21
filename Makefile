#Makefile

FLAG = -pedantic-errors -std=c++11

functions.o: functions.cpp functions.h
	g++ $(FLAG) -c functions.cpp

typing_game_main.o: typing_game_main.cpp functions.h
	g++ $(FLAG) -c typing_game_main.cpp

typing_game: functions.o typing_game_main.o
	g++ $(FLAG) functions.o typing_game_main.o -o typing_game

clean:
	rm -f typing_game typing_game_main.o functions.o

.PHONY: clean
