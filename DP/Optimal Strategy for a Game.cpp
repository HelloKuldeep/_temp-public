#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int n;
int game(vector<int> &a){
	int dp[n][n];
	rep(i,0,n)rep(j,0,n)	dp[i][j]=0;	//not important
	rep(t,0,n)	for(int i=0,j=t;j<n;i++,j++){
		if(i==j)	dp[i][j]=a[i];
		if(i+1==j)	dp[i][j]=max(a[i],a[j]);
		else dp[i][j] = max( a[i]+min(dp[i+2][j],dp[i+1][j-1]) , a[j]+min(dp[i][j-2],dp[i+1][j-1]) );
	}
	//rep(i,0,n){	XL; rep(j,0,n)	cout<<dp[i][j]<<" ";}	XL;XL;
	return dp[0][n-1];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	vector<int> a;
	int x,sum;	S(n);
	rep(i,0,n)	S(x),	a.push_back(x);
	P(game(a));
	return 0;
}
