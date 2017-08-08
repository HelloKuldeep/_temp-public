// O(v+e)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> visit,dist,parent,low,ap;	int V,e;
void traverse(vector< vector<int> > &adjl,int u){
	static int time=0;	int child=0;
	visit[u]=1;
	low[u]=dist[u]=++time;
	for(vector<int>::iterator it=adjl[u].begin();it!=adjl[u].end();it++){
		int v=*it;
		if(!visit[v]){
			child++;
			parent[v]=u;
			traverse(adjl,v);
			low[u]=min(low[u],low[v]);
			if(parent[v] && low[v]>=dist[u])	ap[u]=1;
			if(!parent[v] && child>1)	ap[u]=1;
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
		visit.push_back(0);	parent.push_back(0);	ap.push_back(0);	low.push_back(0);	dist.push_back(0);
	}
	rep(i,0,V)	if(!visit[i])	traverse(adjl,i);
	rep(i,0,V)	if(ap[i])	x++;	cout<<x;	XL;
	rep(i,0,V)	if(ap[i])	P(i);
	return 0;
}
