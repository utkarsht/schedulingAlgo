#include <stdio.h>                                
int main()
{
 int n, *p,*w,qu;
 int sum=0;
 system("clear");
 printf("Enter the number of processes:");
 scanf("%d", &n);
 p=(int*)malloc(n*sizeof(int));
 w=(int*)calloc(n,sizeof(int));
 for(int i=0; i<n; i++)
 {
  printf("Burst time for process %d:", i+1);
  scanf("%d", &p[i]);
 }
 printf("Enter the time Quantum:");
 scanf("%d", &qu);
 system("clear");
 sum=0;
 int ptr=0,cnt=0,tmp;
          sum=0;
    while(cnt!=n)
    {
          if(p[ptr]==0)
          {
                  cnt++;     
                  ptr=(ptr+1)%n;
                  continue;
                  }
          if(p[ptr]>=qu){
          tmp=qu;               
          p[ptr]-=qu;
          }
          else
          {
              tmp=p[ptr];
              p[ptr]=0;
              }
            for(int i=0; i<n; i++)
            {
                    if(i!=ptr && p[i]!=0)
                    w[i]+=tmp;
                    }
                ptr=(ptr+1)%n;
                }                                                  
 printf("\t\tProcess\t\tWaiting Time\n");
 for(int i=0; i<n; i++){
 printf("\t\t%d\t\t%d\n", i+1, w[i]);
 sum+=w[i];
 }
 printf("Average waiting time:%d sec\n", sum/n);
 return 0;
}
