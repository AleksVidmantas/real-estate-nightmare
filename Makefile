CC = g++ #sets compiler IF you want to use variables

a.out: complex.o driver.o game.o house.o player.o property.o tenant.o
	g++ -static -g complex.o driver.o game.o house.o player.o property.o tenant.o -o a.out #compiles after linking everything into an output file


complex.o: complex.cpp complex.h
	g++ -c complex.cpp complex.h

driver.o: driver.cpp
	g++ -c driver.cpp

game.o: game.cpp game.h
	g++ -c game.cpp game.h

house.o: house.cpp house.h
	g++ -c house.cpp house.h

#location.o: location.h
#	g++ -c location.h

player.o: player.cpp player.h
	g++ -c player.cpp player.h

property.o: property.cpp property.h
	g++ -c property.cpp property.h
tenant.o: tenant.cpp tenant.h
	g++ -c tenant.cpp tenant.h

clean:
	rm *.o output a.out *.h.gch