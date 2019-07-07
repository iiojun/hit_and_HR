LDFLAGS += -lm

numquiz: main.o gennumber.o interaction.o
	$(CC) *.o -o numquiz $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o numquiz

