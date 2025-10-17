#include <iostream>
using namespace std;

int main() {
    int n, i, j, time = 0, smallest;
    float avg_wt = 0, avg_tat = 0;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[10], bt[10], temp[10], ct[10], tat[10], wt[10];
    for (i = 0; i < n; i++) {
        cout << "Arrival time of P" << i+1 << ": ";
        cin >> at[i];
        cout << "Burst time of P" << i+1 << ": ";
        cin >> bt[i];
        temp[i] = bt[i];
    }

    bt[9] = 9999;
    int count = 0;
    for (time = 0; count != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] < bt[smallest] && bt[i] > 0)
                smallest = i;
        }
        bt[smallest]--;
        if (bt[smallest] == 0) {
            count++;
            ct[smallest] = time + 1;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - temp[smallest];
            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }

    cout << "\nP#\tAT\tBT\tCT\tTAT\tWT\n";
    for (i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t" << at[i] << "\t" << temp[i] << "\t" 
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << avg_wt/n;
    cout << "\nAverage Turnaround Time = " << avg_tat/n;

    return 0;
}
