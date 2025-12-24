# OS Scheduler Simulator (C++)

A CLI-based Operating System simulator implementing multiple CPU scheduling
algorithms with text-based Gantt chart visualization.

## Features
- FCFS Scheduling
- SJF (Non-Preemptive)
- Round Robin (Preemptive)
- Waiting Time & Turnaround Time calculation
- Text-based Gantt Chart
- Modular OOP design

## Technologies
- C++
- STL (vector, queue)
- Object-Oriented Programming

## How to Run
```bash
g++ src/*.cpp src/algorithms/*.cpp -o os_sim
./os_sim
