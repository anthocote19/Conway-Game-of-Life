# Game of Life - Cellular Automaton (C)

## Description
**The Game of Life** is a cellular automaton created by British mathematician John Conway. It is a zero-player game where the evolution of the game is determined by its initial state. The world is represented by a rectangular grid where each cell can be:

- Alive (`+`)
- Dead (`-`)
- Newborn (`0`)

Each cell interacts with its eight neighbors (horizontally, vertically, and diagonally). Each generation, the cells evolve according to the following rules:
- Any live cell with fewer than two live neighbors dies (underpopulation).
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies (overpopulation).
- Any dead cell with exactly three live neighbors becomes alive (reproduction).

## Features
- **Grid Representation**: A rectangular grid where each cell can be alive (`+`), dead (`-`), or newborn (`0`).
- **Random Initialization**: Each cell has a probability `p` (between 0 and 1) of being alive at the start.
- **Neighbor Interaction**: Each cell interacts with its eight neighbors (horizontally, vertically, and diagonally).
- **Automatic Generation**: After each step, the grid is updated according to the rules. The game ends when the grid no longer changes between generations.

## Technologies Used
- **C Language**: The game is developed using the C language for its simplicity and memory management efficiency.
- **Structures**: Structures are used to represent the grid and cells.

## Installation and Execution

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/Game-of-Life.git


# Example of Grid Evolution
# Initial Grid (for p = 0.3):

- - + - - - - - -
+ - - - + - - - -
- + - + - - - + -
- - - + - - + - -
+ - - + - - - - -
# After One Generation:

- - - - + - - + -
+ - + - - + + - -
- + - - + - - - -
- - - - - + - - -
+ - - - + - + - -
# After Two Generations:

+ - - + - - + - -
- + - - + - - - -
+ - - - + - + - -
- - - - - - - - -
+ + - - + - - + -
