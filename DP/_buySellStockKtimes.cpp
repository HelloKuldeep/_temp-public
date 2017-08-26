#include<bits/stdc++.h>
using namespace std;
int n;
int stock(vector<int> &a,int k){
	int dp[k+1][n];
	for(int i=0;i<n;i++)	dp[0][i]=0;
	for(int i=0;i<k+1;i++)	dp[i][0]=0;
	for(int i=1;i<k+1;i++){
		int mdif=INT_MIN;
		for(int j=1;j<n;j++){
			mdif=max(mdif,dp[i-1][j-1]-a[j-1]);
			dp[i][j]=max(dp[i][j-1],a[j]+mdif);
		}
	}//for(int i=0;i<=k;i++){cout<<endl;for(int j=0;j<=n;j++)cout<<dp[i][j]<<" ";}
	return dp[k][n-1];	//last but second in row
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int x;	scanf("%d",&n);
		vector<int> a;
		for(int i=1;i<=n;i++)	scanf("%d",&x),	a.push_back(x);
		int k;	scanf("%d",&k);
		cout<<stock(a,k)<<endl;
	}
	return 0;
}
