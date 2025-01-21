You will implement a cellular automaton modeling the Game of Life.

The world will be represented by a rectangular grid, where each cell can either be:
Alive
Dead

We give a proportion p between 0 and 1; initially each cell is, with probability p alive, and with probability 1-p dead.

Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent.

At each step in time, the following transitions occur:
Any alive cell with fewer than two alive neighbors dies, as if by underpopulation.
Any alive cell with two or three alive neighbors lives on to the next generation.
Any alive cell with more than three alive neighbors dies, as if by overpopulation.
Any dead cell with exactly three alive neighbors becomes an alive cell, as if by reproduction.

You will define the world with the help of structures.
Between each generation, you should automatically know if it is necessary to make the next generation or to quit the game.
To represent a cell, you must use the following symbols:
"+": alive
"-": dead
"0": newborn (is considered as an alive state, and will be applied one of the 2 other states at the next generation)
