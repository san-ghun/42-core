# philosophers

### Summary

- Keywords: `UNIX` `thread` `mutex` `multithreading` `race condition` `dead lock` `data integrity` `semaphore` `pthread`

1. Objective

   - coding a program that handle multithreading using mutexes and semaphores.

2. Instructions

   - **Program name**: `philo` & `philo_bonus`
   - **Turn in files**: Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c, in directory philo/ & philo_bonus/
   - **Makefile**: NAME, all, clean, fclean, re
   - **Arguments**: `number_of_philosophers`, `time_to_die`, `time_to_eat`, `time_to_sleep`, `[number_of_times_each_philosopher_must_eat]`
   - **External functions**:
     `memset`, `printf`, `write`, `malloc`, `free`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`,
     - mandatory:
       `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
     - bonus:
       `fork`, `kill`, `exit`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
   - **Libft authorized**: NO
   - **Global rules**:

     - Solve an advanced version of the **Dining Philosophers** problem.
     - Global variables are forbidden.
     - Arguments are the following,
       - `number_of_philosophers`: The number of philosophers and also the number of forks.
       - `time_to_die` (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
       - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
       - `time_to_sleep` (in milliseconds): The time a philosopher will spend sleeping.
       - `number_of_times_each_philosopher_must_eat` (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
     - Each philosopher has a number ranging from 1 to `number_of_philosophers`.
     - Philosopher number 1 sits next to philosopher number `number_of_philosophers`. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

     About the logs of your program:

     - Any state change of a philosopher must be formatted as follows:
       - `timestamp_in_ms` X has taken a fork
       - `timestamp_in_ms` X is eating
       - `timestamp_in_ms` X is sleeping
       - `timestamp_in_ms` X is thinking
       - `timestamp_in_ms` X died
         _Replace `timestamp_in_ms` with the current timestamp in milliseconds and X with the philosopher number._
     - A displayed state message should not be mixed up with another message.
     - A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
     - Again, philosophers should avoid dying!

     > ℹ️ Your program must not have any data races.

3. Requirements

   - **Mandatory**:

     - Each philosopher should be a thread.
     - There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
     - To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

   - **Bonus**:

     - All the forks are put in the middle of the table.
     - They have no states in memory but the number of available forks is represented by a semaphore.
     - Each philosopher should be a process. But the main process should not be a philosopher.

---

**references)**

- [CS 110 Lecture 9 - Introduction to Threads - YouTube](https://youtu.be/bw68rvYNG8k?t=3071)
