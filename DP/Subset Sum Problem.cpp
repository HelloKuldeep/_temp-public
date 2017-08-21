#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int subsetSum(vector<int> &a,int n,int sum){
	bool dp[sum+1][n+1];
	rep(i,0,sum+1)	dp[i][0]=false;
	rep(i,0,n+1)	dp[0][i]=true;
	rep(i,1,sum+1)	rep(j,1,n+1){
		dp[i][j]=dp[i][j-1];
		if(i>=a[j-1])
			dp[i][j]|=dp[i-a[j-1]][j-1];
	}
	return dp[sum][n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	vector<int> a;
	int n,x,sum;	S(n);
	rep(i,0,n)	S(x),	a.push_back(x);
	S(sum);
	P(subsetSum(a,n,sum));
	return 0;
}
