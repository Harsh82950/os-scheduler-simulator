
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "scheduler.h"
#include "gantt.h"

using namespace std;

// IMPLEMENTATION ONLY — NO class definition here

void FCFSScheduler::schedule(vector<Process>& processes) {
    // Sort by arrival time
    sort(processes.begin(), processes.end(),
         [](const Process& a, const Process& b) {
             return a.arrivalTime < b.arrivalTime;
         });

    vector<string> timeline;
    int currentTime = 0;

    for (auto& p : processes) {
        // CPU idle time
        while (currentTime < p.arrivalTime) {
            timeline.push_back("IDLE");
            currentTime++;
        }

        // Execute process
        for (int i = 0; i < p.burstTime; i++) {
            timeline.push_back(p.pid);
            currentTime++;
        }

        p.completionTime = currentTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }

    GanttChart::display(timeline);
    displayMetrics(processes);
}

void FCFSScheduler::displayMetrics(const vector<Process>& processes) {
    cout << "\nProcess Metrics:\n";
    cout << "PID\tWT\tTAT\n";

    for (const auto& p : processes) {
        cout << p.pid << "\t"
             << p.waitingTime << "\t"
             << p.turnaroundTime << endl;
    }
}
