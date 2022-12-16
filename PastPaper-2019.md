# Past Paper 2019

## Question 1

Yes, FreeRTOS is a popular real-time operating system (RTOS) kernel that is designed to be small and easy to use. It is designed to run on a wide variety of microcontroller and microprocessors, including those with limited resources.

FreeRTOS supports both cooperative and preemptive multitasking, which allows developers to choose the type of multitasking that best fits the needs of their application. Cooperative multitasking involves tasks voluntarily giving up control of the CPU, while preemptive multitasking involves the RTOS kernel interrupting a task to give control to a higher priority task.

FreeRTOS also supports mutexes and semaphores, which are synchronization mechanisms that allow tasks to coordinate their access to shared resources. Mutexes are used to protect shared resources from concurrent access, while semaphores are used to signal the availability of resources or to signal the completion of tasks.

Overall, FreeRTOS is a widely used RTOS kernel that offers a range of features and flexibility for developing real-time systems.

### Q1 Part A

An RTOS (real-time operating system) is not necessarily required to implement a real-time embedded system because a real-time embedded system can be implemented using a "bare metal" approach, which means that the system runs directly on the hardware without an operating system.

There are two key characteristics of a real-time embedded system that can influence whether or not an RTOS is required:

1. Timing requirements: If the system has strict timing requirements and needs to respond to events within a certain time frame, then an RTOS may be necessary to ensure that the system can meet those timing requirements. An RTOS can provide features like preemptive multitasking and real-time scheduling to ensure that tasks are executed in a timely manner.

1. Resource management: If the system has limited resources, such as memory or processing power, and multiple tasks need to share those resources, then an RTOS can help manage those resources by providing synchronization mechanisms like mutexes and semaphores.

Overall, whether or not an RTOS is required for a real-time embedded system depends on the specific requirements and constraints of the system.

### Q1 Part B

Task scheduling in the FreeRTOS kernel refers to the process of deciding which task should be executed next by the CPU. FreeRTOS uses a priority-based scheduling algorithm, which means that tasks are assigned a priority level and the RTOS kernel always executes the highest priority task that is ready to run.

Context switching, on the other hand, refers to the process of saving the state of a task when it is interrupted and restoring the state of a different task when it is resumed. This is necessary because a task may be interrupted at any point in its execution, and the RTOS kernel needs to be able to resume the task from the same point when it is scheduled to run again.

In FreeRTOS, the context switching function is responsible for saving the state of the current task, including the values of registers and the stack pointer, and restoring the state of the next task that is scheduled to run. This allows the RTOS kernel to seamlessly switch between tasks, even if they are at different points in their execution.

Overall, task scheduling and context switching are two important functions of the FreeRTOS kernel that work together to enable multitasking and real-time scheduling in a system. Task scheduling determines which task should run next, while context switching allows the RTOS kernel to switch between tasks smoothly and efficiently.

### Q1 Part C

There are several steps that can be taken using FreeRTOS to eliminate or reduce the undesirable side-effects of a task that is taking too long to execute:

1. Increase the task's priority: If the task is taking too long to execute because it is being interrupted by lower priority tasks, you can try increasing the priority of the task. This will allow the task to run for longer periods of time without being interrupted by lower priority tasks.

1. Use a mutex or semaphore to protect shared resources: If the task is taking too long to execute because it is waiting for access to a shared resource, you can use a mutex or semaphore to protect the resource. This will allow the task to execute faster by ensuring that it has exclusive access to the resource.

1. Divide the task into smaller tasks: If the task is taking too long to execute because it is doing too much work, you can try dividing the task into smaller tasks that can be executed concurrently. This will allow the task to be executed more efficiently by allowing other tasks to run in parallel.

1. Use a timer to break up the task into smaller chunks: If the task is taking too long to execute because it is doing a lot of work in one go, you can use a timer to break up the task into smaller chunks that can be executed in sequence. This will allow the task to run for shorter periods of time and allow other tasks to run in between.

Overall, there are several steps that can be taken using FreeRTOS to eliminate or reduce the undesirable side-effects of a task that is taking too long to execute. By adjusting the task's priority, using synchronization mechanisms, dividing the task into smaller tasks, or using a timer to break up the task into smaller chunks, you can improve the performance and efficiency of the system.

