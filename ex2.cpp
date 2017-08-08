#include<bits/stdc++.h>
using namespace std; 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int n;
int lcs(int a[]){
	int ans[n][n];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<m;i++)
		for(int j=0;j<l;j++)
			if(a[j]==a[i])	ans[i][j]=a[i];
			else	ans[i][j]=1+min(ans[i][j-1],min(ans[i-1][j],ans[i-1][j-1]));
	return ans[m][l];
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int u;	S(u);	//cin.ignore();
	while(u--){
	    S(n);
	    int a[n];
	    rep(i,0,n)	S(a[i]);
		P(lcs(a));
	}
	return 0;
}
