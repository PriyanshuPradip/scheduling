#include<iostream> 
using namespace std; 
int process[10][6]; 
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void arrangeArrival(int num, int process[][6]) 
{ 
    for(int i=0; i<num; i++) 
    { 
        for(int j=0; j<num-i-1; j++) 
        { 
            if(process[j][1] > process[j+1][1]) 
            { 
                for(int k=0; k<5; k++) 
                { 
                    swap(process[j][k], process[j+1][k]); 
                } 
            } 
        } 
    } 
} 
  
void completionTime(int num, int process[][6]) 
{ 
    int temp, val; 
    process[0][3] = process[0][1] + process[0][2]; 
    process[0][5] = process[0][3] - process[0][1]; 
    process[0][4] = process[0][5] - process[0][2]; 
      
    for(int i=1; i<num; i++) 
    { 
        temp = process[i-1][3]; 
        int low = process[i][2]; 
        for(int j=i; j<num; j++) 
        { 
            if(temp >= process[j][1] && low >= process[j][2]) 
            { 
                low = process[j][2]; 
                val = j; 
            } 
        } 
        process[val][3] = temp + process[val][2]; 
        process[val][5] = process[val][3] - process[val][1]; 
        process[val][4] = process[val][5] - process[val][2]; 
        for(int k=0; k<6; k++) 
        { 
            swap(process[val][k], process[i][k]); 
        } 
    } 
} 
  
int main() 
{ 
    int num, temp, i =0; 
    float turn_total=0.0, wait_total=0.0;
    cout<<"************************************************\n";  
    cout<<"               PROCESS DETAILS              \n"; 
    cout<<"************************************************\n\n";
    
    cout<<"Enter number of Process: "; 
    cin>>num; 
    
    while(i<num) 
    { 
    	process[i][0]= i+1; 
        cout<<"-----------------------------------\n";
        cout<<" Process Id: "<<process[i][0]<<" \n"; 
        cout<<"-----------------------------------\n";
        cout<<"Enter Arrival Time: "; 
        cin>>process[i][1]; 
        cout<<"Enter Burst Time: "; 
        cin>>process[i][2]; 
        if ( process[i][1] != 0)
        	i++;
        else 
        	num=num-1;
    } 
      
    cout<<"PROCESSES ENTERED FOR SHORTEST JOB FIRST \n"; 
    cout<<"Process ID || Arrival Time || Burst Time\n"; 
    cout<<"***********************************************\n";
    for(int i=0; i<num; i++) 
    { 
        cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\n"; 
    } 
      
    arrangeArrival(num, process); 
    completionTime(num, process); 
    cout<<"Scheduling Algorithm ^^^^^^ SHORTEST JOB FIRST ^^^^^^\n"; 
    cout<<"Process ID || Arrival Time || Burst Time || Waiting Time || Turnaround Time\n"; 
    cout<<"**********************************************************************************\n";
    for(int i=0; i<num; i++) 
    {   
        cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\t\t"<<process[i][4]<<"\t\t"<<process[i][5]<<"\n"; 
        wait_total = wait_total+process[i][4];
        turn_total = turn_total+process[i][5];
    } 
    
    float wait_avg=wait_total/num;
	float turn_avg=turn_total/num;
	cout<<"\n                      Average Turn Around Time    : "<<turn_avg<<"\n";
    cout<<"\n                      Average Waiting Time        : "<<wait_avg<<"\n";
    
    
    for(int i=0; i<num; i++) 
    { 
        process[i][2]+2; 
    }     
    arrangeArrival(num, process); 
    completionTime(num, process); 
    cout<<" \n\n                                     If checking and arranging time is 2 seconds\n"; 
    cout<<"Process ID || Arrival Time || Burst Time || Waiting Time || Turnaround Time\n"; 
    cout<<"**********************************************************************************\n";
    for(int i=0; i<num; i++) 
    { 
        cout<<process[i][0]<<"\t\t"<<process[i][1]<<"\t\t"<<process[i][2]<<"\t\t"<<process[i][4]<<"\t\t"<<process[i][5]<<"\n"; 
        wait_total = wait_total+process[i][4];
        turn_total = turn_total+process[i][5];
    } 
    
    wait_avg=wait_total/num;
	turn_avg=turn_total/num;
	cout<<"\n                      Average Turn Around Time    : "<<turn_avg<<"\n";
    cout<<"\n                      Average Waiting Time        : "<<wait_avg<<"\n";
	
} 
