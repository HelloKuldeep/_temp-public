/*
5
4
1 2 3 4
5
3 10 1 2 5
7
12 48 28 21 67 75 85
8
245 108 162 400 274 358 366 166
10
866 919 840 944 761 895 701 912 848 799

#1 20
#2 100
#3 16057
#4 561630
#5 6455522

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("input.txt","r",stdin);
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int nums[n];
		for(i=0;i<n;i++)
		{
			cin>>nums[i];
		}
		int dp[n][n];
		int val;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			int prev=(i-1<0)?1:nums[i-1];
			int next=(i+1==n)?1:nums[i+1];
			dp[i][i]=prev*next;
		}
		for(int l=2;l<=n;l++)
		{
			for(i=0;i<n-l+1;i++)
			{
				j=i+l-1;
				for(k=i;k<=j;k++)
				{
					if(l==n)
					{
						val=nums[k]+(k-1<0?0:dp[i][k-1])+(k+1==n?0:dp[k+1][j]);
					}
					else
					{
						int prev,next;
						prev=(i-1<0)?1:nums[i-1];
						next=(j+1==n)?1:nums[j+1];
						val=prev*next+(k==i?0:dp[i][k-1])+(k==j?0:dp[k+1][j]);
					}
					dp[i][j]=max(dp[i][j],val);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
