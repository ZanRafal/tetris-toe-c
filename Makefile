TicTacToe2: TicTacToe2.o methods.o
	gcc $^
TicTacToe2.o: TicTacToe2.c
	gcc -c $<
methods.o: methods.c
	gcc -c $<

clean:
	rm *.o a.out