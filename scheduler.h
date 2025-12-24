#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once
#include <vector>
#include <string>
#include "process.h"


class Scheduler {
public:
    virtual void schedule(std::vector<Process>& processes) = 0;
    virtual void displayMetrics(const std::vector<Process>& processes) = 0;
    virtual ~Scheduler() {}
};

class FCFSScheduler : public Scheduler {
public:
    void schedule(std::vector<Process>& processes) override;
    void displayMetrics(const std::vector<Process>& processes) override;
};

class SJFScheduler : public Scheduler {
public:
    void schedule(std::vector<Process>& processes) override;
    void displayMetrics(const std::vector<Process>& processes) override;
};

class RoundRobinScheduler : public Scheduler {
    int quantum;
public:
    RoundRobinScheduler(int q);
    void schedule(std::vector<Process>& processes) override;
    void displayMetrics(const std::vector<Process>& processes) override;
};

#endif