### Q1 Part D

In the FreeRTOS kernel, priority inheritance is a mechanism that is used to avoid priority inversion, which is a situation where a high-priority task is blocked by a low-priority task because the low-priority task holds a mutex or semaphore that the high-priority task needs.

To implement priority inheritance, the FreeRTOS kernel maintains a priority inheritance table that stores the priority of each task that holds a mutex or semaphore. When a task attempts to acquire a mutex or semaphore that is already held by another task, the FreeRTOS kernel checks the priority of the task that holds the mutex or semaphore and compares it to the priority of the task that is trying to acquire the mutex or semaphore.

If the task that holds the mutex or semaphore has a lower priority than the task that is trying to acquire the mutex or semaphore, the FreeRTOS kernel temporarily boosts the priority of the task that holds the mutex or semaphore to the same level as the task that is trying to acquire it. This ensures that the high-priority task is not blocked by the low-priority task, and it can continue to run without being interrupted.

Once the task that is trying to acquire the mutex or semaphore has finished and releases the mutex or semaphore, the priority of the task that holds the mutex or semaphore is restored to its original value.

Overall, priority inheritance is an important mechanism in the FreeRTOS kernel that helps to prevent priority inversion and ensures that high-priority tasks are able to execute without being blocked by low-priority tasks.

### Q1 Part E

There are several mechanisms for implementing an aperiodic task using FreeRTOS such that the interference with periodic tasks is bounded:

1. Priority inheritance: One mechanism for implementing an aperiodic task is to use priority inheritance to ensure that the aperiodic task does not interfere with periodic tasks. When an aperiodic task acquires a mutex or semaphore that is held by a periodic task, the FreeRTOS kernel temporarily boosts the priority of the periodic task to the same level as the aperiodic task. This ensures that the periodic task is not blocked by the aperiodic task and can continue to run without interference.

1. Rate-monotonic scheduling: Another mechanism for implementing an aperiodic task is to use rate-monotonic scheduling, which is a real-time scheduling algorithm that assigns fixed priorities to tasks based on their period. By assigning higher priorities to tasks with shorter periods, rate-monotonic scheduling ensures that periodic tasks are given higher priority and are able to execute without interference from aperiodic tasks.

Overall, there are several mechanisms that can be used to implement an aperiodic task using FreeRTOS such that the interference with periodic tasks is bounded. By using priority inheritance or rate-monotonic scheduling, you can ensure that periodic tasks are given the necessary resources and are able to execute without interference from aperiodic tasks.

## Question 2

To implement this temperature monitor, you can follow these steps:

1. Connect the temperature sensors to the PIC18 microcontroller using the appropriate input pins. You may need to use external voltage dividers or other circuitry to ensure that the sensor output is within the acceptable range for the ADC.

1. Configure the ADC to use the interrupt-driven foreground task to read the temperature sensor values. Set the ADC to use the internal voltage reference and a conversion clock rate that is appropriate for your requirements.

1. Set up the main background task to update the LCD display with the current temperature readings. You may need to use a buffer to store the readings as they are taken by the ADC, and then transfer them to the LCD display in the background task.

1. Implement a system to store the temperature readings over the 24 hour period. This can be done using an array or other data structure that is large enough to hold all of the readings. You will need to write a function that stores each new reading in the appropriate location in the array and updates the minimum, maximum, and most recent readings as needed.

1. Implement the alert feature that displays a message on the LCD if the temperature rises above 4 degrees Celsius for more than 15 minutes. This can be done by using a counter that is incremented each time the temperature exceeds 4 degrees Celsius, and reset to zero when the temperature falls below this threshold. If the counter exceeds a certain value (e.g. 15 minutes worth of readings), then the alert message can be displayed on the LCD.

1. Test the system thoroughly to ensure that it is functioning correctly and meeting the required specifications. This may involve verifying the accuracy and resolution of the temperature readings, as well as testing the alert feature and the ability to store and display the minimum, maximum, and most recent readings.

### Q2 Part A

One appropriate representation scheme for storing temperature readings in the described system would be to use fixed-point notation. In this scheme, a fixed number of bits are used to represent the integer part of the temperature value, and a fixed number of bits are used to represent the fractional part. For example, you could use 8 bits to represent the integer part and 8 bits to represent the fractional part, resulting in a total of 16 bits per temperature reading.

