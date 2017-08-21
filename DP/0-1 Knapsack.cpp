#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int knapSack(int w,vector<int> v,vector<int> we,int n){
	int dp[w+1][n+1];
	rep(i,0,w+1) dp[i][0]=0;
	rep(i,0,n+1) dp[0][i]=0;
	rep(i,1,w+1)rep(j,1,n+1){
		dp[i][j]=dp[i][j-1];
		if(i>=we[j-1])	dp[i][j]=max(dp[i][j-1],v[j-1]+dp[i-we[j-1]][j-1]);
	}
	//if(n==0 || w==0) return 0;
	//if(we[n-1]>w)	return knapSack(w,v,we,n-1);
	//else return	max(v[n-1]+knapSack(w-we[n-1],v,we,n-1) , knapSack(w,v,we,n-1));
	return dp[w][n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	vector<int> a,b;
	int n;
	int x,w;	S(n);
	rep(i,0,n)	S(x),	a.push_back(x);
	rep(i,0,n)	S(x),	b.push_back(x);
	S(w);	//rep(i,0,n)cout<<a[i]<<" ";	XL;	rep(i,0,n)cout<<b[i]<<" ";	XL;	P(w);	XL;
	P(knapSack(w,a,b,n));
	return 0;
}
