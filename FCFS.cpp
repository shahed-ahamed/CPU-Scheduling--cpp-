#include <iostream>
using namespace std;

int main(){
    int n,bt[20],wt[20],tat[20],i;
    float awt=0,atat=0;
    cout<<"Enter number of processes: ";
    cin>>n;

    for(i=0;i<n;i++){
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>bt[i];
    }

    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }

    for(i=0;i<n;i++){
        tat[i]= wt[i]+bt[i];
        awt+=wt[i];
        atat+=tat[i];

    }

    awt/=n;
    atat/=n;
    cout<<"\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++){
        cout<<"p"<<i+1<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
    }

    cout<<"\nAverage Waiting Time: "<<awt;
    cout<<"\nAverage Turnaround Time: "<<atat;
    return 0;
}
