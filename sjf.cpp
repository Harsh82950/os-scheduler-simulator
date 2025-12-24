#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>

#include "scheduler.h"
#include "gantt.h"

using namespace std;

// IMPLEMENTATION ONLY — NO class definition here

void SJFScheduler::schedule(vector<Process>& processes) {
    int currentTime = 0, completed = 0;
    int n = processes.size();
    vector<bool> done(n, false);
    vector<string> timeline;

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && processes[i].arrivalTime <= currentTime &&
                processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                idx = i;
            }
        }

        if (idx == -1) {
            timeline.push_back("IDLE");
            currentTime++;
            continue;
        }

        for (int t = 0; t < processes[idx].burstTime; t++) {
            timeline.push_back(processes[idx].pid);
            currentTime++;
        }

        processes[idx].completionTime = currentTime;
        processes[idx].turnaroundTime =
            currentTime - processes[idx].arrivalTime;
        processes[idx].waitingTime =
            processes[idx].turnaroundTime - processes[idx].burstTime;

        done[idx] = true;
        completed++;
    }

    GanttChart::display(timeline);
    displayMetrics(processes);
}

void SJFScheduler::displayMetrics(const vector<Process>& processes) {
    cout << "\nPID\tWT\tTAT\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }
}
