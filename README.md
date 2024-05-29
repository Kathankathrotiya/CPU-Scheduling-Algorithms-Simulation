# CPU Scheduling Algorithms

## Project Overview

This project implements various CPU scheduling algorithms to manage processes in a simulated operating system environment. CPU scheduling is a critical task in operating systems, ensuring efficient execution of processes by deciding the order in which processes access the CPU. This project covers the following algorithms:

- First Come First Served (FCFS)
- Shortest Job First (SJF)
- Round Robin (RR)
- Shortest Remaining Time First (SRTF)
- Non-Preemptive Priority
- Preemptive Priority
- Longest Job First (LJF)
- Longest Remaining Time First (LRTF)

The project demonstrates how each algorithm handles process scheduling, with a focus on the algorithms' performance and efficiency.

## Algorithms Implemented

### 1. First Come First Served (FCFS)
- **Description**: Processes are scheduled in the order they arrive.
- **Characteristics**: Simple and fair, but can lead to the "convoy effect" where shorter processes wait for long processes to complete.

### 2. Shortest Job First (SJF)
- **Description**: Processes with the shortest burst time are scheduled first.
- **Characteristics**: Optimal in terms of minimizing average waiting time, but requires precise knowledge of burst times.

### 3. Round Robin (RR)
- **Description**: Each process is assigned a fixed time slice (quantum) in a cyclic order.
- **Characteristics**: Ensures fairness and responsiveness, suitable for time-sharing systems.

### 4. Shortest Remaining Time First (SRTF)
- **Description**: Preemptive version of SJF where the process with the shortest remaining time is scheduled next.
- **Characteristics**: Can lead to high overhead due to frequent context switching.

### 5. Non-Preemptive Priority
- **Description**: Processes are scheduled based on priority, with higher priority processes executed first.
- **Characteristics**: Simple to implement but can lead to starvation of low-priority processes.

### 6. Preemptive Priority
- **Description**: Similar to Non-Preemptive Priority but allows preemption if a higher priority process arrives.
- **Characteristics**: Reduces waiting time for high-priority processes, but increases complexity.

### 7. Longest Job First (LJF)
- **Description**: Processes with the longest burst time are scheduled first.
- **Characteristics**: Can lead to poor average waiting time, not commonly used in practice.

### 8. Longest Remaining Time First (LRTF)
- **Description**: Preemptive version of LJF where the process with the longest remaining time is scheduled next.
- **Characteristics**: Similar issues to LJF, with additional overhead due to preemption.

## ScreenShots:
![Screenshot 1](https://github.com/Kathankathrotiya/CPU-Scheduling-Algorithms-Simulation/blob/main/Screenshot%202024-05-29%20121009.png)
