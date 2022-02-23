startproduce: producer.o consumer.o
	./producer

producer.o: producer.c
	gcc producer.c -o producer -g -Wall
	
consumer.o: consumer.c
	gcc consumer.c -o consumer -g -Wall

clean:
	rm -f producer.o
	rm -f producer
	rm -f consumer.o
	rm -f consumer