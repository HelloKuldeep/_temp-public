#include<bits/stdc++.h>
using namespace std; 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int lcs(string a,string b){
	int l=a.length(),m=b.length();//	cout<<"t";
	int ans[m+1][l+1];
	rep(i,0,l+1)	ans[0][i]=0;
	rep(i,0,m+1)	ans[i][0]=0;
	for(int i=1;i<m+1;i++)
		for(int j=1;j<l+1;j++)
			if(a[j-1]==b[i-1])	ans[i][j]=ans[i-1][j-1]+1;
			else	ans[i][j]=max(ans[i][j-1],ans[i-1][j]);
	return ans[m][l];
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int u;	S(u);
	while(u--){
	    int x,y;    S2(x,y);
	    cin.ignore();
		string a,b;
		getline(cin,a);
		getline(cin,b);
		P(lcs(a,b));
	}
	return 0;
}
