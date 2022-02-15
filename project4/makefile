all: slidingpuzzle-v4

slidingpuzzle-v4: slidingpuzzle-v4.o sp-tcp-client.o sp-tcp-server.o sp-game.o sp-server-functions.o sp-client-functions.o
	gcc -g -Wall -o slidingpuzzle-v4 slidingpuzzle-v4.o sp-tcp-client.o sp-tcp-server.o sp-game.o sp-server-functions.o sp-client-functions.o


slidingpuzzle-v4.o: slidingpuzzle-v4.c
	gcc -c slidingpuzzle-v4.c

sp-game.o: sp-game.c
	gcc -c sp-game.c

sp-tcp-client.o: sp-tcp-client.c sp-client-functions.h
	gcc -c sp-tcp-client.c sp-client-functions.h

sp-tcp-server.o: sp-tcp-server.c sp-server-functions.h
	gcc -c sp-tcp-server.c sp-server-functions.h

sp-client-functions.o: sp-client-functions.c sp-client-functions.h
	gcc -c sp-client-functions.c sp-client-functions.h

sp-server-functions.o: sp-server-functions.c sp-server-functions.h
	gcc -c sp-server-functions.c sp-server-functions.h

clean: 
	rm -f *.o
	rm -f slidingpuzzle-v4.o
	rm -f sp-tcp-client.o
	rm -f sp-tcp-server.o
	rm -f sp-game.o
	rm -f slidingpuzzle-v4
	rm -f sp-client-functions.h.gch
	rm -f sp-server-functions.h.gch

git:
	make clean
	git add .
	echo "Enter commit message:  with t= and b= tags"
	git commit -m "$t" -m "$b"
	git push

quick:
	make clean
	clear
	make
	