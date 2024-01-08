// C++ program to demonstrate SSTF Disk Scheduling algorithm
# include<stdio.h>
#include<stdlib.h>
int main()
{
 int i,TotalHeadMoment=0,count=0;

 // The number of requests
 int n = 8;
 //Enter the requests sequence
 int ReadyQueue[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
 //Enter the initial head position
 int initial = 50;
 printf("Head sequence movement is: %d\n",initial);

 while(count!=n)
 {
 int min=1000,diff,index;
 for(i=0;i<n;i++)
 {
 diff=abs(ReadyQueue[i]-initial);
 if(min>diff)
 {
 min=diff;
 index=i;
 }
 
 }
 TotalHeadMoment=TotalHeadMoment+min;
 initial=ReadyQueue[index];
 printf("Head sequence movement is: %d\n",initial);

 ReadyQueue[index]=1000;
 count++;
 }
 printf("Total head movement is: %d",TotalHeadMoment);
 
 return 0;
 }
