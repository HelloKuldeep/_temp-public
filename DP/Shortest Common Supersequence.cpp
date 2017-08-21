#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int Supersequence(string &s,string &t){
	int n=s.length(),m=t.length();	
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<m+1;j++)
			if(!i)	dp[i][j]=j;
			else if(!j)	dp[i][j]=i;
			else if(s[i-1]==t[j-1])	dp[i][j]=1+dp[i-1][j-1];
			else	dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
	return dp[n][m];
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	string s,t;
	getline(cin,s);	getline(cin,t);
	cout<<Supersequence(s,t)<<endl;
	return 0;
}
/*	//total length - LCS//
int Supersequence(string &s,string &t){
	int n=s.length(),m=t.length();	
	int dp[n+1][m+1];
	for(int i=0;i<n+1;i++)
		for(int j=0;j<m+1;j++)
			if	(!i || !j)	dp[i][j]=0;
			else if(s[i-1]==t[j-1])	dp[i][j]=1+dp[i-1][j-1];
			else	dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	return m+n-dp[n][m];
}*/
