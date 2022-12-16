# Past Paper 2018

## Question 1

µCOS-II (MicroController Operating System) is a real-time operating system (RTOS) kernel that is designed for use in microcontroller-based systems. It supports a range of features that are commonly found in RTOS kernels, including:

1. Preemptive priority-based multitasking: This allows tasks to be assigned priorities, and the RTOS will automatically switch between tasks based on their priority.

1. Cooperative multitasking: This allows tasks to run until they yield control of the CPU to another task, rather than being preempted by the RTOS.

1. Mutexes: These are used to synchronize access to shared resources between tasks, to prevent race conditions and other issues that can occur when multiple tasks attempt to access the same resource simultaneously.

1. Semaphores: These are used to signal between tasks, allowing one task to notify another that a particular event has occurred or a resource is available.

µCOS-II also provides a range of other features, such as support for interrupts, timers, and communication between tasks. It is typically used in embedded systems that require real-time behavior and/or multitasking capabilities.

### Q1 Part A

A real-time embedded system is a system that is designed to perform specific tasks within a predetermined time frame, often with very strict timing requirements. While an RTOS (real-time operating system) can be used to help manage and coordinate the various tasks within a real-time system, it is not necessarily required in all cases.

There are two key characteristics of a real-time embedded system that may make an RTOS unnecessary:

1. Single-task systems: If a real-time system only has one task that needs to be performed, an RTOS is not necessary because there is no need to coordinate or schedule multiple tasks.

1. Simple systems with minimal timing requirements: If a real-time system has very simple tasks and minimal timing requirements, it may be possible to implement the system using a simple, bare-metal approach rather than using an RTOS. This can be more efficient and may be easier to implement in some cases.

That being said, RTOSes are commonly used in real-time embedded systems due to the many benefits they offer, such as the ability to support multiple tasks, handle interrupts, and synchronize access to shared resources.

### Q1 Part B

Task scheduling is the process of selecting which task should be run next by the CPU. This is typically done based on the priority of the tasks and the scheduling algorithm being used by the RTOS. In µCOS-II, task scheduling is done by the kernel, which maintains a list of tasks that are ready to run and selects the next task to run based on its priority.

Context switching is the process of switching between tasks by saving the state (or context) of the currently running task and restoring the saved state of the next task that is going to run. This process is necessary in a multitasking system because it allows the CPU to switch between tasks without losing track of the current state of each task.

In µCOS-II, context switching is performed by the kernel when a task switch is required, either due to a higher-priority task becoming ready to run or because the currently running task has finished or yielded control of the CPU. The kernel saves the current state of the task (such as the value of registers and other CPU resources) and restores the saved state of the next task that is going to run. This allows the next task to pick up where it left off and ensures that the system can seamlessly switch between tasks without any loss of information.

### Q1 Part C

Deadlock is a situation that can occur when two or more tasks are blocked and waiting for each other to release a resource, resulting in a standstill where none of the tasks can proceed. In a co-operative priority-based system, deadlock can occur when mutexes are used to synchronize access to shared resources and the tasks are not programmed correctly.

There are several circumstances that can lead to deadlock in a co-operative priority-based system using mutexes:

Mutual exclusion: If two tasks are using mutexes to synchronize access to a shared resource, and each task holds the mutex while waiting for the other task to release it, a deadlock can occur.

Priority inversion: If a high-priority task is waiting for a low-priority task to release a mutex, the low-priority task may not run often enough to release the mutex, resulting in a deadlock.

Priority inheritance: If a high-priority task is waiting for a mutex that is held by a low-priority task, the low-priority task may not run often enough to release the mutex, resulting in a deadlock.

µCOS-II provides several features that can be used to prevent deadlock in co-operative priority-based systems:

Priority inheritance: This feature allows the kernel to temporarily boost the priority of a task that is holding a mutex that is being waited on by a higher-priority task. This ensures that the low-priority task runs more frequently and is able to release the mutex, preventing deadlock.

