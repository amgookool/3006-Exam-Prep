# Past Paper 2021

## Question 1

Yes, the ESP8266 RTOS SDK is an example of a tick-driven real-time operating system (RTOS) kernel. RTOS kernels are designed to provide a predictable, deterministic execution environment for real-time systems that require precise timing and rapid response to events. The ESP8266 RTOS SDK is based on the FreeRTOS kernel and is designed to run on the ESP8266 microcontroller, which is a low-cost, low-power system-on-chip (SoC) with built-in WiFi capabilities.

The ESP8266 RTOS SDK uses a tick-driven scheduling model, which means that it uses a periodic timer interrupt (called the "tick") to schedule the execution of tasks and jobs. Tasks and jobs are the basic units of execution in the ESP8266 RTOS SDK and are used to implement the logic of an application. Tasks are preemptive, meaning that they can be interrupted and resumed at any time, while jobs are co-operative, meaning that they run to completion before yielding control to other tasks or jobs.

The ESP8266 RTOS SDK also provides a range of features and services that are commonly found in RTOS kernels, such as support for semaphores, mutexes, and message queues, as well as a range of memory management and communication functions. It is designed to be easy to use and is well-documented, making it a popular choice for developing real-time applications on the ESP8266 microcontroller.

### Q1 Part A

Periodic tasks and/or jobs are tasks that execute at regular intervals, with a fixed period between successive executions. They are characterized by their period (the time between successive executions) and their worst-case execution time (WCET), which is the maximum amount of time it takes for the task to execute.

Aperiodic tasks and/or jobs are tasks that do not execute at regular intervals and do not have a fixed period. They may be triggered by external events or by the completion of other tasks or jobs. Aperiodic tasks and/or jobs may have variable execution times and may not be bounded by a fixed WCET.

Sporadic tasks and/or jobs are tasks that execute at irregular intervals, with a minimum inter-arrival time between successive executions. They are similar to aperiodic tasks and/or jobs in that they are not bound by a fixed period, but they are distinguished by the requirement that they must not execute too frequently. The minimum inter-arrival time is used to ensure that sporadic tasks do not consume too many system resources or interfere with the execution of other tasks and/or jobs.

In a real-time system, periodic tasks and/or jobs are used to implement time-critical functionality that must be executed at regular intervals, while aperiodic tasks and/or jobs are used to handle event-driven or asynchronous functionality. Sporadic tasks and/or jobs are used in systems where a task may need to execute at irregular intervals, but with a minimum separation between successive executions to ensure that it does not consume too many resources or interfere with the execution of other tasks and/or jobs.

### Q1 Part B

In a real-time system, it is important to choose an appropriate task scheduling approach that can meet the timing and performance requirements of the system. Listing I uses a preemptive priority-based scheduling approach, while Listing II uses a cyclic executive approach.

I would prefer Listing I in this context because it provides a more flexible and deterministic scheduling approach that can better meet the timing requirements of the system. In Listing I, Job A is triggered by a high level on a GPIO pin, which means that it can execute as soon as the event occurs, without having to wait for the next slot in the cyclic executive. This is important for aperiodic tasks, as it allows them to respond to events as soon as they occur, rather than having to wait for the next slot in the cyclic executive.

In addition, Listing I uses priority-based scheduling, which allows the system to prioritize tasks based on their importance. This can be useful in a real-time system where some tasks may have more critical timing requirements than others. For example, if Job A is more time-critical than Job B or Job C, it can be assigned a higher priority to ensure that it is always given priority over the other tasks.

On the other hand, Listing II uses a cyclic executive approach, which executes tasks in fixed slots at regular intervals. While this approach can be suitable for systems with simple and predictable timing requirements, it may not be suitable for systems with more complex or variable timing requirements, such as the system described in this scenario. This is because the cyclic executive approach may not be able to respond quickly enough to aperiodic tasks and may not be able to prioritize tasks based on their importance.

In summary, I would prefer Listing I in this context because it provides a more flexible and deterministic scheduling approach that can better meet the timing requirements of the system and allow for the prioritization of tasks based on their importance.

### Q1 Part C

