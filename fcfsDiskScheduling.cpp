#include<stdio.h>
#include<math.h>

int size=8;
void FCFS(int arr[], int head){
    int seekC=0;
    int currC,dist;
    for(int i=0;i<size;i++){
        currC=arr[i];
        dist=fabs(head-currC);
        seekC+=dist;
        head=currC;
    }
    
    printf("total number of seek operation: %d", seekC);
    printf("\nseek sequence\n");
    
    for(int i=0;i<size;i++){
        printf("%d\n", arr[i]);
    }
    
}

int main(){
    int arr[8]={176, 79, 34, 60, 92, 11, 41, 114};
    int head=50;
    FCFS(arr,head);
    return 0;
}
