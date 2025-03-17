# 🕹️ **so_long: A 2D Game Project**

**so_long** is a small 2D game created using the **MiniLibX Graphics Library**. It's the fifth project in the 42 programming school's curriculum. This game was developed from scratch and focuses on the core concepts of graphical programming.

---

## 🎮 **What is so_long?**

The **so_long** project is designed to help you understand the fundamentals of graphical programming. It's a top-down game where you must navigate through a map, collect coins, and escape through the exit. This project introduces working with graphics, map validation, event handling, sprites, and managing windows.

The game is built using the **MiniLibX** graphical library, and it comes with various tasks such as:

- Validating game maps passed as arguments.
- Ensuring no memory leaks.
- Implementing game mechanics and designing the gameplay.
- Managing windows and handling events.
- Working with textures, sprites, and tiles.

---

## 📌 **Project Requirements:**

The project must be written according to the **Norm**, the strict coding standard at 42. These are some of the key rules to follow:

- Each function must be **maximum 25 lines**, not counting curly brackets.
- Each line should not exceed **80 columns** in length (comments included).
- A function can take a maximum of **4 named parameters**.
- You can't declare more than **5 variables per function**.
- **Forbidden constructs**:
  - `for`, `do...while`, `switch`, `case`, `goto`, ternary operators (`?`), and **Variable Length Arrays** (VLAs).

---

## 🗺️ **Maps:**

You can use any map file, as long as it adheres to the following rules:

- The map must be in a **.ber** file format.
- Valid characters in the map:
  - **1** - Wall
  - **C** - Coin
  - **E** - Exit
  - **P** - Player's starting position
  - **0** - Floor
  - **A** - Enemy

---

## 🎮 **Game Controls:**

- **W** ➡️ Move Up
- **A** ➡️ Move Left
- **S** ➡️ Move Down
- **D** ➡️ Move Right
- **Esc** ➡️ Close the game

The goal of the game is to collect all the coins, which will unlock the exit. Once all coins are collected, you can escape through the exit door to complete the level.

---

## 🚀 **Setup & Running the Game**

### **Installation:**

1. First, install the required dependencies for MiniLibX:
   ```bash
   sudo apt-get update
   sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
   ```

2. Clone and setup MiniLibX:
   ```bash
   git clone https://github.com/42Paris/minilibx-linux.git
   cd minilibx-linux
   make
   sudo cp mlx.h /usr/local/include
   sudo cp libmlx.a /usr/local/lib
   cd ..
   ```

3. Clone this repository:
   ```bash
   git clone <repo-url>
   cd so_long
   ```

4. Compile the project:
   ```bash
   make
   ```

5. Run the game with a map:
   ```bash
   ./so_long maps/maps_1.ber
   ```

### **Troubleshooting:**
If you encounter any issues with MiniLibX:
- Make sure all dependencies are properly installed
- For MacOS users, you might need to install XQuartz
- Check if the MiniLibX library is properly linked in the Makefile

## 📂 **Project Structure**

```
so_long/
│
├── Makefile             # Compilation instructions
├── README.md            # Project documentation
├── include/             # Header files
├── srcs/                # Source code
├── maps/                # Map files
└── wrong_maps/          # Invalid map files
```

## 📅 **Project Milestones**

- **Completion Date:** 2024-11-13
- **Grade:** 125/100

## 📜 **License**

This project is licensed under the terms of the 42 License. More details can be found on the 42 website.

## 🔗 **Additional Resources**

- [MiniLibX GitHub Repository](https://github.com/42Paris/minilibx-linux)
- [42 School](https://42.fr/en/homepage/)
