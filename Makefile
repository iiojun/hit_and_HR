numquiz: main.o gennumber.o interaction.o
	gcc *.o -o numquiz

clean:
	rm *.o numquiz

