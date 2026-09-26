# Work for section 04

Estimated completion time: 1 days.

Do all of your work in this directory (but not in this file) so that it can be easily reviewed by a senior member later.

You should constantly be referring back to the reading or other external sources. It is not expected of you to complete all the exercises in this unaided.

## Exercise 1: Create Two Tasks with Different Priorities

**Objective:** Understand task creation and priority scheduling.

**Steps:**

- Create Task A (high priority) and Task B (low priority).
- Task A toggles an LED every 200 ms.
- Task B toggles a different LED every 500 ms.
- Observe the behavior.

**Expected Outcome:** The higher-priority task (Task A) preempts the lower-priority task (Task B).

## Exercise 2: Implement a Simple Delay

**Objective:** Learn to use RTOS delay functions.

**Steps:**

- Create a single task that prints “Hello RTOS” every 1 second.
- Use `vTaskDelay()` (FreeRTOS) or an equivalent delay function.

**Expected Outcome:** The task prints periodically without blocking the CPU.

## Exercise 3: Mutual Exclusion with a Semaphore

**Objective:** Practice synchronization.

**Steps:**

- Create two tasks that increment a shared counter.
- Use a binary semaphore to ensure only one task accesses the counter at a time.

**Expected Outcome:** The counter increments correctly without race conditions.

## Exercise 4: Task Notification

**Objective:** Learn inter-task signaling.

**Steps:**

- Create two tasks: Producer and Consumer.
- Producer generates a number every 500 ms.
- Producer notifies Consumer using task notifications to process the number.

**Expected Outcome:** Consumer runs only when signaled by Producer.

## Exercise 5: Queue Communication

**Objective:** Understand queues for inter-task data transfer.

**Steps:**

- Create a queue to hold integers.
- Task A sends numbers 1–10 to the queue.
- Task B receives numbers from the queue and prints them.

**Expected Outcome:** Data is transferred safely between tasks.
