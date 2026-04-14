# C & C++ Projects Collection

A repository showcasing various low-level programming, systems engineering, and algorithmic projects implemented in C and C++. These projects cover topics ranging from file systems and concurrency to mathematical optimizations and game logic.

## 🚀 Projects Overview

### 📂 [FAT12 File System](https://github.com/hilalsaygin/C-_Projects/tree/main/FAT12)
A low-level implementation of the FAT12 file system. This project demonstrates an understanding of disk structures, boot sectors, File Allocation Tables, and directory management.

### 🧵 [Concurrent File Access System](https://github.com/hilalsaygin/C-_Projects/tree/main/Concurrent%20File%20Access%20System)
A system designed to handle multiple processes or threads accessing files simultaneously. It focuses on synchronization primitives (mutexes, semaphores) to ensure data integrity and prevent race conditions.

### 📦 [Multithreaded Delivery System](https://github.com/hilalsaygin/C-_Projects/tree/main/multithreaded%20delivery%20system)
A simulation of a delivery logistics system using multithreading. It manages concurrent tasks and resource allocation to optimize delivery paths and timing.

### 🔢 [SparseMatrix Operations](https://github.com/hilalsaygin/C-_Projects/tree/main/SparseMatrix%20Operations)
Highly efficient operations for Sparse Matrices. This project focuses on memory optimization and performance, storing only non-zero elements to handle large-scale computations that are common in scientific engineering.

### 🎮 [Wordle Game with Numbers](https://github.com/hilalsaygin/C-_Projects/tree/main/WordleGame_with_numbers)
A logic-based CLI game inspired by Wordle, but using numerical sequences. It features custom validation logic and feedback loops for the player.

## 🛠️ Built With

- **C**: Used for low-level system implementations (FAT12, Concurrency).
- **C++**: Used for object-oriented logic and algorithmic optimizations.
- **Makefile**: Streamlined compilation and build management.

## 🔧 Getting Started

### Prerequisites
- GCC/G++ Compiler
- Make (optional, for projects with Makefiles)

### Compilation
Navigate to a specific project directory and compile the source files. For example:
```bash
cd "SparseMatrix Operations"
g++ main.cpp SparseMatrix.cpp -o sparse_op
./sparse_op
