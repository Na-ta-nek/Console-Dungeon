# Console-Dungeon

## Project Description
**Console-Dungeon** is a text-based RPG console game designed to run in the Linux terminal. The player navigates dungeons, defeats monsters, and discovers items in chests to help them on their journey. Use the power of strategy and the items you find to conquer the dungeons and emerge victorious!

## Installation

To set up and run the project, `gtest` and `gmock` is required.

### Steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/Na-ta-nek/Console-Dungeon.git
   ```

2. Navigate into the project directory:
   ```bash
   cd Console-Dungeon
   ```

3. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

4. Configure the project with CMake:
   ```bash
   cmake ..
   ```

5. Build and run the game:
   ```bash
   ./Console-Dungeon
   ```

## Running Tests

To run unit tests for **Console-Dungeon**, use one of the following commands from the `build` directory:

- Run the unit tests directly:
  ```bash
  ./Console-Dungeon-ut
  ```

- Or, run tests using `ctest`:
  ```bash
  ctest
  ```

## Game Content

- **Monsters**: 9 unique monsters await you in the dungeons.
- **Items**: Find 9 different items to aid you in battle and exploration.

Good luck conquering the dungeons and defeating all the monsters!
