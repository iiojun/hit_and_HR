numquiz: main.o gennumber.o interaction.o
	gcc *.o -o numquiz -lm

clean:
	rm *.o numquiz

