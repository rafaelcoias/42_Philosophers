# 42_Philosophers

## Assigment

Create a program that solves the famous Philosophers problem. 

## Skills Learned

  - Imperative programming
  - Rigor
  - Unix
  - Threads
  - Mutexes

## Goal

In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

## Rules

  - One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.
  - The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
  - There are also forks on the table. There are as many forks as philosophers.
  - Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
  - When a philosopher has finished eating, they put thttps://man7.org/linux/man-pages/man3/usleep.3.htmlheir forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
  - Every philosopher needs to eat and should never starve.
  - Philosophers don’t speak with each other.
  - Philosophers don’t know if another philosopher is about to die.
  - Each philosopher should be a thread.
  - There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
  - To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.
  - Philosophers should avoid dying!
  
## What you need to know before starting philosophers

### Functions Manual

  - <a href="https://man7.org/linux/man-pages/man3/usleep.3.html">usleep()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/settimeofday.2.html">gettimeofday()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_create.3p.html">pthread_create()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_detach.3p.html">pthread_detach()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_join.3p.html">pthread_join()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html">pthread_mutex_init()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html">pthread_mutex_destroy()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html">pthread_mutex_lock()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_unlock.3p.html">pthread_mutex_unlock()</a> 

### Threads

Because each philosopher is a thread we need to understand what a thread is.

A thread is a path of execution within a process. A process can contain multiple threads.

In the philo program there can be a lot of threads. That means each philosopher(thread) is executing within a main thread. Every philo is eating, sleeping or thinking at the same time.

This <a href="https://www.youtube.com/watch?v=d9s_d28yJq0&t=287s">video</a> explains how to use threads in your C program.

<details><summary>Example</summary>
  
  ![image](https://user-images.githubusercontent.com/91686183/190930361-324d337c-5960-4ea3-973a-1315be931b0f.png)

</details>

### Mutexes

Because each philosopher must eat using his and other philosopher's fork, there can be an issue when two philosophers try the same fork at the same time 

A mutex is a programming concept that is frequently used to solve multi-threading problems.

Is used when there is any chance of two threads accessing the same process data at the same time. For example, if a thread is changing a variable value when other thread is reading it.

This <a href="https://www.youtube.com/watch?v=oq29KUy29iQ&t=306s">video</a> explains how to use mutexes in your C program.

<details><summary>Example</summary>
  
  ![image](https://user-images.githubusercontent.com/91686183/190930661-b8c051ca-4cce-488b-8295-fc9886a9f872.png)
  
</details>

## Preview

<details><summary>My Philo</summary>
  
  ![Screencast from 18-09-2022 23_52_58](https://user-images.githubusercontent.com/91686183/190931695-93215ce2-81a3-4132-b0b8-c41b25ccfe93.gif)
  
</details>

<details><summary>My grade</summary>
  
  ![image](https://user-images.githubusercontent.com/91686183/169927289-9e8dcfa1-7789-4b1d-a6fb-b9d1b8f90dce.png)
  
</details>

<hr>

I hope you found it interesting!

If you are going to do philosophers, I wish you good luck and hope that you learned something here!
