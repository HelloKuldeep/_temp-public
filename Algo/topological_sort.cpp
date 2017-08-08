#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> visit;	int V,e;	stack<int> stk;
void trav(vector< vector<int> > &adj,int u){
	visit[u]=1;
	set<int> ord;
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	ord.insert(*it);
	for(set<int>::reverse_iterator it=ord.rbegin();it!=ord.rend();it++)	if(!visit[*it])	trav(adj,*it);	//for lexical ordered topo
	stk.push(u);
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b;	S2(V,e);	V+=1;
    vector< vector<int> > adj(V);
	rep(i,0,e){
	 	S2(a,b);	adj[a].push_back(b);
	}
	rep(i,0,V)	visit.push_back(0);
	for(int i=V-1;i>0;i--)	if(!visit[i])	trav(adj,i);
	while(!stk.empty()){
		P(stk.top());	stk.pop();
	}
	return 0;
}
