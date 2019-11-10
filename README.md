# UPDATING XV6
## TASK1 -> waitx() system call

1. Add a system call to update the existing system call wait().
2. The call takes two integer arguments by reference.
3. The wtime stands for waiting time.
4. The rtime stands for running time.
5. The system call initialises ctime, rtime ,etime  in the proc structure.
6. These variables are updated at appropriate places.
7. wait time is calculated at the end using ctime and rtime as wtime = etime -
   ctime - rtime.

## TASK2 -> getpinfo() system call

1. Add a system call to give information about the processes.
2. Create a new struct to represent the information.
3. Information includes pid, runtime, num_run, ticks, current_queue.
4. The call return a struct filled with information of the process which called
   this command.
5. It helps in giving critical info about the process.

## TASK3 -> FCFS scheduling policy

1. The task is to implement a FCFS policy in the scheduler.
2. We use the creation time of the processes which we defined above in the proc
   struct.
3. using ctime , we find the process with lowest ctime , and schedule it.
4. This policy suffers from convoy effect.

## TASK4 -> PRIORITY Based scheduling policy
1. The task is to implement a Priority based scheduling.
2. The scheduler checks the process which is runnable and has the highest
   priority among all the available processes.
3. Then it schedules such a process.
4. This policys favours the process with the highest priority and as a result if
   some user keeps pushing higher priority process than a low priority process
   may suffer from starvation.

## TASK5 -> MLFQ scheduling policy
1. The task is to implement 5 queues with different priorities.
2. The processes in the highest priority queue run first.
3. If there are no processes in higher priority queue only than a processe from
   lower queue will be run.
4. To avoid starvation we can use aging which will push the processes in a
   higher priority queue after a certain waiting time.
5. There is a limit on wait time in each queue.
6. After the wait time is reached then the process is pushed to a higher
   priority queue.

## TIMING COMPARISONS OF VARIOUS POLICIES
1. The FCFS policy takes 17.22 for running.  
2. The RR policy takes 15.61 seconds for running
3. The PBS policy takes  19.51 seconds for running
4. The MLFQ policy takes 18.83 seconds for running
