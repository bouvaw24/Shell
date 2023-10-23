CC = clang
CFLAGS = -std=c17 -Wall -Wextra -O3
OBJS=example.o change_directory.o free_tokens.o read_input.o tokenize_input.o

%.o : %.c
		$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

example: $(OBJS)
	$(CC) $(CFLAGS) -o example $(OBJS)

clean:
	$(RM) example *.o


example.o: example.c header.h
change_directory.o: change_directory.c header.h
free_tokens.o: free_tokens.c header.h
read_input.o: read_input.c header.h
tokenize_input.o: tokenize_input.c header.h

