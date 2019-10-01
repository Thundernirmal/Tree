
#include<stdio.h>
int dp[1111];
int a[1111];int b[1111];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif
  int T,N;
  scanf("%d",&T);
  while(T--)
  {
     scanf("%d",&N);
     for (int i=0;i<N;i++)
     {
         scanf("%d",a[i]);
     }
     for (int i=0;i<N;i++)
     {
         scanf("%d",b[i]);
     }
     int maxi=0;
      for(int i=0;i<N;i++)
      {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
           if(a[i]>=a[j] && dp[i]<dp[j]+1)
           {dp[i]=dp[j]+1;}
        }
        maxi=max(dp[i],maxi);
      }
      printf("%d\n",maxi);
  }
}
