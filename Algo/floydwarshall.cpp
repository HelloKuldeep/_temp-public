#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define MAX 100001
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int w,n,a,b;	long e;	S(n);	scanf("%ld",&e);
	int vect[n][n],dist[n][n];	//dist to store shortest path
	rep(i,0,n)	rep(j,0,n){ if(i==j)	vect[i][j]=0;	else	vect[i][j]=MAX;	dist[i][j]=-1; }
	for(long i=0;i<e;i++){
		S2(a,b);	S(w);
		vect[a][b]=w;	//vect[b][a]=w;	//directed
		dist[a][b]=a;	//dist[b][a]=b;	//directed
	}
	rep(k,0,n)rep(i,0,n)rep(j,0,n)	if(vect[i][j]>vect[i][k]+vect[k][j]){
		vect[i][j]=vect[i][k]+vect[k][j];
		dist[i][j]=dist[k][j];
	}
	rep(i,0,n){
		rep(j,0,n)	P(vect[i][j]);	XL;
	}
	return 0;
}
