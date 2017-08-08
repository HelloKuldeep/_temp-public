// O(v+e)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x,y) printf("%d %d\n",x,y)
vector<int> visit,dist,parent,low;	int V,e;
vector<pair<int,int> > bridge;
void traverse(vector< vector<int> > &adjl,int u){
	static int time=0;
	visit[u]=1;
	low[u]=dist[u]=++time;
	for(vector<int>::iterator it=adjl[u].begin();it!=adjl[u].end();it++){
		int v=*it;
		if(!visit[v]){
			parent[v]=u;
			traverse(adjl,v);
			low[u]=min(low[u],low[v]);
			if(low[v]>dist[u])	bridge.push_back(make_pair(u,v));
		}
		else if(v!=parent[u])	low[u]=min(low[u],dist[v]);
	}
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b,x=0;	S2(V,e);
    vector< vector<int> > adjl(V);
	rep(i,0,e){
	 	S2(a,b);	adjl[a].push_back(b);	adjl[b].push_back(a);
	}
	rep(i,0,V){
		visit.push_back(0);	parent.push_back(0);	low.push_back(0);	dist.push_back(0);
	}
	rep(i,0,V)	if(!visit[i])	traverse(adjl,i);
	int r=bridge.size();	cout<<r;	XL;
	rep(i,0,r)	P(bridge[i].first,bridge[i].second);
	return 0;
}
