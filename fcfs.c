#include <stdio.h>
int main()
{
 int n, *p,*w;
 int sum=0;
 system("clear");
 printf("Enter the number of processes:");
 scanf("%d", &n);
 p=(int*)malloc(n*sizeof(int));
 w=(int*)malloc(n*sizeof(int));
 for(int i=0; i<n; i++)
 {
  printf("Burst time for process %d:", i+1);
  scanf("%d", &p[i]);
  w[i]=sum;
  sum+=p[i];
 }
 system("clear");
 sum=0;
 printf("\t\tProcess\t\tWaiting Time\n");
 for(int i=0; i<n; i++){
 printf("\t\t%d\t\t%d\n", i+1, w[i]);
 sum+=w[i];
 }
 printf("Average waiting time:%d sec\n", sum/n);
 return 0;
}
