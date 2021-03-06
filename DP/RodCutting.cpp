#include<bits/stdc++.h>
using namespace std;
int n;
int part(vector<int> &a){
	int dp[n+1][n+2];
	for(int i=0;i<n+1;i++)	dp[i][0]=0;
	for(int i=0;i<n+2;i++)	dp[0][i]=0;
	for(int i=1;i<n+1;i++)for(int j=1;j<n+2;j++){
		if(i>j)	dp[i][j]=dp[i-1][j];
		else	dp[i][j]=max(dp[i][j-i]+a[i-1],dp[i-1][j]);
	}	//for(int i=0;i<n+1;i++){cout<<endl;for(int j=0;j<n+2;j++)cout<<dp[i][j]<<" ";}
	return dp[n][n+1];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int x,sum=0;	scanf("%d",&n);
	vector<int> a;
	for(int i=0;i<n;i++)	scanf("%d",&x),	a.push_back(x);	for(int i=0;i<n;i++)cout<<a[i]<<" ";	cout<<endl;
	cout<<part(a)<<endl;
	return 0;
}
