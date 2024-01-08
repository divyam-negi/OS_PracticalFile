#include <stdio.h>

int main() {
    int blockSize[] = {100, 50, 30, 120, 35};
    int processSize[] = {40, 10, 30, 60};
    int numBlocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int numProcesses = sizeof(processSize) / sizeof(processSize[0]);

    int allocations[numProcesses];
    int occupiedBlocks[numBlocks];

    // Initialize allocation and occupiedBlocks arrays
    for (int i = 0; i < numProcesses; i++) {
        allocations[i] = -1;
    }

    for (int i = 0; i < numBlocks; i++) {
        occupiedBlocks[i] = 0;
    }

    // Best Fit Allocation Algorithm
    for (int i = 0; i < numProcesses; i++) {
        int indexPlaced = -1;
        for (int j = 0; j < numBlocks; j++) {
            if (occupiedBlocks[j] == 0 && blockSize[j] >= processSize[i]) {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
        // If a block is found for the process
        if (indexPlaced != -1) {
            allocations[i] = indexPlaced;
            occupiedBlocks[indexPlaced] = 1;
        }
    }

    // Display the allocation results
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocations[i] != -1)
            printf("%d\n", allocations[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

