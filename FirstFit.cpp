#include<stdio.h>
int main(){
	int bsize[]={30,5,10};
	int psize[]={10,6,9};
	int numB=sizeof(bsize)/sizeof(bsize[0]);
	int numP=sizeof(psize)/sizeof(psize[0]);
	
	int allocations[numP];
	int occupied[numB];
	
	for(int i=0;i<numP;i++){
		allocations[i]=-1;
	}
	
	for(int i=0;i<numB;i++){
		occupied[i]=0;
	}
	
	for(int i=0;i<numP;i++){
		for(int j=0;j<numB;j++){
			if(occupied[j]==0 && bsize[j]>=psize[i]){
				allocations[i]=j;
				occupied[j]=1;
				break;
			}
		}
	}
	
	printf("\nProcessNumber\tProcessSize\tBlockNumber\n");
	for(int i=0;i<numP;i++){
		printf("%d\t\t\t%d\t\t\t", i+1,psize[i]);
		if(allocations[i]!=-1){
			printf("%d\n", allocations[i]+1);
		}
		else{
			printf("not allowed!");
		}
	}
	
}