Timeout: This feature allows a task to specify a timeout when it waits for a mutex. If the mutex is not available within the specified timeout, the task will be unblocked and can proceed without the mutex. This can help prevent deadlock by allowing tasks to proceed even if the mutex is not immediately available.

Deadlock detection: This feature allows the kernel to detect when a deadlock has occurred and take appropriate action to resolve it. This may involve releasing one or more mutexes to allow the tasks to proceed, or taking other actions to break the deadlock.

### Q1 Part D

The Event Control Block (ECB) is a data structure used by the µCOS-II kernel to manage events and messages within the system. The ECB structure typically contains the following elements:

Event flags: These are used to signal the occurrence of an event or the availability of a message. They can be set or cleared by tasks or ISRs (interrupt service routines) to signal the occurrence of an event or to indicate that a message is ready to be received.

Message queue: This is a list of messages that are waiting to be received by a task. The message queue is used to store messages that are sent to a task but not yet received.

Semaphore: This is used to synchronize access to the message queue between the sender and receiver tasks. It is used to prevent race conditions and other issues that can occur when multiple tasks attempt to send or receive messages simultaneously.

Timer: This is used to implement timeouts for message-related functions. For example, a task may specify a timeout when it waits for a message to be received, and the timer is used to track the elapsed time and unblock the task if the timeout expires.

These elements of the ECB structure facilitate message-related functions by providing the necessary synchronization and signaling mechanisms to allow tasks to send and receive messages. The event flags and semaphore are used to synchronize access to the message queue and ensure that messages are delivered correctly. The timer is used to implement timeouts and allow tasks to proceed if a message is not received within a specified time frame. Together, these elements allow tasks to communicate and exchange data using messages, which is an important aspect of many real-time systems.

### Q1 Part E

The idle task is a special task that is run by the µCOS-II kernel when there are no other tasks that are ready to run. The idle task is typically implemented as a low-priority task that consumes very little CPU time and has a minimal impact on the overall system performance.

The main role of the idle task is to allow the kernel to track the actual system utilization. When the idle task is running, it means that there are no other tasks that are ready to run, and the CPU is idle. The kernel can track the amount of time that the idle task is running and use this information to determine the overall utilization of the system.

For example, if the idle task is running most of the time, it means that the system is not very busy and there is plenty of unused CPU time available. On the other hand, if the idle task is only running a small fraction of the time, it means that the system is heavily utilized and the CPU is busy running other tasks.

The idle task is also useful for conserving power in systems that are powered by batteries or other limited power sources. By allowing the CPU to idle when there is nothing else to do, the idle task can help reduce power consumption and extend the life of the system.

Overall, the idle task is an important component of the µCOS-II kernel that allows the system to track actual utilization and conserve power when necessary.

## Question 2

To implement this temperature monitoring system, you could use the following steps:

1. Connect the PIC18 microcontroller to the LCD display and temperature sensors.

1. Configure the microcontroller to read temperature data from the sensors using the ADC and interrupts.

1. Set up a foreground task to continuously read temperature data from the sensors and store it in a buffer.

1. Set up a background task to update the LCD display with the minimum, maximum, and most recent temperature readings.

1. Use a timer to trigger the background task to run every minute.

1. Implement a system to track the temperature readings over a 24-hour period. This could be done using a circular buffer or a rolling window of data.

1. Implement an alert system to display a message on the LCD if the temperature rises above 4 degrees Celsius for more than 15 minutes at any time during the 24-hour period. This could be done by maintaining a record of the temperature readings and checking for any sustained periods above the threshold.

It's important to ensure that the system is reliable and robust. You may want to consider implementing error handling and fault tolerance measures, such as checking the integrity of the temperature data and providing backup power sources in case of failures.

### Q2 Part A

One possible representation scheme to store temperature readings in this system would be to use fixed-point notation, which allows you to represent a number as a whole number and a fractional part. In this case, you could represent each temperature reading as a 16-bit integer, with the most significant byte representing the whole number portion and the least significant byte representing the fractional part.