In software development, "thread-safe" refers to the ability of a function, method, or code block to be safely executed concurrently by multiple threads without causing errors or unintended side effects. A function or code block is said to be thread-safe if it can be called simultaneously by multiple threads without the need for explicit synchronization, such as mutexes or semaphores.

On the other hand, a function or code block that is not thread-safe may produce unexpected results or cause errors when called concurrently by multiple threads. This can occur if the function or code block accesses or modifies shared data or resources without proper synchronization, leading to data races and race conditions.

In the case of the ESP8266 RTOS SDK, the I2C APIs are not thread-safe, which means that they may not be safely called concurrently by multiple tasks or threads. If you want to use one I2C port in different tasks, you need to take care of the resulting multi-thread issue to ensure that the I2C APIs are used safely and correctly.

One strategy to manage the multi-thread issue in this case would be to use a mutex to synchronize access to the I2C port. A mutex is a synchronization object that allows only one task or thread to access a shared resource at a time. By using a mutex to synchronize access to the I2C port, you can ensure that only one task or thread can use the I2C APIs at a time, preventing data races and race conditions.

To use a mutex to synchronize access to the I2C port, you would first need to create a mutex using the xSemaphoreCreateMutex() function. Then, each task or thread that needs to use the I2C port would need to call the xSemaphoreTake() function to obtain the mutex before using the I2C APIs, and call the xSemaphoreGive() function to release the mutex after using the I2C APIs. This will ensure that only one task or thread can use the I2C port at a time, preventing data races and race conditions.

Here is an example of how you might use a mutex to synchronize access to the I2C port in the ESP8266 RTOS SDK:

```C
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

SemaphoreHandle_t i2c_mutex;

void task1(void *arg)
{
    // Obtain the mutex before using the I2C port
    xSemaphoreTake(i2c_mutex, portMAX_DELAY);
    // Use the I2C port here
    i2c_master_write_byte(...);
    // Release the mutex after using the I2C port
    xSemaphoreGive(i2c_mutex);
}

void task2(void *arg)
{
    // Obtain the mutex before using the I2C port
    xSemaphoreTake(i2c_mutex, portMAX_DELAY);
    // Use the I2C port here
    i2c_master_read_byte(...);
    // Release the mutex after using the I2C port
    xSemaphoreGive(i2c_mutex);
}

void app_main(void)
{
    i2c_mutex = xSemaphoreCreateMutex();
    xTaskCreate();
}
```

### Q1 Part D

Running two copies of a task, with separate task-control blocks, on the same processor does not generally qualify as a redundant sub-system in the context of critical systems. This is because both copies of the task are still running on the same processor, and a failure or malfunction of the processor would affect both copies of the task.

Redundant sub-systems are designed to provide backup or failover capabilities in the event of a failure or malfunction of the primary system. In the context of critical systems, redundant sub-systems are typically implemented using multiple independent processors, rather than multiple copies of a task running on the same processor. This ensures that a failure or malfunction of one processor does not affect the operation of the other processor, allowing the system to continue operating even if one processor fails.

There have been several cases of embedded system failures in critical systems where the use of redundant sub-systems could have prevented or mitigated the failure. For example, the Mars Climate Orbiter mission in 1999 was lost due to a failure in the navigation system, which was caused by a unit conversion error that went undetected due to a lack of redundant sub-systems. In this case, the use of redundant sub-systems could have detected the error and prevented the loss of the spacecraft.

Another example is the Fukushima Daiichi nuclear disaster in 2011, which was caused by a failure in the cooling system of the nuclear power plant. The cooling system failed due to a loss of power, which was caused by the tsunami that followed the Tohoku earthquake. The disaster could have been prevented or mitigated if the cooling system had been designed with redundant sub-systems, such as multiple independent power sources or backup pumps, to ensure that the system could continue to operate even in the event of a power failure or other failure.

In summary, running two copies of a task, with separate task-control blocks, on the same processor does not generally qualify as a redundant sub-system in the context of critical systems. Redundant sub-systems are typically implemented using multiple independent processors to provide backup or failover capabilities in the event of a failure or malfunction of the primary system.

### Q1 Part E

Trusted Platform Modules (TPMs) are specialized microcontroller that are designed to secure embedded systems by providing hardware-based security features such as secure boot, hardware-based encryption, and secure key storage. TPMs are typically used in systems that require a high level of security, such as in military, financial, or medical applications.

