TARGET := link_queue
SRC := link_queue.c link_queue_test.c
OBJ := link_queue.o link_queue_test.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)  
%.o : %.c
	gcc -o $@ $< -c 
clean : 
	rm -rf *.o $(TARGET)