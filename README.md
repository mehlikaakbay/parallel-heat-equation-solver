# Parallel Heat Equation Solver – C++ & OpenMP


## Overview

This project implements a **1D Heat Equation Solver** using the **finite difference method**, coded in **C++** with **OpenMP** for parallelization.

We developed both a serial and a parallel version of the algorithm to demonstrate performance improvement through multithreading. The simulation models how heat spreads through a rod over time.

---

## Key Features

- Solves 1D heat equation using finite difference discretization  
- Parallel implementation using `#pragma omp parallel for`  
- Boundary conditions handled appropriately  
- Runtime comparison between serial and parallel versions  
- Vectorized memory management with `std::vector<double>`  
- Uses OpenMP, chrono, cmath, and vector libraries

---

## Technologies Used

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![OpenMP](https://img.shields.io/badge/OpenMP-Parallel-yellow)
![VS Code](https://img.shields.io/badge/IDE-VSCode-blue)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)

- Language: C++17  
- Parallelization: OpenMP  
- Timing: `std::chrono`  
- Compilation: g++ with `-fopenmp` flag

---

## How to Compile & Run

### Compile:
```bash
g++ -fopenmp -O2 -o heat_solver main.cpp threads.cpp
```
### Run:
```bash
./heat_solver
```

---

## Performance Example
### Tested with:
- N = 1,000,000 points  
- Steps = 20,000  
- Threads = 20

Output:
Serial Time:   286.674 seconds  
Parallel Time: 279.3 seconds

Performance may vary depending on system specs and CPU thread count.

---

## Project Files

- [src/](./src/) – C++ source code files  
- [report/](./report/) – Documentation and performance report  


### Download Binary

You can download the compiled `.out` file from the [latest release]([https://github.com/mehlikaakbay/heat-equation-solver/releases/latest](https://github.com/mehlikaakbay/parallel-heat-equation-solver/releases/tag/v1.0.1)) and run it on macOS/Linux:

```bash
./heat_solver.out
```
---

Mehlika Rana Akbay
BSc. Software Engineering – UE Germany
