#include<bits/stdc++.h>
using namespace std;
int Egg(int n,int f){
	int dp[n+1][f+1];
	for(int j=0;j<f+1;j++)	dp[1][j]=j;
	for(int i=0;i<n+1;i++)	dp[i][0]=0;
	for(int i=2;i<n+1;i++)
		for(int j=1;j<f+1;j++){
			dp[i][j]=INT_MAX;
			for(int k=1;k<=j;k++)	dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
		}
	return dp[n][f];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int n,f; cin>>n>>f;
		cout<<Egg(n,f)<<endl;
	}
	return 0;
}
/*
int Egg(int n,int f){
	if(f==0 || f==1)	return f;
	if(n==1)	return f;
	int r,u=INT_MAX;
	for(int k=1;k<=f;k++){
		r=max(Egg(n-1,k-1),Egg(n,f-k));
		if(u>r)	u=r;
	}
	return u+1;
}
*/
