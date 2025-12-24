#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
public:
    std::string pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;

    int completionTime;
    int waitingTime;
    int turnaroundTime;

    Process(std::string id, int at, int bt, int pr)
        : pid(id),
          arrivalTime(at),
          burstTime(bt),
          remainingTime(bt),
          priority(pr),
          completionTime(0),
          waitingTime(0),
          turnaroundTime(0) {}
};

#endif
