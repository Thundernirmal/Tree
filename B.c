
#include<stdio.h>
int dp[1111];
int a[1111];int b[1111];

void insertionSort(int A[],int B[], int size) 
{ 
int i, key, j,key2; 
for (i = 1; i < size; i++) 
{ 
	key = A[i]; key2=B[i];
	j = i-1;
	while (j >= 0 && A[j] > key) 
	{ 
		A[j+1] = A[j]; 
		B[j+1]=[j];
		j = j-1; 
	} 
	A[j+1] = key; 
	B[j+1] = key2;
} 
}
int max(int a, int b){
 if(a > b)
return a;
return b;
}												
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
     insertionSort(b,a,N);
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