One of the main roles of TPMs in embedded systems is to provide a secure boot process, which ensures that only trusted software can be run on the system. The TPM performs this role by verifying the integrity of the system's firmware and software during the boot process, and only allowing the system to boot if the firmware and software are trusted and have not been tampered with. This helps to prevent malware and other threats from running on the system, and ensures that the system is running only trusted and approved software.

Another role of TPMs in embedded systems is to provide hardware-based encryption and secure key storage. TPMs can generate and store encryption keys and other sensitive data in a secure, hardware-based key store, which is protected by hardware-based security measures such as physical tampering detection and secure boot. This helps to prevent unauthorized access to sensitive data and ensures that the data is only accessible to authorized parties.

One advantage of utilizing TPMs in embedded systems is that they provide a strong and reliable security foundation for the system, which can be difficult to achieve using software-based security measures alone. TPMs are particularly useful in systems that require a high level of security, as they provide hardware-based security features that are more resistant to attacks and tampering.

However, one disadvantage of utilizing TPMs in embedded systems is that they can add complexity and cost to the system. TPMs require additional hardware and software components, which can increase the cost and complexity of the system. In addition, TPMs can be difficult to integrate into existing systems, as they require specialized software and hardware support. This can make it challenging to implement TPMs in systems that were not designed with TPMs in mind.

In summary, the role of TPMs in embedded systems is to provide hardware-based security features such as secure boot, hardware-based encryption, and secure key storage. TPMs provide a strong and reliable security foundation for the system, but can also add complexity and cost to the system.

## Question 2

### Q2 Part A

The ESP8266 can handle a maximum I2C transfer speed of 400 kilo bits per second, so the 100 kilo bits/second transfer speed should not be a problem. However, the rate at which the ADC is sampling (250 samples per second) and the rate at which the ESP8266 is able to read the data from the ADC (100 kilo bits per second) may create a bottleneck.

To calculate the amount of time it takes for the ESP8266 to read a single sample from the ADC, you can use the following formula:

time per sample = (number of bits per sample) / (transfer speed)

For a 16-bit ADC, the number of bits per sample is 16. Plugging this into the formula, we get:

time per sample = 16 bits / 100 kilo bits/second = 0.00016 seconds/sample

This means it takes the ESP8266 approximately 160 microseconds to read a single sample from the ADC. With the ADC sampling at a rate of 250 samples per second, this means the ESP8266 is only able to read about 62.5% of the samples being generated by the ADC. If you need to read all of the samples being generated by the ADC, you may need to consider using a faster transfer speed or finding a way to increase the rate at which the ESP8266 can read the data.

#### A-Part (i)

It takes approximately 50 bus cycles to retrieve an ADC reading because each bus cycle consists of a start condition followed by a 7-bit slave address, a read/write bit, and an acknowledgement bit from the slave. This means that it takes a minimum of 8 bus cycles to initiate a read operation on the I2C bus and retrieve a single byte of data.

For a 16-bit ADC, two bytes of data must be read to retrieve the full ADC reading. This means it takes at least 16 bus cycles to read a single ADC reading. However, additional bus cycles may be required depending on the specific implementation of the I2C protocol being used. For example, some implementations may use a repeated start condition instead of a stop condition to switch between write and read operations, which would require additional bus cycles.

It's also worth noting that the number of bus cycles required to retrieve an ADC reading will depend on the specific ADC and I2C interface being used. Some ADCs may use a different number of bits or require a different number of bytes to be read in order to retrieve the full ADC reading. Additionally, some I2C implementations may require more or fewer bus cycles to perform a read operation.

#### A-Part (ii)

The maximal frequency at which 16-bit ADC readings transferred via I2C can be used to reliably detect and track changes will depend on several factors, including:

1. The speed of the I2C bus: The transfer speed of the I2C bus will determine how quickly data can be transferred between the ADC and the microcontroller.

1. The rate at which the ADC is sampling: The ADC must be able to sample the input signal at a high enough rate to accurately capture the changes in the signal.

1. The processing time of the microcontroller: The microcontroller must be able to process the ADC readings quickly enough to detect and track changes in the signal.