For example, to store the temperature reading of 4.1 degrees Celsius, you could use the following binary representation:

0000 0100.0001 1000

The most significant byte (0000 0100) represents the whole number portion of the temperature (4 degrees), and the least significant byte (0001 1000) represents the fractional part (0.1 degrees).

To store the temperature reading of 19.7 degrees Celsius, you could use the following binary representation:

0001 1001.0111 0000

The most significant byte (0001 1001) represents the whole number portion of the temperature (19 degrees), and the least significant byte (0111 0000) represents the fractional part (0.7 degrees).

This representation scheme allows you to store temperature readings with a resolution of 0.1 degrees Celsius, which meets the system requirement of having a resolution of 0.1 degree Celsius. It also allows you to store temperature readings with an accuracy of ±1 degree Celsius, which meets the system requirement of having an accuracy of ±1 degree Celsius.

In addition, using a fixed-point representation scheme allows you to easily perform arithmetic operations on the temperature readings, such as finding the minimum, maximum, or average temperature. It also allows you to easily convert the temperature readings to other units, such as Fahrenheit, if needed.

### Q2 Part B

It is generally better to read a single sensor at 10-bit resolution rather than reading four sensors at 8-bit accuracy and averaging to get a 10-bit result.

One reason for this is that reading a single sensor at 10-bit resolution will typically provide more accurate and consistent results compared to reading multiple sensors and averaging the readings. This is because averaging the readings from multiple sensors can potentially introduce errors and noise, especially if the sensors have different offsets or sensitivities. In addition, averaging the readings from multiple sensors can also introduce additional latency, as the system needs to wait for all of the sensor readings to be obtained before the average can be calculated.

On the other hand, reading a single sensor at 10-bit resolution allows you to directly obtain a high-resolution reading from the sensor, which can be more accurate and consistent compared to averaging multiple lower-resolution readings. In addition, reading a single sensor at 10-bit resolution can be faster and more efficient, as the system does not need to wait for multiple sensor readings or perform additional calculations to obtain the final result.

Therefore, if the goal is to obtain the most accurate and consistent temperature readings with the least amount of latency and complexity, it is generally better to read a single sensor at 10-bit resolution rather than reading four sensors at 8-bit accuracy and averaging the results.

### Q2 Part C

Here is a fragment of C code that violates MISRA-C Rule 15.2:

```C
switch (temp) {
  case 0:
    printf("Temperature is 0 degrees Celsius\n");
    break;
  case 1:
    printf("Temperature is 1 degree Celsius\n");
  case 2:
    printf("Temperature is 2 degrees Celsius\n");
    break;
  default:
    printf("Temperature is above 2 degrees Celsius\n");
}
```

In this code fragment, the case 1 clause does not have a break statement, which violates MISRA-C Rule 15.2. If the temperature is 1 degree Celsius, the code will execute both the case 1 and case 2 clauses, which may not be the intended behavior.

This violation of MISRA-C Rule 15.2 could impact the background LCD display task in a number of ways. For example, if the background task is using the 'temp' variable to determine which message to display on the LCD, the task may display the wrong message if the 'temp' value is 1. This could lead to confusion or errors in the operation of the system. In addition, the lack of a break statement in the case 1 clause could also cause the background task to execute more code than necessary, which could lead to slower performance and increased power consumption.

### Q2 Part D

The internal analog multiplexer (MUX) in a microcontroller can have an effect on the effective number of bits (ENOB) of the ADC temperature readings. The ENOB is a measure of the resolution and accuracy of the ADC, and is typically defined as the number of bits of resolution in the ADC output that are actually useful for making measurements.

The effect of the internal MUX on the ENOB of the ADC temperature readings will depend on several factors, including the design of the MUX and the ADC, the number of channels available on the MUX, and the signal-to-noise ratio (SNR) of the ADC.