Using this representation scheme, the temperature readings 3.9 degrees Celsius and 18.5 degrees Celsius could be stored as follows:

- 3.9 degrees Celsius: 0011.1001 (binary)
- 18.5 degrees Celsius: 0100.0110 (binary)

This representation scheme meets the system requirements because it allows for a resolution of 0.1 degree Celsius, as specified, and provides a sufficient range of values to cover the full temperature range from 0 to 19.9 degrees Celsius. It also allows for easy comparison of temperature readings by simply comparing the binary values, which can be done quickly using bitwise operators.

Another advantage of this representation scheme is that it is easy to implement and does not require the use of floating-point arithmetic, which can be computationally intensive and may not be supported by all microcontroller.

### Q2 Part B

Reading a single sensor at 10-bit resolution is generally better than reading four sensors at 8-bit accuracy and averaging the results to get a 10-bit result. This is because reading a single sensor at a higher resolution generally provides more accurate results than averaging multiple sensors at a lower resolution.

One of the main advantages of reading a single sensor at 10-bit resolution is that it allows for a higher level of precision in the temperature readings. With 10 bits of resolution, the temperature can be measured in increments of 0.25 degrees Celsius, which is more precise than the 1 degree Celsius increments that are possible with 8-bit accuracy. This is especially important if the system needs to detect small changes in temperature, as it will be able to do so more accurately with a higher resolution sensor.

Another advantage of reading a single sensor at 10-bit resolution is that it is generally simpler and more reliable than reading multiple sensors and averaging the results. Averaging the readings from multiple sensors can introduce errors and inaccuracies if the sensors are not perfectly calibrated or if there are variations in the environment that affect their readings. Additionally, using multiple sensors increases the complexity of the system and may require more hardware resources, such as additional input pins or external components.

Overall, reading a single sensor at a higher resolution is generally the better choice in terms of accuracy and simplicity, as long as the sensor is capable of providing reliable readings over the required temperature range.

### Q2 Part C

To comply with MISRA-C Rule 19.15, you can use the preprocessor directive "#ifndef" in combination with the #define directive to ensure that a header file is only included once. This can be done as follows:

```C
#ifndef HEADER_H
#define HEADER_H

// contents of header file go here

#endif // HEADER_H
```

The "#ifndef" directive checks if the macro HEADER_H is not defined, and if it is not, the contents of the header file are included and the macro is defined using the #define directive. If the macro is already defined, the "#ifndef" directive will evaluate to false and the contents of the header file will not be included.

If this rule is violated and a header file is included multiple times, it can potentially impact the background LCD display task in a number of ways. For example, if the header file contains declarations of functions or variables that are used in the background task, those declarations may be included multiple times, which could result in a compile-time error. Additionally, if the header file contains definitions of functions or variables that are used in the background task, those definitions may be included multiple times, which could result in multiple copies of the functions or variables being present in the final executable, leading to potential runtime errors.

Overall, compliance with MISRA-C Rule 19.15 is important to ensure that header files are included correctly and that the background LCD display task functions correctly.

### Q2 Part D

The internal analog multiplexer in an ADC can have an effect on the effective number of bits (ENOB) of the ADC's temperature readings. ENOB is a measure of the resolution and accuracy of an ADC, and is typically expressed as the number of bits of resolution that the ADC can achieve when operated under certain conditions.

The effect of the internal analog multiplexer on the ENOB of the ADC's temperature readings will depend on a number of factors, including the number of channels that are multiplexed, the frequency of the multiplexing, and the signal-to-noise ratio (SNR) of the ADC. In general, the more channels that are multiplexed, the lower the ENOB of the ADC's readings will be, as the multiplexer will introduce additional noise and errors into the measurements. Similarly, the higher the frequency of the multiplexing, the lower the ENOB will be, as the ADC will have less time to accurately sample and convert the input signal.

To quantify the effect of the internal analog multiplexer on the ENOB of the ADC's temperature readings, additional information about the multiplexer itself and the system in which it is used will be needed. This may include information about the number of channels being multiplexed, the multiplexing frequency, the SNR of the ADC, and other relevant factors. By analyzing this information, it may be possible to estimate the impact of the multiplexer on the ENOB of the ADC's temperature readings and make any necessary adjustments to the system to optimize its performance.

