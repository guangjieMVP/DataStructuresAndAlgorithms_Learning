TARGET := arr_queue
SRC := array_queue.c array_queue_test.c
OBJ := array_queue.o array_queue_test.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)  
%.o : %.c
	gcc -o $@ $< -c 
clean : 
	rm -rf *.o $(TARGET)