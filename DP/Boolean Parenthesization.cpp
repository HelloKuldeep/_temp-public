#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int Parenthesization(vector<char> S,vector<char> O,int n){
	int T[n][n],F[n][n];
	rep(i,0,n)
		T[i][i]=(S[i]=='T')?1:0,
		F[i][i]=(S[i]=='F')?1:0;
	//rep(i,0,n){XL;rep(j,0,n)cout<<T[i][j]<<" ";}XL;rep(i,0,n){XL;rep(j,0,n)cout<<F[i][j]<<" ";}XL;
	for(int gap=1;gap<n;gap++){
		for(int i=0,j=gap;j<n;++i,++j){
			T[i][j]=F[i][j]=0;
			for(int	g=0;g<gap;g++){
				int k=i+g;
				int	tik=T[i][k]+F[i][k];
				int tkj=T[k+1][j]+F[k+1][j];
				if(O[k]=='&')	T[i][j]+=T[i][k]*T[k+1][j],	F[i][j]+=tik*tkj-T[i][k]*T[k+1][j];
				if(O[k]=='|')	T[i][j]+=tik*tkj-F[i][k]*F[k+1][j],	F[i][j]+=F[i][k]*F[k+1][j];
				if(O[k]=='^')	T[i][j]+=T[i][k]*F[k+1][j]+F[i][k]*T[k+1][j],	F[i][j]+=T[i][k]*T[k+1][j]+F[i][k]*F[k+1][j];
			}
		}
	}	//rep(i,0,n){XL;rep(j,0,n)cout<<T[i][j]<<" ";}XL;rep(i,0,n){XL;rep(j,0,n)cout<<F[i][j]<<" ";}XL;
	return T[0][n-1];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	vector<char> a,b;
	int n;	char x;	S(n);
	rep(i,0,n)	cin>>x,	a.push_back(x);
	rep(i,0,n-1)	cin>>x,	b.push_back(x);	//rep(i,0,n)cout<<a[i]<<" ";	XL;	rep(i,0,n-1)cout<<b[i]<<" ";	XL;
	cout<<Parenthesization(a,b,n)<<endl;
	return 0;
}
