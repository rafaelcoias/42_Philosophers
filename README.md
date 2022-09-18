# 42_Philosophers

## Assigment

Create a program that solves the famous Philosophers problem. 

## Goal

In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

## Rules

  - One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
  - The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
  - There are also forks on the table. There are as many forks as philosophers.
  - Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
  - When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
  - Every philosopher needs to eat and should never starve.
  - Philosophers don’t speak with each other.
  - Philosophers don’t know if another philosopher is about to die.
  - Each philosopher should be a thread.
  - There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
  - To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.
  - Philosophers should avoid dying!
  
## What you need to know before starting philosophers

### Functions Manual

  - <a href="https://man7.org/linux/man-pages/man2/usleep.2.html">usleep()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/gettimeofday.2.html">gettimeofday()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/pthread_create.3p.html">pthread_create()</a>
  - <a href="https://man7.org/linux/man-pages/man2/pthread_mutex_init.3p.html">pthread_mutex_init()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/pipe.2.html">pipe</a> 
  - <a href="https://man7.org/linux/man-pages/man2/unlink.2.html">unlink()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/wait.2.html">wait()</a>
  - <a href="https://man7.org/linux/man-pages/man2/waitpid.2.html">waitpid()</a> 