In general, using the internal MUX to switch between multiple analog input channels can reduce the ENOB of the ADC temperature readings if the MUX introduces additional noise or offsets into the ADC input signal. This can occur if the MUX has a high channel-to-channel isolation, or if the MUX introduces additional capacitance or resistance into the ADC input circuit.

To quantify the effect of the internal MUX on the ENOB of the ADC temperature readings, you would need to measure the ENOB of the ADC under different MUX configurations and compare the results. You would also need to consider other factors that could affect the ENOB of the ADC, such as the sampling rate, the input range, and the input impedance of the ADC.

In general, it is important to carefully design and optimize the MUX and ADC circuitry to ensure that the ENOB of the ADC temperature readings is as high as possible, in order to maximize the accuracy and resolution of the temperature measurements.

### Q2 Part E

The statement "In high-reliability systems, where failures may endanger life, the use of interrupts is viewed with some suspicion" suggests that interrupts may be viewed with caution in systems where the consequences of failures could be severe or life-threatening. This may be because interrupts can potentially introduce additional complexity and potential failure points into a system, which could increase the risk of errors or failures.

I agree with this statement, as the use of interrupts in high-reliability systems should be carefully considered and carefully designed in order to minimize the risk of errors or failures. This is especially true in systems where failures could have serious or life-threatening consequences, such as medical devices, aviation systems, or safety-critical control systems.

In the case of a walk-in refrigerator, the consequences of failures may not necessarily be life-threatening, but they could still have serious impacts on the safety and quality of the food stored in the refrigerator. For example, if the temperature monitoring system in the walk-in refrigerator were to fail due to an interrupt-related error, it could potentially lead to the spoilage of food or the growth of harmful bacteria, which could pose a risk to public health.

Therefore, it is important to carefully consider the use of interrupts in the temperature monitoring system of the walk-in refrigerator, and to design the system in a way that minimizes the risk of errors or failures related to interrupts. This may involve using robust interrupt handling strategies, testing the system extensively, and providing backup or fail-safe measures in case of interrupt-related failures.

## Question 3

This system description outlines the various tasks and their associated processes that are running on a PIC18 microcontroller in an embedded system for a refrigeration controller.

Task 1, BLDC Control, is responsible for controlling the PWM signals for the compressor and runs at 100ms intervals if the global boolean variable Running is set to TRUE. The task consists of several processes that control the compressor, including setting the Operating Light to ON, checking for compressor faults, and setting the PWM Duty Cycle based on the Temperature Error.

Task 2, Temperature Monitor, reads the temperature sensor at 0.5s intervals and updates a local static variable called Temperature. It also checks if the temperature exceeds 4C and puts a '*' character on the TXQ message queue for transmission via Bluetooth.

Task 3, Interface Control, is responsible for managing the serial communication and user interface of the system. It runs at 1s intervals and has a phase delay of 0.25s. It includes processes for handling button press events, consuming a Semaphore S1 associated with compressor faults, and managing the transmission and reception of ASCII characters over the Bluetooth connection.

The ISRHandler is an interrupt service routine that manages the RXQ and TXQ message queues for serial communication. It runs on demand and has a baud rate of 300, with 8 data bits, no parity bit, and 1 stop bit. It consists of two processes, one for handling Rx interrupts and another for handling Tx interrupts.

Overall, this system appears to be designed to monitor and control the operation of a refrigeration system, including the compressor, temperature sensor, and user interface. The use of mutexes and semaphores helps to ensure that shared resources and variables are accessed safely and efficiently.

### Q3 Part A

To construct a cyclic executive schedule for the execution of tasks 1 to 3 with a minor cycle of 50ms, we can follow the following steps:

1. Determine the minimum execution time (e) and phase delay (p) for each task:
    - Task 1: e = 10ms, p = 0
    - Task 2: e = 10ms, p = 0
    - Task 3: e = 20ms, p = 25ms

