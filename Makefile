LDFLAGS += -lm

hhr: main.o gennumber.o interaction.o
	$(CC) *.o -o hhr $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o hhr

