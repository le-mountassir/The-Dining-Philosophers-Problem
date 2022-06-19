# The-Dining-Philosophers-Problem

-The Dining Philosopher Problem states that N philosophers seated around a circular table with one chopstick between each pair of philosophers. 
There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him. 
One chopstick may be picked up by any one of its adjacent followers but not both.

## Semaphore Solution to Dining Philosopher – Problem

-There are three states of the philosopher: THINKING, HUNGRY, and EATING. Here there are two semaphores: 
Mutex and a semaphore array for the philosophers. Mutex is used such that no two philosophers may access the pickup or putdown at the same time. 
The array is used to control the behavior of each philosopher. 
But, semaphores can result in deadlock due to programming errors.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/dining_philosopher_problem.png">
