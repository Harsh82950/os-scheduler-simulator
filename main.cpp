#include <iostream>
#include <vector>

#include "process.h"
#include "scheduler.h"
#include "gantt.h"


// Forward declarations
class FCFSScheduler;
class SJFScheduler;
class RoundRobinScheduler;

using namespace std;

void displayMenu() {
    cout << "\nSelect Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF (Non-Preemptive)\n";
    cout << "3. Round Robin\n";
    cout << "Enter choice: ";
}

int main() {
    int n;
    cout << "==== OS Scheduler Simulator ====\n";
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes;

    cout << "Enter details (Arrival Time Burst Time Priority)\n";
    for (int i = 0; i < n; i++) {
        int at, bt, pr;
        string pid = "P" + to_string(i + 1);

        cout << pid << ": ";
        cin >> at >> bt >> pr;

        processes.emplace_back(pid, at, bt, pr);
    }

    displayMenu();
    int choice;
    cin >> choice;

    Scheduler* scheduler = nullptr;

    if (choice == 1) {
        scheduler = new FCFSScheduler();
    } else if (choice == 2) {
        scheduler = new SJFScheduler();
    } else if (choice == 3) {
        int quantum;
        cout << "Enter Time Quantum: ";
        cin >> quantum;
        scheduler = new RoundRobinScheduler(quantum);
    } else {
        cout << "Invalid choice.\n";
        return 0;
    }

    scheduler->schedule(processes);
    delete scheduler;

    return 0;
}
