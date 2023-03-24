<div align="center">
<a><img height="120px" src="https://github.com/fesper-s/fesper-s/blob/main/src/42_badges/philosopherse.png"></a>

# Philosophers - 100% ✅
</div>

In this project, I learned the basics of threading a process. Creating threads and using mutexes.

## Usage
`make` and execution `./philo <number of philosophers> <time to die> <time to eat> <time to sleep> <(optional) number of times each philosopher must eat>
```sh
./philo 1 200 200 200          // Not have enough forks, so he dies
./philo 2 800 200 200          // Nobody dies
./philo 5 800 200 200          // Nobody dies
./philo 5 800 200 200 7        // Simulation stops when all philosophers eat 7 meals
./philo 4 410 200 200          // Nobody dies
./philo 4 310 200 200          // One philosopher dies
./philo 4 500 200 1.2          // Invalid arguments
./philo 4 0 200 200            // Invalid arguments
./philo 4 -500 200 200         // Invalid arguments
./philo 4 500 200 2147483647   // One philopher dies after 500ms
./philo 4 2147483647 200 200   // Nobody dies
./philo 4 214748364732 200 200 // Invalid arguments
./philo 4 200 210 200          // One philosopher dies, should show his dead before 210ms 
```
