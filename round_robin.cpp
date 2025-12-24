#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

#include "scheduler.h"
#include "gantt.h"

using namespace std;

// IMPLEMENTATION ONLY — NO class definition here

RoundRobinScheduler::RoundRobinScheduler(int q) : quantum(q) {}

void RoundRobinScheduler::schedule(vector<Process>& processes) {
    queue<int> q;
    vector<string> timeline;
    int currentTime = 0;
    int n = processes.size();
    vector<bool> inQueue(n, false);
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime &&
                !inQueue[i] && processes[i].remainingTime > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (q.empty()) {
            timeline.push_back("IDLE");
            currentTime++;
            continue;
        }

        int idx = q.front();
        q.pop();

        int execTime = min(quantum, processes[idx].remainingTime);

        for (int t = 0; t < execTime; t++) {
            timeline.push_back(processes[idx].pid);
            currentTime++;
        }

        processes[idx].remainingTime -= execTime;

        if (processes[idx].remainingTime == 0) {
            processes[idx].completionTime = currentTime;
            processes[idx].turnaroundTime =
                currentTime - processes[idx].arrivalTime;
            processes[idx].waitingTime =
                processes[idx].turnaroundTime - processes[idx].burstTime;
            completed++;
        } else {
            q.push(idx);
        }
    }

    GanttChart::display(timeline);
    displayMetrics(processes);
}

void RoundRobinScheduler::displayMetrics(const vector<Process>& processes) {
    cout << "\nPID\tWT\tTAT\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }
}

