## This is a very famous programming challenge called *GameOfLife*. 
 By the help of this project we can make programs which are turing complete . As we can see here, in our program it starts with the entropy and follows up till the still life state . It is capable of attaining complexicity from 0 to infinity or vice versa .

## The Four Rules of Conway’s Game of Life

These rules are applied to every cell in the grid for the next generation:

1. **Underpopulation**  
   Any live cell with fewer than two live neighbors dies.

2. **Survival**  
   Any live cell with two or three live neighbors lives on to the next generation.

3. **Overpopulation**  
   Any live cell with more than three live neighbors dies.

4. **Reproduction**  
   Any dead cell with exactly three live neighbors becomes a live cell.


   ## 🧩 Setup (No CMake required)

1️⃣ Clone this repo  
```bash
git clone https://github.com/<your-username>/GameOfLife.git
cd GameOfLife

setup_sfml.bat
