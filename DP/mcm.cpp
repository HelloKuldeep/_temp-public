#include<bits/stdc++.h>
using namespace std;
int mcm(vector<int> &a,int n){
	int dp[n-1][n-1];
	for(int g=0;g<n-1;g++)
	for(int i=0,j=g;j<n-1;i++,j++){
		if(i==j)	dp[i][j]=0;
		else	dp[i][j]=min(dp[i][j-1]+a[i]*a[j]*a[j+1],dp[i+1][j]+a[i]*a[i+1]*a[j+1]);
	}	//rep(i,0,n){XL;rep(j,0,n)cout<<T[i][j]<<" ";}XL;rep(i,0,n){XL;rep(j,0,n)cout<<F[i][j]<<" ";}XL;
	return dp[0][n-2];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n,x;	scanf("%d",&n);
	vector<int> a;
	for(int i=0;i<n;i++)	scanf("%d",&x),	a.push_back(x);	//rep(i,0,n)cout<<a[i]<<" ";	XL;	rep(i,0,n-1)cout<<b[i]<<" ";	XL;
	cout<<mcm(a,n)<<endl;
	return 0;
}