1. Calculate the number of minor cycles (n) required to execute each task based on its minimum execution time (e) and the minor cycle period (T):
    - Task 1: n = e / T = 10ms / 50ms = 0.2 cycles
    - Task 2: n = e / T = 10ms / 50ms = 0.2 cycles
    - Task 3: n = e / T = 20ms / 50ms = 0.4 cycles

1. Determine the start time for each task based on its phase delay (p) and the minor cycle period (T):
   - Task 1: start time = p % T = 0 % 50ms = 0ms
   - Task 2: start time = p % T = 0 % 50ms = 0ms
   - Task 3: start time = p % T = 25ms % 50ms = 25ms

1. Create a schedule table with the start time, number of minor cycles, and task number for each task:

| Start Time (ms) | Number of Cycles | Task Number |
|-----------------|------------------|-------------|
| 0               | 0.2              | 1           |
| 0               | 0.2              | 2           |
| 25              | 0.4              | 3           |

1. Repeat the schedule table for each minor cycle, starting from the first row:

| cycle | Start Time (ms) | Number of Cycles | Task Number |
|-------|-----------------|------------------|-------------|
| 1     | 0               | 0.2              | 1           |
| 1     | 0               | 0.2              | 2           |
| 1     | 25              | 0.4              | 3           |
| 2     | 0               | 0.2              | 1           |
| 2     | 0               | 0.2              | 2           |
| 2     | 25              | 0.4              | 3           |
| ...   | ...             | ...              | ...         |

With this schedule, we can ensure that all tasks are executed within their required minimum execution time and that their execution is synchronized with the minor cycle of 50ms. Interrupts will not be disabled during the execution of the tasks, allowing the ISRHandler to run as needed.

### Q3 Part B

To construct and graph appropriate task timelines for the execution of tasks 1 to 3 in the embedded system scenario using a time-based task manager with a 100ms tick, we can follow the following steps:

1. Determine the minimum execution time (e) and phase delay (p) for each task:
   - Task 1: e = 10ms, p = 0
   - Task 2: e = 10ms, p = 0
   - Task 3: e = 20ms, p = 25ms

1. Calculate the number of ticks (n) required to execute each task based on its minimum execution time (e) and the tick period (T):
    - Task 1: n = e / T = 10ms / 100ms = 0.1 ticks
    - Task 2: n = e / T = 10ms / 100ms = 0.1 ticks
    - Task 3: n = e / T = 20ms / 100ms = 0.2 ticks

1. Determine the start time for each task based on its phase delay (p) and the tick period (T):
    - Task 1: start time = p % T = 0 % 100ms = 0ms
    - Task 2: start time = p % T = 0 % 100ms = 0ms
    - Task 3: start time = p % T = 25ms % 100ms = 25ms

1. Create a schedule table with the start time, number of ticks, and task number for each task:

| Start Time(ms) | Number of Ticks | Task Number |
|----------------|-----------------|-------------|
| 0              | 0.1             | 1           |
| 0              | 0.1             | 2           |
| 25             | 0.2             | 3           |

1. Graph the task timelines by plotting the start time and duration for each task on a timeline:

```text
[Task 1] 0ms 10ms
|--------|

[Task 2] 0ms 10ms
|--------|

[Task 3] 25ms 45ms
|--------|

```

In this example, each task is allowed to run for its required minimum execution time of 10ms or 20ms, depending on the task. If a task is blocked, it will trigger a context switch to the next ready task, allowing other tasks to run in the meantime. Interrupts will not be disabled during the execution of the tasks, allowing the ISRHandler to run as needed.

### Q3 Part C

There are several criteria that can be used to compare the performance of tasks in the embedded system scenario using a cyclic executive and a time-based task manager. These include:

1. Predictability: A cyclic executive schedule allows tasks to be executed in a predictable and deterministic manner, as the schedule is fixed and each task runs for a fixed number of minor cycles or ticks. In contrast, a time-based task manager may be less predictable, as tasks may be blocked or delayed and cause a context switch to the next ready task.

