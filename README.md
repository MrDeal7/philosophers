# Philosophers

A C implementation of the classic **Dining Philosophers** concurrency problem, completed as part of the [42 School](https://42.fr) curriculum.

## The Problem

Several philosophers sit around a round table. There is a fork between each pair of adjacent philosophers. Philosophers alternate between three states:

- **Eating** — requires picking up both the left and right fork
- **Sleeping** — resting after a meal
- **Thinking** — waiting for forks to become available

A philosopher dies if they go too long without eating. The simulation ends when a philosopher dies, or when every philosopher has eaten a required number of times.

## Features

- Each philosopher runs as an independent **thread** (`pthread`)
- Forks are protected by **mutexes** to prevent race conditions
- Even/odd philosopher ordering avoids **deadlock**
- A dedicated **monitor** (death_god) continuously checks whether any philosopher has starved
- Thinking time is calculated automatically to keep even-numbered tables in sync

## Build

```bash
make
```

This produces the `philo` binary. To clean up:

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full rebuild
```

## Usage

```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers (and forks) at the table |
| `time_to_die` | Time (ms) a philosopher can go without eating before dying |
| `time_to_eat` | Time (ms) it takes a philosopher to eat |
| `time_to_sleep` | Time (ms) a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(optional)* Simulation stops once every philosopher has eaten this many times |

All time values are in **milliseconds**.

### Examples

```bash
# 5 philosophers, die after 800ms without food, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same, but stop once everyone has eaten at least 7 times
./philo 5 800 200 200 7

# Edge case: a lone philosopher who can never eat (only one fork)
./philo 1 800 200 200
```

## Output

Each event is printed in the following format:

```
timestamp_in_ms philosopher_id action
```

Possible actions:
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

No message is printed after a philosopher has died.

## Project Structure

```
.
├── Makefile
└── src/
    ├── philosophers.h   # structs and prototypes
    ├── philosophers.c   # entry point, thread creation, fork assignment
    ├── actions.c        # eat / sleep / think routines
    ├── parsing.c        # argument parsing (ft_atoi, prepare_args)
    ├── utils.c          # fork locking, death monitor
    ├── utils2.c         # time helpers, cleanup, meal tracking
    └── ft_printf.*      # lightweight printf implementation
```

## Author

**divalent** — [42 School](https://42.fr)
