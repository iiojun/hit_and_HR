TARGET 	= hhr
OBJS 	= main.o gennumber.o interaction.o
LDFLAGS += -lm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS) $(LDFLAGS)
# Note:
# '$@' means $(TARGET)

clean:
	-@ rm $(TARGET) $(OBJS) > /dev/null 2>&1
# Note:
# '-' ignores any errors
# '@' disables showing commands
# '> /dev/null 2>&1' makes any output discarded

.PHONY: clean