### Q2 Part E

I agree with the statement that testing interrupt-rich code is difficult due to the unpredictable and unreproducible nature of real-world events. Interrupt-rich code is code that relies heavily on interrupt handlers to respond to external events or signals, such as input from sensors or user interfaces. These interrupt handlers can be triggered at any time, making it difficult to predict and control the execution flow of the code.

In the case of the high-reliability temperature monitor described in the previous questions, testing the interrupt-driven foreground task that reads the temperature sensors could be challenging due to the unpredictable nature of the interrupts. For example, if the interrupt handler is triggered by a change in the temperature reading, it may be difficult to reproduce a specific temperature change in a controlled testing environment. Additionally, the timing of the interrupts may vary depending on the environment and other external factors, making it difficult to predict the exact sequence of events that will occur during testing.

Overall, the unpredictable and unreproducible nature of real-world events can make it difficult to test interrupt-rich code, as it can be challenging to predict and control the execution flow of the code. This can make it difficult to ensure that the code is functioning correctly and meeting the required specifications.

## Question 3

In this system, there are four doors that are equipped with magnetic card readers and locks. Each door has its own instance of Task Qi that runs every 2 seconds with a phase shift. Task A is responsible for polling the magnetic card readers at each door and communicating with a different reader every 0.5 seconds. Task B is responsible for verifying the validity of a magnetic card and allowing or denying entry based on this verification.

Task A sends 13-byte messages to Task B containing information about the door and card being used, including the door id, reader id, card id, and a checksum for the card id. The checksums for all of the magnetic cards are stored in an unsorted list in memory. Task B performs a linear search through this list to verify the validity of the card.

For analysis purposes, we need to consider the operation of the system from t=0 to t=2 seconds. At t=0, card data is available at all doors. The card read at Door 0 is last in the Task B search list, while the card read at Door 1 is first in the search list. The card read at Door 2 is in the middle of the search list, and the card read at Door 3 is not in the search list. The execution times for tasks JAb, JAf, and JBd depend on the serial response or linear search time.

---
Task A is a periodic task that is responsible for polling each of the magnetic card readers at the four doors. It communicates with a different reader every 0.5 seconds. The task consists of several jobs that are executed in sequence.

The first job (JAa) requests the state of door i and clears the buffer. The second job (JAb) waits for a response from door i. If door i has responded with the reader id, the third job (JAc) adds the door number i and reader id to the buffer. The fourth job (JAe) is a loop that continues to execute as long as door i has more characters. Within this loop, the fifth job (JAf) requests a character from door i, the sixth job (JAg) waits for a response from door i, and the seventh job (JAh) adds the character to the buffer. If the buffer is not empty, the eighth job (JAi) sends a 13-byte message to Task B. The ninth job (JAk) increments the value of i by 1, and the tenth job (JAl) checks if i is greater than 3. If it is, the eleventh job (JAm) sets i back to 0.

Task B is a task that is released on the receipt of a message from Task A. It consists of several jobs that are executed in sequence. The first job (JBa) checks if the door id and reader identifier are both valid. If they are, the second job (JBb) calculates a checksum. The third job (JBc) checks if the calculated checksum matches the checksum received in the message from Task A. If it does, the fourth job (JBd) performs a top-down search of the list for the checksum. If the checksum is found in the list, the fifth job (JBe) sends a semaphore to Task Qi based on the door id.

Task Qi is a periodic task that runs for each of the four doors. It consists of three jobs that are executed in sequence. The first job (JDa) checks if a semaphore has been received from Task B. If it has, the second job (JDb) opens the door lock. If a semaphore has not been received, the third job (JDc) releases the door lock.

### Q3 Part A

In a foreground-background system, Task A, Qi (for each door) are foreground tasks that are triggered as needed by the periodic kernel-service interrupt, while Task B runs in the background.

For Task A, the timeline can be represented as follows:

```text
Time (seconds)  |  Task A job
----------------|----------------
      0         |  JAa
      0.1       |  JAb
      0.2       |  JAc
      0.4       |  JAd
      0.6       |  JAe
      0.7       |  JAf
      0.8       |  JAg
      1.0       |  JAh
      1.1       |  JAe
      ...       |  ...
      4.9       |  JAi
      5.0       |  JAj
      5.1       |  JAk
      5.2       |  JAl
      5.3       |  JAm
      5.4       |  JAa
      ...       |  ...
```

