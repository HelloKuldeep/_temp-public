#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define MAX 1000001
vector<ll> dist;
void initialise(int n){
	rep(i,0,n)	dist.push_back(MAX);
}
void dijkstra(vector<vector<pair<ll,int> > > &vect){
	int u,v;  ll w,c;
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	pq.push(make_pair(0,1));
	dist[1]=0;
	while(!pq.empty()){
		u=pq.top().second;
		c=pq.top().first;
		pq.pop();
		if(dist[u]<c)	continue;	//To discard node u if its path is updated(Min) by some other pq pair.
		for(int i=0;i<vect[u].size();i++){
			v=vect[u][i].second;
			w=vect[u][i].first;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				pq.push(make_pair(dist[v],v));
			}
		}
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,a,b;	ll e,w;	S(n);	scanf("%lld",&e);
	initialise(n+1);
	vector<vector<pair<ll,int> > > vect(n+1);
	for(long i=0;i<e;i++){
		S2(a,b);	scanf("%lld",&w);
		vect[a].push_back(make_pair(w,b));
		vect[b].push_back(make_pair(w,a));	//undirected
	}	
	dijkstra(vect);
	rep(i,2,n+1)	P(dist[i]);
	return 0;
}
