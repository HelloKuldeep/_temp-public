#include<bits/stdc++.h>
using namespace std;
int dice(int n,int m,int k){
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	for(int j=1;j<=m;j++)	dp[1][j]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			for(int x=1;x<=m && x<=k;x++)
				dp[i][j]+=dp[i-1][j-x];
	return dp[n][k];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int n,m,k;	scanf("%d%d%d",&n,&m,&k);
		cout<<dice(n,m,k)<<endl;
	}
	return 0;
}
/*
int dice(int n,int m,int k){	//Recursion
	if(k<1)	return 0;
	if(n==1)	return k<=m;
	int u=0;
	for(int i=1;i<=m;i++)
		u+=dice(n-1,m,k-i);
	return u;
}
*/