1. Responsiveness: A time-based task manager may be more responsive to changes in the system, as it allows tasks to be preempted and replaced with higher priority tasks as needed. In contrast, a cyclic executive schedule may be less responsive, as tasks are executed in a fixed order and may not be able to be preempted.

1. Overhead: A cyclic executive schedule may have lower overhead compared to a time-based task manager, as it does not require the context switches and queue management that are necessary in a time-based task manager. This can make it more efficient and easier to implement.

Based on these criteria, it is difficult to determine which system would be preferred without more information about the specific requirements and constraints of the embedded system. If predictability and low overhead are the most important factors, a cyclic executive schedule may be preferred. If responsiveness and the ability to handle changes in the system are the most important factors, a time-based task manager may be preferred.

### Q3 Part D

To determine the effective task deadlines of the jobs in Task 1 and the order in which they would run using the Deadline Monotonic priority-assignment algorithm, we can use a precedence graph as follows:

1. Create a node for each job in Task 1, using the job number and relative deadline as labels:
    - J11 (e=10ms, d=50ms)
    - J12 (e=5ms, d=50ms)
    - J13 (e=10ms, d=50ms)
    - J14 (e=5ms, d=50ms)
    - J15 (e=15ms, d=50ms)

1. Create directed edges between the nodes to represent the dependencies between the jobs. For example, if Job J11 must be completed before Job J12 can start, we would draw an arrow from J11 to J12:

    J11 --> J12 --> J13 --> J14 --> J15

1. Calculate the effective deadline for each job by adding its relative deadline to the earliest time at which it can start. For example, the effective deadline for Job J11 would be 10ms + 50ms = 60ms.

    - J11 (e=10ms, d=50ms, ed=60ms)
    - J12 (e=5ms, d=50ms, ed=65ms)
    - J13 (e=10ms, d=50ms, ed=70ms)
    - J14 (e=5ms, d=50ms, ed=75ms)
    - J15 (e=15ms, d=50ms, ed=80ms)

1. Sort the jobs based on their effective deadlines, with the jobs with the shortest effective deadlines first. In this case, the order would be:

    J11 --> J12 --> J13 --> J14 --> J15

1. If there are multiple jobs with the same effective deadline, sort them based on their execution time, with the jobs with the shortest execution times first.

Using the Deadline Monotonic priority-assignment algorithm, the jobs in Task 1 would be scheduled in the following order: J11, J12, J13, J14, J15. This ensures that the jobs with the shortest effective deadlines are given the highest priority and are executed first, while still ensuring that all jobs are completed within their relative deadlines.

### Q3 Part E

There are several potential hazards or risks that the embedded system may present if it is implemented using pre-emptive priority-based scheduling, where Task 1 has the highest priority, Task 3 has the lowest priority, and interrupts are never disabled. These hazards and risks include:

1. Priority inversion: Priority inversion occurs when a low-priority task holds a resource that is needed by a high-priority task, causing the high-priority task to be blocked. This can lead to long delays or errors in the system. To mitigate this risk, we can use priority inheritance or priority ceiling protocols to temporarily boost the priority of the low-priority task when it holds a resource that is needed by a high-priority task.

1. Indefinite blocking: If a high-priority task is indefinitely blocked or delayed, it can cause lower-priority tasks to be starved of CPU time and never get a chance to run. To mitigate this risk, we can use a timer or watchdog mechanism to ensure that high-priority tasks do not run for too long and prevent lower-priority tasks from running.

1. Deadlock: If a high-priority task is waiting for a resource that is held by a low-priority task, and the low-priority task is waiting for a resource that is held by the high-priority task, it can lead to a deadlock situation where neither task can progress. To mitigate this risk, we can use a deadlock detection and recovery mechanism to detect and resolve deadlocks in the system.

Overall, it is important to carefully consider the risks and hazards associated with pre-emptive priority-based scheduling and implement appropriate mitigating strategies to ensure that the system operates reliably and meets its real-time requirements.
