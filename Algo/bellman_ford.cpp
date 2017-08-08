#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%lld ",x)
#define MAX 1000001
vector<ll> dist;
void initialise(int n){
	rep(i,0,n)	dist.push_back(MAX);
}
void bellman(vector<pair<pair<int,int>,int> > &vect,int n,long e){
	dist[1]=0;
	for(int i=1;i<=n-1;i++)
		for(long j=0;j<e;j++){
			int u=vect[j].first.first, v=vect[j].first.second, w=vect[j].second;
			if(dist[u]!=MAX && dist[u]+w<dist[v])	dist[v]=dist[u]+w;
		}
}
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int w,n,a,b;	long e;	S(n);	scanf("%ld",&e);
	initialise(n+1);
	vector<pair<pair<int,int>,int> > vect;
	for(long i=0;i<e;i++){
		S2(a,b);	S(w);
		vect.push_back(make_pair((make_pair(a,b)),w));
	}
	bellman(vect,n,e);
	rep(i,2,n+1)	P(dist[i]);	XL;
	return 0;
}
