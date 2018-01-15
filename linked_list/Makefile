CFLAGS = -g -Wall
TARGET = linked_list


all: $(TARGET)

$(TARGET): $(TARGET).c main.c
	gcc $(CFLAGS) -o linked_list $(TARGET).c main.c

clean:
	$(RM) $(TARGET)

run:
	./$(TARGET)