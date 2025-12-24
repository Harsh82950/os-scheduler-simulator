#include <iostream>
#include "gantt.h"

using namespace std;

void GanttChart::display(const vector<string>& timeline) {
    cout << "\nGantt Chart:\n|";
    for (const auto& p : timeline) {
        cout << " " << p << " |";
    }
    cout << "\n0";

    for (int i = 1; i <= timeline.size(); i++) {
        cout << "   " << i;
    }
    cout << endl;
}
