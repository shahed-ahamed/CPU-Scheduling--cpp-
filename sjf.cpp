#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int pid[20], bt[20], wt[20], tat[20];

    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        pid[i] = i+1;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    float total_wt = 0, total_tat = 0;
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << bt[i] << "\t\t" 
             << wt[i] << "\t\t" << tat[i] << endl;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "Average Waiting Time = " << (total_wt / n) << endl;
    cout << "Average Turnaround Time = " << (total_tat / n) << endl;

    return 0;
}