Here, Task A is triggered by the periodic kernel-service interrupt every 0.1 seconds. The task consists of several jobs that are executed in sequence. The timeline shows the execution of these jobs at regular intervals of 0.1 seconds.

For Task Qi for door i, the timeline can be represented as follows:

```text
Time (seconds)  |  Task Qi (door i) job
----------------|----------------
      0         |  JDa
      2         |  JDa
      4         |  JDa
      6         |  JDa
      ...       |  ...
```

Here, Task Qi for door i is triggered by the periodic kernel-service interrupt every 2 seconds. The task consists of a single job that is executed at these intervals.

For Task B, which runs in the background, the timeline can be represented as follows:

```text
Time (seconds)  |  Task B job
----------------|----------------
      0         |  JBa
      0.1       |  JBb
      0.2       |  JBc
      0.3       |  JBd
      0.4       |  JBe
      0.5       |  JBf
      ...       |  ...
```

Here, Task B is triggered by the receipt of a message from Task A and consists of several jobs that are executed in sequence. The timeline shows the execution of these jobs at regular intervals of 0.1 seconds.

The above timelines are just examples and the actual execution of the tasks and jobs may vary depending on the specific implementation and conditions of the system.

### Q3 Part B

In a fixed priority, pre-emptive priority-based scheduling system with a 100ms kernel tick, Task B has the highest priority, while Task A has the lowest priority. When a blocked task triggers a context switch, the next ready task in the queue is allowed to run.

The timeline for Task A can be represented as follows:

```text
Time (seconds)  |  Task A job
----------------|----------------
      0         |  JAa
      0.1       |  JAb
      0.2       |  JAc
      0.4       |  JAd
      0.6       |  JAe
      0.7       |  JAf
      0.8       |  JAg
      1.0       |  JAh
      1.1       |  JAe
      ...       |  ...
      4.9       |  JAi
      5.0       |  JAj
      5.1       |  JAk
      5.2       |  JAl
      5.3       |  JAm
      5.4       |  JAa
      ...       |  ...
```

Here, Task A is scheduled to run every 100ms, as specified by the kernel tick. However, it may be pre-empted by higher priority tasks, such as Task B, if they become ready to run. The timeline shows the execution of the jobs in Task A at regular intervals of 100ms.

For Task Qi for door i, the timeline can be represented as follows:

```text
Time (seconds)  |  Task Qi (door i) job
----------------|----------------
      0         |  JDa
      2         |  JDa
      4         |  JDa
      6         |  JDa
      ...       |  ...
```

Here, Task Qi for door i is scheduled to run every 2 seconds. However, it may be pre-empted by higher priority tasks, such as Task B, if they become ready to run. The timeline shows the execution of the job in Task Qi at regular intervals of 2 seconds.

For Task B, which has the highest priority, the timeline can be represented as follows:

```text
Time (seconds)  |  Task B job
----------------|----------------
      0         |  JBa
      0.1       |  JBb
      0.2       |  JBc
      0.3       |  JBd
      0.4       |  JBe
      0.5       |  JBf
      ...       |  ...
```

Here, Task B is triggered by the receipt of a message from Task A and consists of several jobs that are executed in sequence. The timeline shows the execution of these jobs at regular intervals of 0.1 seconds. Since Task B has the highest priority, it will be able to pre-empt lower priority tasks, such as Task A and Task Qi, if they are currently running.

The above timelines are just examples and the actual execution of the tasks and jobs may vary depending on the specific implementation and conditions of the system.

### Q3 Part C

There are several criteria that can be used to compare the real-time performance of the foreground-background and pre-emptive priority-based scheduling systems for the given embedded system scenario. These criteria include:

1. Response time: The response time is the time taken for a task to start executing after it becomes ready to run. In the foreground-background system, all tasks are triggered by the periodic kernel-service interrupt and run in the foreground. This means that the response time for all tasks is determined by the interval of the kernel-service interrupt. In the pre-emptive priority-based scheduling system, the response time for a task depends on its priority and the availability of higher priority tasks. Tasks with higher priority will have a shorter response time compared to tasks with lower priority.

