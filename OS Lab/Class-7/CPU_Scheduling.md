# CPU Scheduling
### Why Needed?
 - Max CPU Utilization
 - Max Burst Time

# Impementations
## FCFS
> Using Java

<br>

### **Classes Architecture (Generalized)**
 - FCFS
    - `processQueue` - not important for scheduling
    - `readyQueue` 
    - `driver()`
 - Timer
 - Process
    - `id`
    - `burstTime`
    - `priority`
    - `type` - Preemptive/Non-preemptive
    - `responseTime`
    - `waitingTime`
    - `TurnAroundTime`

<br>

### **Procedure**
 - `Time:` check if process arrives.
 - `Algorithm:` Decide from ready queue which process to execute.
 - `Preemptive/Non-preemptive:` Process run
 - `All other decision making:` Post-calculation

<br>

### File Structure
- Project
    - fcfs
        - FCFS.java
        - GlobalTimer.java
        - Process.java


### **Codes**
>GlobalTimer.java
```java
package fcfs;

public class GlobalTimer {
    public int time;

    public GlobalTimer(int time) {
        this.time = time;
    }
}
```

<br>

>Process.java
```java
package fcfs;

public class Process {
    int id;
    int arrivalTime;
    int duration;
    GlobalTimer globalTimer;

    public Process(int id, int arrivalTime, int duration, GlobalTimer globalTimer) {
        this.id = id;
        this.arrivalTime = arrivalTime;
        this.duration = duration;
        this.globalTimer = globalTimer;
    }

    public void runProcess() {
        for (int i = 0; i < duration; i++) {
            System.out.println("My process ID: " + this.id);
            System.out.println("Global time: " + this.globalTimer.time);
            globalTimer.time++;
        }

        System.out.println("*****Process ID:" + this.id + " completed it's job.*****");
    }

    public int getId() {
        return id;
    }

    public int getArrivalTime() {
        return arrivalTime;
    }

    public int getDuration() {
        return duration;
    }

    public GlobalTimer getGlobalTimer() {
        return globalTimer;
    }
}
```

<br>

> FCFS.java
```java
package fcfs;

import java.util.PriorityQueue;

public class FCFS {
    static PriorityQueue<Process> processQueue = new PriorityQueue<>(10, (o1, o2) -> {
        // Always based on arrival time
        return (int) (o1.getArrivalTime() - o2.getArrivalTime());
    });
    static PriorityQueue<Process> readyQueue = new PriorityQueue<>(10, (o1, o2) -> {
        // depends on scheduling algorithm
        return (int) (o1.getArrivalTime() - o2.getArrivalTime());
    });

    static GlobalTimer globalTimer = new GlobalTimer(0);

    public static void main(String[] args) {
        processQueue.add(new Process(1, 3, 2, globalTimer));
        processQueue.add(new Process(2, 6, 2, globalTimer));
        processQueue.add(new Process(3, 1, 2, globalTimer));
        processQueue.add(new Process(4, 3, 5, globalTimer));

        while (true) {
            while (!processQueue.isEmpty() && !readyQueue.isEmpty()) {
                readyQueue.add(processQueue.poll());
            }

            if (!readyQueue.isEmpty())
                runProcessInCPU();
            else {
                System.out.println("No process in Ready Queue");
                System.out.println("Global Time: " + globalTimer.time);
                globalTimer.time++;
            }
        }
    }

    public static boolean checkIfNewProcessArrived() {
        if (!processQueue.isEmpty()) {
            if (processQueue.element().getArrivalTime() < globalTimer.time)
                return true;
        }
        return false;
    }

    public static void runProcessInCPU() {
        Process process = readyQueue.poll();
        process.runProcess();
    }
}
```