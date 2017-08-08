// O(v+e)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> dist,parent,low;	int V,e,ocount=0,ecount=0;	stack<pair<int,int> > stk;
void traverse(vector< vector<int> > &adjl,int u){
	static int time=0;	int child=0;
	low[u]=dist[u]=++time;
	for(vector<int>::iterator it=adjl[u].begin();it!=adjl[u].end();it++){
		int v=*it;
		if(!dist[v]){
			child++;
			parent[v]=u;
			stk.push(make_pair(u,v));
			traverse(adjl,v);
			low[u]=min(low[u],low[v]);
			if( (dist[u]>1 && low[v]>=dist[u]) || (dist[u]==1 && child>1) ){
				set<int> ver;
				while(stk.top().first!=u || stk.top().second!=v){
					ver.insert(stk.top().first);	ver.insert(stk.top().second);	stk.pop();
				}
				ver.insert(stk.top().first);	ver.insert(stk.top().second);		stk.pop();
				if((ver.size())&1 && ver.size())	ocount++;	else if(ver.size())	ecount++;
			}
		}	else if(v!=parent[u] && dist[v]<low[u]){
			low[u]=min(low[u],dist[v]);
			stk.push(make_pair(u,v));
		}
	}
}
int main(){
    int a,b,x=0;	S2(V,e);
    vector< vector<int> > adjl(V);
	rep(i,0,e){
	 	S2(a,b);	adjl[a].push_back(b);	adjl[b].push_back(a);
	}
	rep(i,0,V){
		parent.push_back(0);	low.push_back(0);	dist.push_back(0);
	}
	rep(i,0,V){
		if(!dist[i])	traverse(adjl,i);
		set<int> ver;
		while(stk.size()>0){
			ver.insert(stk.top().first);	ver.insert(stk.top().second);	stk.pop();
		}
		if((ver.size())&1 && ver.size())	ocount++;	else if(ver.size())	ecount++;
	}
	cout<<ocount<<" "<<ecount;
	return 0;
}
