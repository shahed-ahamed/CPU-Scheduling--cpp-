
#include <iostream>
using namespace std;


void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; 
    while (1)
    {
        bool done = true;

       
        for (int i = 0; i < n; i++)
        {
            
            if (rem_bt[i] > 0)
            {
                done = false;

               

                
          
     