1. The resolution of the ADC: A higher resolution ADC will be able to capture smaller changes in the input signal, allowing for more accurate detection and tracking of changes.

1. The noise in the system: Any noise in the system, such as electrical noise on the I2C bus or noise in the input signal, can make it more difficult to accurately detect and track changes in the signal.

To determine the maximal frequency at which ADC readings can be used to reliably detect and track changes, you will need to consider all of these factors and determine the limiting factor. For example, if the ADC is sampling at a high rate but the microcontroller is unable to process the readings fast enough, the maximal frequency will be limited by the processing speed of the microcontroller. On the other hand, if the ADC is not sampling fast enough to accurately capture the changes in the signal, the maximal frequency will be limited by the ADC's sampling rate.

### Q2 Part B

One benefit of utilizing coding standards in developing embedded systems that use the ESP8266 RTOS SDK is that it can help ensure that the code is consistent, easy to understand, and maintainable. Coding standards provide a set of guidelines for how code should be written, including conventions for naming variables and functions, formatting code, and commenting. Adhering to these standards can make it easier for other developers to understand and work with the code, which can save time and reduce the risk of errors.

One drawback of utilizing coding standards is that it can add overhead to the development process. Adhering to coding standards requires extra effort and attention to detail, which can slow down development. Additionally, some coding standards may be more stringent than necessary for a particular project, which can lead to unnecessary complexity.

As for the AUTOSAR Rule A7-5-2, which states that "Functions shall not call themselves, either directly or indirectly," this rule is intended to prevent infinite recursion. If a function calls itself directly or indirectly (e.g. through another function), it can create an infinite loop in which the function is called repeatedly without ever terminating. This can lead to an uncontrolled consumption of resources, such as memory or processing power, which can cause the system to crash or become unresponsive. By prohibiting functions from calling themselves, the AUTOSAR standard helps to ensure that functions are well-behaved and do not cause problems for the system.

### Q2 Part C

The ESP8266 (ESP-01s) typically has three types of information programmed into its SPI flash memory:

1. Bootloader: The bootloader is the first code that is executed when the ESP8266 is powered on or reset. Its primary function is to initialize the hardware and load the second-stage bootloader or the application firmware, depending on the mode of operation.

1. Second-stage bootloader: The second-stage bootloader is a small program that is responsible for loading the application firmware into memory. It is typically stored at the end of the SPI flash and is loaded by the first-stage bootloader during startup.

1. Application firmware: The application firmware is the main program that runs on the ESP8266 and is responsible for executing the desired functionality of the device. It is typically stored in the middle of the SPI flash and is loaded by the second-stage bootloader during startup.

During startup, the ESP8266 first executes the first-stage bootloader, which initializes the hardware and checks for the mode of operation (e.g., normal operation, bootloader mode, etc.). If the device is in normal operation mode, the first-stage bootloader will load the second-stage bootloader, which in turn will load the application firmware. The application firmware is then executed, and the device starts functioning as intended.

The partitions table is a data structure that is used to define the layout of the flash memory on the ESP8266. It specifies the size and location of different regions of the flash, such as the bootloader, second-stage bootloader, application firmware, and any other data that may be stored in the flash.

The partitions table is typically stored in the flash memory itself and is accessed by the first-stage bootloader during startup. It helps the bootloader determine where the different components of the system are located in the flash and how to access them. The partitions table also allows the system to be divided into multiple logical partitions, each with a specific purpose and role in the overall system.

For example, the partitions table may define a boot partition that contains the first-stage bootloader, a second-stage bootloader partition that contains the second-stage bootloader, and an app partition that contains the application firmware. The bootloader can then use the information in the partitions table to determine where each of these partitions is located in the flash and how to load them into memory.

### Q2 Part D

One technique for determining an appropriate task stack size for the ESP8266 RTOS SDK is to use the "worst case stack usage analysis" method. This technique involves analyzing the code that will run within a task to determine the maximum amount of stack space that will be required by the task at any given time.

To perform the worst case stack usage analysis, you can follow these steps:

1. Identify all the functions that will be called within the task and the maximum number of function arguments and local variables that will be used by each function.

