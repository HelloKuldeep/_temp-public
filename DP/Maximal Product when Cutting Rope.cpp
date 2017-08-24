#include<bits/stdc++.h>
using namespace std;
int ropeCutP(int n){
	int dp[n+1],u;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i/2;j++)
			u=max(max(u,(i-j)*j),dp[i-j]*j);
		dp[i]=u;
	}
	return dp[n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int n;	scanf("%d",&n);
		cout<<ropeCutP(n)<<endl;
	}
	return 0;
}
/*
int ropeCutP(int n){	//Recursion
	int u=0;
	if(n<=0)	return 0;
	for(int i=1;i<n;i++)
		u=max(max(u,(n-i)*i),rodCutP(n-i)*i);
	return u;
}
*/
