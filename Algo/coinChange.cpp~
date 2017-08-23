#include<bits/stdc++.h>	
using namespace std;
int coin(vector<int> &a,int n,int k){	//On-space
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=0;i<k;i++)
		for(int j=a[i];j<=n;j++)
			dp[j]+=dp[j-a[i]];
	//for(int i=0;i<k+1;i++){cout<<endl;for(int j=0;j<n+1;j++)cout<<dp[i][j]<<" ";}
	return dp[n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int x,n,k;	scanf("%d%d",&k,&n);
		vector<int> a;
		for(int i=0;i<k;i++)	scanf("%d",&x),	a.push_back(x);	//for(int i=0;i<n;i++)cout<<a[i]<<" ";	cout<<endl;
		cout<<coin(a,k,n)<<endl;
	}
}
/*int coin(vector<int> &a,int n,int k){	//On2
	int dp[k+1][n+1];
	for(int i=0;i<n+1;i++) dp[0][i]=0;
	for(int i=0;i<k+1;i++) dp[i][0]=1;
	for(int i=1;i<k+1;i++)for(int j=1;j<n+1;j++)
		(j>=a[i-1])?dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]]:dp[i][j]=dp[i-1][j];
	//for(int i=0;i<k+1;i++){cout<<endl;for(int j=0;j<n+1;j++)cout<<dp[i][j]<<" ";}
	return dp[k][n];
}*/
/*int coin(vector<int> &a,int n,int k){	//Recursion
	if(!n)	return 1;
	if(n<0)	return 0;
	if(k<=0 && n>=1)	return 0;
	return coin(a,n,k-1)+coin(a,n-a[k-1],k);
}*/
