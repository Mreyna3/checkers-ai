to compile the program just run the makefile using the make command in the terminals
then to execute it type ./Jarvis

------------------------How to Play--------------------

the board is represented in the program by the grid

11 12 13 14 15 16 17 18
21 22 23 24 25 26 27 28
31 32 33 34 35 36 37 28
41 42 43 44 45 46 47 48
51 52 53 54 55 56 57 58
61 62 63 64 65 66 67 68
71 72 73 74 75 76 77 78
81 82 83 84 85 86 87 88

the coressponding board with the pieces is

- w - w - w - w
w - w - w - w -
- w - w - w - w
- - - - - - - -
- - - - - - - -
b - b - b - b -
- b - b - b - b
b - b - b - b -


say you want to move the the first white piece in the third row...
its possible moves are to move from the square

32 43
32 41

when you are asked to enter a move you can enter the line of move
in term of squares seperarted by a space just like above

say in case of a capture move for eg-

- w - w - w - w
w - w - w - w -
- w - w - w - w
- - b - - - - -
- - - - - - - -
b - b - b - b -
- b - b - - - b
b - b - b - b -

when the board state is something like this
the the white pawn at square 32 can make tow jumps and capture 2 pieces
or make a single move to the left

so the possible moves are

32 43 54 65 76
32 41

so as you see we have to enter the line of our move in terms of square

if u dont remember the squares you can always enter 0 in the enter move command
to print the grind of squares to analyze your move

or if you want to see the list of all your possible moves press 1 and enter

Enjoy!
