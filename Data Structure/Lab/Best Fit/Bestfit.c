#include <stdio.h>
#include <stdlib.h>
void implementBestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    int occupied[blocks];
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1; 
    }
    for (int i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }
    for (int i = 0; i < processes; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                {
                    indexPlaced = j;
                } 
                else if (blockSize[j] < blockSize[indexPlaced]) 
                {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1; 
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++) 
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() 
{
    int blocks, processes;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &blocks);
    int *blockSize = (int *)malloc(blocks * sizeof(int));
    printf("Enter the sizes of the memory blocks:\n");
    for (int i = 0; i < blocks; i++) 
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    int *processSize = (int *)malloc(processes * sizeof(int));
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < processes; i++) 
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    implementBestFit(blockSize, blocks, processSize, processes);
    free(blockSize);
    free(processSize); 
    return 0;
}

