# 🎮 Game of Life

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/e/e5/Gospers_glider_gun.gif" alt="Game of Life" width="300"/>
</p>


## 📖 Introduction

The **Game of Life** is a cellular automaton designed by British mathematician **John Horton Conway** in 1970. Despite its name, it is not a game in the traditional sense: there are no players or decisions to make. It is a simulation that evolves automatically based on its initial state.

### 🧬 The Rules

The universe of the Game of Life is an infinite two-dimensional grid of cells, where each cell can be in one of two states: **alive** (O) or **dead** (.). Evolution is determined by these four simple rules:

| Rule                         | Description                                             |
| ---------------------------- | ------------------------------------------------------- |
| **Death by underpopulation** | A live cell with fewer than 2 live neighbors dies       |
| **Survival**                 | A live cell with 2 or 3 live neighbors survives         |
| **Death by overpopulation**  | A live cell with more than 3 live neighbors dies        |
| **Birth**                    | A dead cell with exactly 3 live neighbors becomes alive |

### 🌟 Why is it fascinating?

From these simple rules, complex behaviors emerge:

- **Still lifes**: Stable patterns that do not change (Block, Beehive)
- **Oscillators**: Patterns that repeat cyclically (Blinker, Pulsar)
- **Spaceships**: Patterns that move across the board (Glider, LWSS)
- **Methuselahs**: Small patterns that evolve for many generations before stabilizing (Acorn, R-pentomino)

---

## 🚀 Usage

### Compilation

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Execution

```bash
./gameoflife
```

> ⚠️ **Note**: The program does not accept arguments. Run with `./gameoflife` only.

---

## 📋 Menus

### 🏠 Main Menu

```
-------------Game of Life-------------
Enter one of the following options:
1. Select a pattern to run.
2. Draw a new pattern.
3. Change the speed of the simulation.
4. Exit.
>>>>> 
```

| Option | Description                       |
| ------ | --------------------------------- |
| 1      | Select a predefined pattern       |
| 2      | Draw a custom pattern *(pending)* |
| 3      | Change simulation speed           |
| 4      | Exit the program                  |

### 🎨 Presets Menu

```
-------------Game of Life-------------
Select one of the following presets:
1. Blinker.
2. Glider.
3. Acorn.
4. Complex pattern.
5. Back to main menu
>>>>> 
```

| Preset              | Description                                           |
| ------------------- | ----------------------------------------------------- |
| **Blinker**         | Simple period-2 oscillator (3 cells in a line)        |
| **Glider**          | Spaceship that moves diagonally                       |
| **Acorn**           | Pattern that evolves chaotically for many generations |
| **Complex pattern** | Line of cells that generates complex structures       |

### ⚙️ Simulation Menu

```
-------------Game of Life-------------
Choose an option:
1. Run simulation.
2. Change speed.
3. Set the number of iterations.
4. Back to main menu
>>>>> 
```

| Option | Description                                |
| ------ | ------------------------------------------ |
| 1      | Run the simulation with current parameters |
| 2      | Modify the simulation speed                |
| 3      | Set the number of iterations               |
| 4      | Return to main menu                        |

---

## ✅ Working Features

- [x] Game of Life simulation engine
- [x] Correct neighbor counting
- [x] Application of Conway's 4 rules
- [x] Terminal visualization with ASCII characters
- [x] Interactive main menu
- [x] Predefined pattern selection (Blinker, Glider, Acorn)
- [x] Simulation speed configuration
- [x] Number of iterations configuration
- [x] Drawing system with "pen" (wasd + x to toggle)

---

## 🔧 Pending Implementation

- [ ] **Custom drawing mode**: Allow the user to manually draw patterns using wasd keys to move and x to paint
- [ ] **More presets**: Add classic patterns like Pulsar, Gosper Glider Gun, LWSS
- [ ] **Pause/Resume**: Control simulation in real time
- [ ] **Statistics**: Show current generation, population, etc.

---

## 🎛️ Configuration

Board dimensions and default speed are defined in `includes/gol.h`:

```c
#define WIDTH  80   // Board width
#define HEIGHT 45   // Board height
#define SPEED  5    // Default speed
```

---

## 📁 Project Structure

```
gameoflife/
├── SRCS/
│   ├── gol.c        # Main and main menu
│   ├── helpers.c    # Simulation and drawing functions
│   └── presets.c    # Predefined patterns and preset menus
├── includes/
│   └── gol.h        # Header with definitions and prototypes
├── Makefile
└── README.md
```

---

## 👤 Author

**hgamiz-g** - [42 Málaga](https://www.42malaga.com/)

---

## 📚 References

- [Conway's Game of Life - Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
- [LifeWiki - Pattern Catalog](https://conwaylife.com/wiki/Main_Page)
- [Online Game of Life Simulator](https://copy.sh/life/)