1. Jitter: Jitter is the variation in the execution time of a periodic task. In the foreground-background system, all tasks are triggered by the periodic kernel-service interrupt, which means that the jitter for all tasks is determined by the interval of the kernel-service interrupt. In the pre-emptive priority-based scheduling system, the jitter for a task depends on its priority and the availability of higher priority tasks. Tasks with higher priority may have a lower jitter compared to tasks with lower priority.

1. Throughput: Throughput is the number of tasks that are completed within a given time period. In the foreground-background system, all tasks are triggered by the periodic kernel-service interrupt, which means that the throughput for all tasks is determined by the interval of the kernel-service interrupt. In the pre-emptive priority-based scheduling system, the throughput for a task depends on its priority and the availability of higher priority tasks. Tasks with higher priority may have a higher throughput compared to tasks with lower priority.

Based on these criteria, I would prefer to implement the pre-emptive priority-based scheduling system for the given embedded system scenario. This is because the pre-emptive priority-based scheduling system allows for better control over the response time, jitter, and throughput of the tasks by assigning different priorities to the tasks. This can be especially important in real-time systems where the timing of the tasks is critical. In contrast, the foreground-background system does not provide any mechanism for prioritizing tasks, which may result in poor real-time performance.

### Q3 Part D

The precedence graph for the jobs in the first instance of Task A can be represented as follows:

```text
                               JAa
                                 |
                              JAb--JAc
                                 |   |
                              JAd--JAe--JAf--JAg--JAh
                                 |            |
                              JAe----------JAi--JAj
```

Here, the jobs in Task A have the following relative deadlines:

- JAa: 100 ms
- JAb: 100 ms
- JAc: 100 ms
- JAd: 100 ms
- JAe: 100 ms
- JAf: 100 ms
- JAg: 100 ms
- JAh: 100 ms
- JAi: 100 ms
- JAj: 100 ms

The effective task deadlines of the jobs in Task A can be determined by adding the relative deadlines of the jobs to the release time of the task. For the first instance of Task A, the release time is t=0, so the effective task deadlines of the jobs can be calculated as follows:

- JAa: t=0 + 100 ms = 100 ms
- JAb: t=0 + 100 ms = 100 ms
- JAc: t=0 + 100 ms = 100 ms
- JAd: t=0 + 100 ms = 100 ms
- JAe: t=0 + 100 ms = 100 ms
- JAf: t=0 + 100 ms = 100 ms
- JAg: t=0 + 100 ms = 100 ms
- JAh: t=0 + 100 ms = 100 ms
- JAi: t=0 + 100 ms = 100 ms
- JAj: t=0 + 100 ms = 100 ms

If the Shortest-Job-First dynamic-priority-assignment algorithm is used, the tasks will be scheduled in the order of the shortest jobs first. In Task A

### Q3 Part E

There are several potential hazards and risks that the embedded system described in the scenario may present under any of the three specified scheduling schemes. These hazards and risks include:

1. Deadlines may be missed: One potential hazard is that the system may fail to meet the real-time deadlines of the tasks. This can happen if the tasks are not given sufficient time to execute, or if the system is overloaded and unable to complete the tasks in time. To mitigate this hazard, the system can use techniques such as rate-monotonic scheduling or dynamic priority scheduling to ensure that the tasks are given sufficient time to execute and meet their deadlines. Additionally, the system can be designed to handle overload conditions, such as by providing additional processing resources or by using techniques such as load shedding to temporarily reduce the workload.

1. Resources may be overused: Another potential hazard is that the system may overuse resources, such as memory or processing power, which can lead to performance degradation or system failures. To mitigate this hazard, the system can use techniques such as resource reservation or resource allocation to ensure that the tasks have access to the resources they need without overusing them. Additionally, the system can use techniques such as load balancing to distribute the workload across multiple resources and prevent any single resource from being overused.

1. System may become unstable: A third potential hazard is that the system may become unstable and prone to failures due to the complexity of the tasks and the interactions between them. To mitigate this hazard, the system can use techniques such as fault tolerance and error recovery to ensure that it can continue to operate even in the event of a failure. Additionally, the system can use techniques such as testing and simulation to identify and resolve potential stability issues before the system is deployed.