1. Determine the maximum number of bytes required to store each function argument and local variable, taking into account the type and size of each variable.

1. Calculate the total number of bytes required for all function arguments and local variables by adding up the sizes of each variable.

1. Add a conservative estimate of the stack space required for system-level functions and interrupts, as well as any other overhead that may be required by the RTOS.

Using this technique, you can determine the minimum stack size required by the task and allocate a stack of that size.

The worst case stack usage analysis technique is more likely to over-size the task stack, as it includes a conservative estimate of the stack space required for system-level functions and interrupts. This means that the stack size may be larger than strictly necessary, which could lead to wasted memory.

The potential ramifications of using a "bad" task stack size, either one that is too small or too large, depend on the specific circumstances of the system. If the task stack size is too small, the task may run out of stack space and crash, leading to unpredictable behavior and potential system failure. On the other hand, if the task stack size is too large, it may waste valuable memory resources that could be used for other purposes. It is therefore important to carefully consider the task stack size and allocate an appropriate amount of memory to ensure reliable and efficient operation of the system.

Here are two additional techniques for determining an appropriate task stack size for the ESP8266 RTOS SDK:

1. Stack Watermarking: Stack watermarking is a technique that involves inserting specific values into the task stack at specific points in the code. These values can then be checked periodically to determine how much stack space has been used by the task. To use this technique, you can insert watermark values at the beginning and end of each function, as well as at key points in the code where the stack usage is expected to be high. You can then monitor the stack usage over time and adjust the stack size as needed to ensure that it is sufficient for the task's needs.

1. Stack Monitoring: Stack monitoring is a technique that involves monitoring the stack usage of a task at runtime and adjusting the stack size as needed. To use this technique, you can set up a timer or interrupt to periodically check the stack usage and compare it to the total stack size. If the stack usage exceeds a certain threshold, you can increase the stack size to ensure that the task has sufficient stack space.

Both of these techniques are more likely to under-size the task stack, as they are based on real-time monitoring of the stack usage and do not include a conservative estimate of the stack space required for system-level functions and interrupts.

As with any technique for determining an appropriate task stack size, the potential ramifications of using a "bad" task stack size depend on the specific circumstances of the system. If the task stack size is too small, the task may run out of stack space and crash, leading to unpredictable behavior and potential system failure. On the other hand, if the task stack size is too large, it may waste valuable memory resources that could be used for other purposes. It is therefore important to carefully consider the task stack size and allocate an appropriate amount of memory to ensure reliable and efficient operation of the system.

### Q2 Part E

There are several reasons why developers of ESP8266-based critical-systems might decide to forgo using sleep functions, even when limited power is available:

1. Real-time requirements: Some critical systems may have real-time requirements that cannot be met if the processor is put to sleep. For example, if a system needs to respond to external events within a certain timeframe, putting the processor to sleep could delay the response and cause the system to fail.

1. Network connectivity: The ESP8266 relies on a network connection to function, and putting the processor to sleep could disrupt that connection. If the system needs to maintain a constant connection to the network, sleep functions may not be an option.

1. Power consumption: While putting the processor to sleep can reduce power consumption, it may also cause other components of the system to consume more power. For example, maintaining a network connection or keeping a device powered on may require more power than the processor would consume while running.

1. Complexity: Implementing sleep functions can add complexity to a system, as the developer must ensure that the system can wake up and resume operation when needed. This can be a significant burden in critical systems where reliability and simplicity are key considerations.

Overall, the decision to use sleep functions or not in an ESP8266-based critical system will depend on the specific requirements and constraints of the system. Developers may need to weigh the potential benefits of reduced power consumption against the potential drawbacks of disrupted connectivity or real-time performance.

## Question 3

It sounds like the processing facility has a system in place for routing items through various stations using a conveyor belt and RFID technology. The system is controlled by an ESP-01s controller, which is connected to various input and output devices such as RFID tag readers, sensors, push buttons, and relays via an I2C bus. The controller is configured to receive messages from the RFID tag readers at 2400 baud, and to respond to rising edge interrupt signals from a GPIO expander.

