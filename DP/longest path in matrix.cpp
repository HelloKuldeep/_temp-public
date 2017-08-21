#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int n,x;
int maxpath(int i,int j,vector<vector<int> > &a,vector<vector<int> > &dp){
	if(i>=n || i<0 || j>=n || j<0)	return 0;
	if(dp[i][j]!=-1)	return dp[i][j];
	if(i>0 && a[i][j]+1==a[i-1][j])	return dp[i][j]=1+maxpath(i-1,j,a,dp);
	if(i<n-1 && a[i][j]+1==a[i+1][j])	return dp[i][j]=1+maxpath(i+1,j,a,dp);
	if(j>0 && a[i][j]+1==a[i][j-1])	return dp[i][j]=1+maxpath(i,j-1,a,dp);
	if(j<n-1 && a[i][j]+1==a[i][j+1])	return dp[i][j]=1+maxpath(i,j+1,a,dp);
	return dp[i][j]=1;
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	S(n);	vector<vector<int> > mat(n);//int mat[n][n];
	vector<vector<int> > dp(n);//int dp[n][n];
	rep(i,0,n)	rep(j,0,n)	S(x),	mat[i].push_back(x),	dp[i].push_back(-1);
    int ans=0;
    rep(i,0,n)rep(j,0,n){
		if(dp[i][j]==-1)	maxpath(i,j,mat,dp);		//rep(ik,0,n){	XL;	rep(jk,0,n)	cout<<dp[ik][jk]<<" ";	}	XL;
		ans=max(ans,dp[i][j]);
	}
	P(ans);
	return 0;
}
