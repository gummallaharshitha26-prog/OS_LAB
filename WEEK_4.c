#include <stdio.h>
void firstFit(int block[], int b, int process[], int p)
{
 int allocation[20];
 int i, j;
 for(i = 0; i < p; i++)
 allocation[i] = -1;
 for(i = 0; i < p; i++)
 {
 for(j = 0; j < b; j++)
 {
 if(block[j] >= process[i])
 {
 allocation[i] = j;
 block[j] -= process[i];
 break;
 }
 }
 }
 printf("\n--- FIRST FIT ---\n");
 for(i = 0; i < p; i++)
 {
 if(allocation[i] != -1)
 printf("Process %d (%d KB) -> Partition %d\n",
 i + 1, process[i], allocation[i] + 1);
 else
 printf("Process %d (%d KB) -> Not Allocated\n",
 i + 1, process[i]);
 }
}
void worstFit(int block[], int b, int process[], int p)
{
 int allocation[20];
 int i, j, worst;
 for(i = 0; i < p; i++)
 allocation[i] = -1;
 for(i = 0; i < p; i++)
 {
 worst = -1;
 for(j = 0; j < b; j++)
 {
 if(block[j] >= process[i])
 {
 if(worst == -1 || block[j] > block[worst])
 worst = j;
 }
 }
 if(worst != -1)
 {
 allocation[i] = worst;
 block[worst] -= process[i];
 }
 }
 printf("\n--- WORST FIT ---\n");
 for(i = 0; i < p; i++)
 {
 if(allocation[i] != -1)
 printf("Process %d (%d KB) -> Partition %d\n",
 i + 1, process[i], allocation[i] + 1);
 else
 printf("Process %d (%d KB) -> Not Allocated\n",
 i + 1, process[i]);
 }
}
void bestFit(int block[], int b, int process[], int p)
{
 int allocation[20];
 int i, j, best;

for(i = 0; i < p; i++)
 allocation[i] = -1;
 for(i = 0; i < p; i++)
 {
 best = -1;
 for(j = 0; j < b; j++)
 {
 if(block[j] >= process[i])
 {
 if(best == -1 || block[j] < block[best])
 best = j;
 }
 }
 if(best != -1)
 {
 allocation[i] = best;
 block[best] -= process[i];
 }
 }
 printf("\n--- BEST FIT ---\n");
 for(i = 0; i < p; i++)
 {
 if(allocation[i] != -1)
 printf("Process %d (%d KB) -> Partition %d\n",
 i + 1, process[i], allocation[i] + 1);
 else
 printf("Process %d (%d KB) -> Not Allocated\n",
 i + 1, process[i]);
 }
}
int main()
{
 int block[20], process[20];
 int block1[20], block2[20], block3[20];
 int b, p, i;
 printf("=========================================\n");
 printf(" FIXED PARTITION MEMORY ALLOCATION\n");
 printf("=========================================\n");
 printf("Enter number of partitions: ");
 scanf("%d", &b);
 printf("Enter partition sizes:\n");
 for(i = 0; i < b; i++)
 {
 printf("Partition %d: ", i + 1);
 scanf("%d", &block[i]);
 }
 printf("\nEnter number of processes: ");
 scanf("%d", &p);
 printf("Enter process sizes:\n");
 for(i = 0; i < p; i++)
 {
 printf("Process %d: ", i + 1);
 scanf("%d", &process[i]);
 }
 /* Make separate copies for each method */
 for(i = 0; i < b; i++)
 {
 block1[i] = block[i];
 block2[i] = block[i];
 block3[i] = block[i];
 }
 firstFit(block1, b, process, p);
 worstFit(block2, b, process, p);
 bestFit(block3, b, process, p);
 return 0;
}
