#include<bits/stdc++.h>
using namespace std;
int n;
int stk(vector<int> &a,int k){
    int dp[k+1][n+1];
    for(int i=0;i<=k;i++)	dp[i][0]=0;
    for(int j=0;j<=n;j++)	dp[0][j]=0;
    for(int i=1;i<=k;i++)for(int j=1;j<n;j++){
    	int ans = INT_MIN;
        for (int m=0;m<j;m++)	ans=max(ans,a[j]-a[m]+dp[i-1][m]);
            dp[i][j]=max(dp[i][j-1],ans);
    }
    return dp[k][n-1];
}
int main()
{
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int x,k;	scanf("%d%d",&k,&n);
		vector<int> a;
		for(int i=0;i<n;i++)	scanf("%d",&x),	a.push_back(x);	//rep(i,0,n)cout<<a[i]<<" ";	XL;	rep(i,0,n-1)cout<<b[i]<<" ";	XL;
		cout<<stk(a,k)<<endl;
	}
}