There are 16 distinct stations along the conveyor, each with its own RFID tag reader, sensor, push button, and relay. Items arriving from outside the facility are processed at station 0 before being placed on the conveyor. When an item is detected in front of a station, its RFID code is scanned and, if necessary, the item is transferred off the conveyor to the station by activating the associated relay. Once the item has been processed at the station, it is placed back on the conveyor and routed to its next destination.

The system is implemented using four tasks, a binary semaphore, a global data structure, and a message queue. Task A is responsible for updating the LCD display, Task B is responsible for routing items when a station button is pressed, Task C is an interrupt-driven task that signals Task D when an item is detected, and Task D is responsible for transferring items off the conveyor.

It is important to note that the kernel is configured to allow interrupt events to preempt the running task, perform preemptive priority-based scheduling, prevent pre-emption of tasks accessing the I2C bus, and incur minimal overhead at system reset and scheduler task switch. This helps to ensure that the system runs smoothly and efficiently.

Task A is a periodic task that is responsible for updating the LCD display with the number of items in circulation on the conveyor. It does this by retrieving messages from a queue and updating a static variable called "count" based on the messages it receives. If a message comes from Task D, count is decremented, and if a message comes from Task B, count is incremented. Task A then displays the value of count on the LCD display via I2C.

Task B is a periodic task that is responsible for routing items when a station button is pressed. It does this by reading the 16-bit pushbutton GPIO expander status into a variable called "I", and then activating the RFID reader for any station whose bit in "I" is set. It retrieves the RFID code for the item and checks if it is a valid parcel code. If it is, it retrieves the RFID code for the destination station and updates the route in a global data structure called "G" for the parcel. It also updates the status in "G" for the station to "AVAILABLE" and places a message on the queue for Task A.

Task C is an aperiodic task that is triggered by an interrupt signal. When it is triggered, it sends a semaphore called "S" to Task D and disables interrupts.

Task D is a periodic task that is responsible for transferring items off the conveyor. It does this by first clearing all bits in the 16-bit transfer relay GPIO expander. If the semaphore "S" is available, it retrieves the semaphore and then reads the 16-bit sensor GPIO expander status into a variable called "I". It enables interrupts and then activates the RFID reader for any station whose bit in "I" is clear, and whose status in "G" is "AVAILABLE". If the RFID code for the item matches the route in "G" for the parcel, it sets the bit for the station in the 16-bit transfer relay GPIO expander, updates the status in "G" for the station to "BUSY", and places a message on the queue for Task A. It then deactivates the RFID reader.

### Q3 Part A

To create the precedence graph for Task B, we need to consider the execution time and dependencies of each step in the task. The precedence graph for Task B is shown below:

```text
Step:  JBa  JBb  JBc  JBd  JBe  JBf  JBg  JBh  JBi
       2    1    101  5    100  5    11   2    1

JBa -- JBb
|       |
JBb -- JBc
|       |
JBc -- JBd
|       |
JBd -- JBe
|       |
JBe -- JBf
|       |
JBf -- JBg
|       |
JBg -- JBh
|       |
JBh -- JBi
```

Next, we can calculate the Worst-Case Execution Time (WCET) for each task.

Task A:

The WCET for Task A is the sum of the execution times of all the steps in the task, plus the time it takes to retrieve a message from the queue:
WCET(A) = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 9 units
Task B:

The WCET for Task B is the sum of the execution times of all the steps in the task:
WCET(B) = 2 + 1 + 101 + 5 + 100 + 5 + 11 + 2 + 1 = 228 units
Task C:

The WCET for Task C is the sum of the execution times of all the steps in the task:
WCET(C) = 2 units
Task D:

The WCET for Task D is the sum of the execution times of all the steps in the task:
WCET(D) = 1 + 1 + 2 + 1 + 1 + 5 + 10 + 7 + 1 + 1 = 30 units
To calculate the Worst-Case System Utilization, we need to sum the WCETs of all the tasks and divide by the period of the slowest periodic task:

Utilization = (9 + 228 + 2 + 30) / 5000 = 0.069

This means that the system is utilizing 6.9% of its available processing time. This is a relatively low utilization, indicating that the system has sufficient capacity to handle the tasks it needs to perform. Therefore, the system is feasible as it has sufficient processing power to handle the tasks it needs to perform within the required time frame.

### Q3 Part B

