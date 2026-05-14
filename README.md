# Philosophers Dining Problem

*This project has been created as part of the 42 curriculum by mosakura*

## Description

This project implements a solution to the classic **Dining Philosophers Problem**, a fundamental concurrency challenge in computer science. The problem demonstrates how to properly manage shared resources and synchronize multiple threads to prevent deadlocks and race conditions.

### Problem Overview

In this scenario, multiple philosophers sit around a circular table with a bowl of rice in the center and one fork placed between each pair of adjacent philosophers. Each philosopher needs to:
1. **Think** for a certain amount of time
2. **Eat** when they have access to two forks (one on each side)
3. **Sleep** after eating

The goal is to simulate this scenario using multithreading while ensuring no philosopher starves (i.e., no deadlock occurs) and proper synchronization of shared resources (the forks).

### Learning Objectives

- Understanding concurrent programming with POSIX threads (`pthread`)
- Implementing mutex locks to protect shared resources
- Avoiding deadlocks through proper synchronization strategies
- Managing thread lifecycle and process timing
- Working with system time functions for accurate event simulation

## Instructions

### Compilation

To compile the project, navigate to the project directory and run:

```bash
cd philo
make
```

This will generate an executable named `philosopher`.

### Execution

Run the program with the following syntax:

```bash
./philosopher <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

**Arguments:**
- `time_to_die` — Time in milliseconds after which a philosopher dies if they haven't eaten
- `time_to_eat` — Time in milliseconds it takes a philosopher to eat
- `time_to_sleep` — Time in milliseconds a philosopher sleeps after eating
- `number_of_times_each_philosopher_must_eat` (optional) — If specified, the simulation ends once all philosophers have eaten this many times

**Example:**

```bash
./philosopher 800 200 200 5
```

This creates a simulation where:
- Each philosopher dies if they don't eat within 800ms
- Each meal takes 200ms
- Each philosopher sleeps for 200ms after eating
- The simulation ends once each philosopher has eaten 5 times

### Cleaning Up

To remove all compiled files and objects:

```bash
make clean
```

To remove all compiled files and the executable:

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

## Implementation Details

The solution uses the following synchronization mechanisms:

- **Mutexes**: Protects the forks (shared resources) from simultaneous access
- **Threads**: Each philosopher runs in its own thread for concurrent execution
- **System Time**: Uses `gettimeofday()` to track elapsed time and manage simulation events

## Resources

### Documentation
- [POSIX Threads Documentation](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/pthread.h.html)
- [pthread_mutex Tutorial](https://www.man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html)
- [The Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [42 School Curriculum Documentation](https://42.fr)

### Related Articles
- [Concurrency Control Mechanisms](https://en.wikipedia.org/wiki/Concurrency_control)
- [Deadlock Detection and Prevention](https://en.wikipedia.org/wiki/Deadlock)
- [Thread Synchronization Techniques](https://en.wikipedia.org/wiki/Synchronization_(computer_science))

### AI Usage

AI (Copilot) was used for the README.