Here is a timeline for a single hyper-period from startup, where there are no parcels on the conveyor, no sensors are triggered, and the button on station 0 is pressed at time t=2100 units, for a single parcel to be routed to station 3, which arrives at station 3 at t=7300 units:

```text
t=0: System starts up
t=0: Task A starts (period = 5000 units)
t=0: Task B starts (period = 1000 units)
t=0: Task D starts (period = 2000 units)

t=500: Task A runs
t=1000: Task B runs
t=1500: Task A runs
t=2000: Task A runs
t=2100: Button on station 0 is pressed

t=2500: Task A runs
t=3000: Task B runs
t=3500: Task A runs
t=4000: Task A runs
t=4500: Task A runs
t=5000: Task A runs
t=5500: Task A runs
t=6000: Task A runs
t=6500: Task A runs
t=7000: Task A runs
t=7100: Task B runs
t=7300: Parcel arrives at station 3

t=7500: Task A runs
t=8000: Task B runs
t=8500: Task A runs
...
```

Note that the timeline above assumes that the system is configured to allow interrupt events to preempt the running task, and that the kernel is performing preemptive priority-based scheduling. This means that if an interrupt event occurs, the running task will be interrupted and the interrupt task will be run. Also, tasks with higher priority will be given more processing time than tasks with lower priority.

In this case, we can see that when the button on station 0 is pressed at t=2100 units, Task B is preempted and runs. Task B activates the RFID reader for station 0, retrieves the RFID code for the parcel and the destination station, and updates the route in the global data structure. It then places a message on the queue for Task A and deactivates the RFID reader. When the parcel arrives at station 3 at t=7300 units, it is detected by the sensor at that station, which triggers an interrupt and causes Task C to run. Task C sends a semaphore to Task D, which is then able to run and transfer the parcel off the conveyor. Task A updates the LCD display to reflect the change in the number of items in circulation on the conveyor.

### Q3 Part C

There are several performance criteria that can be used to evaluate the different priority assignment schemes:

Response time: This refers to the amount of time it takes for a task to complete its execution. In a real-time system, it is important to have a predictable and short response time to ensure that tasks are completed within the required time frame.

Throughput: This refers to the number of tasks that can be completed within a given time period. A high throughput is desirable to ensure that the system is able to handle a large number of tasks efficiently.

Utilization: This refers to the percentage of processing time that is used by the tasks. A high utilization can lead to resource contention and reduced system performance.

Based on these criteria, I would recommend using rate-monotonic static scheduling for the system. This is because rate-monotonic scheduling assigns priorities based on the period of the tasks, with shorter period tasks having higher priority. This ensures that tasks with shorter periods have a shorter response time and higher throughput, as they are given a higher priority and are able to complete their execution more quickly. Additionally, rate-monotonic scheduling has a lower utilization compared to other schemes, which helps to reduce resource contention and improve system performance.

In the context of the conveyor system described, rate-monotonic scheduling would be a suitable choice as it would ensure that tasks with shorter periods (such as Task B and Task D) have a higher priority and are able to complete their execution more quickly. This would help to ensure that parcels are routed and transferred efficiently, and that the LCD display is updated in a timely manner.

### Q3 Part D

There are two operational issues and/or concerns with the suggested modification to the conveyor system firmware:

1. Shared use of the RX pin: By using the RX pin for both the RFID tag reader function and the emergency stop function, the system may experience conflicts or unpredictable behavior if the two functions are activated at the same time. For example, if an RFID tag reader is activated while the emergency stop function is triggered, the system may not be able to properly process the RFID data or may produce unintended results.

1. Activation of the emergency stop function: Since the emergency stop function is activated by an interrupt on the RX pin, it is possible that the function could be triggered by other sources of noise or interference on the pin. This could lead to false activations of the function, which could disrupt the operation of the conveyor system.

To address these concerns, the firmware can be modified to include additional safeguards and checks to ensure the proper operation of the system. For example, the firmware can include a mechanism to detect and ignore RFID data when the emergency stop function is activated, or a debouncing system to prevent false activations of the function due to noise or interference. Additionally, the firmware can include a confirmation prompt or other security measures to ensure that the emergency stop function is only activated intentionally by a human operator.
