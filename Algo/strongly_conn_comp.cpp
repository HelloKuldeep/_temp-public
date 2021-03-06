#include<bits/stdc++.h>	//Kosaraju's Algo
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> visit;	int V,e;	stack<int> stk;
void scc(vector< vector<int> > &adj,int u){
	visit[u]=1;
	P(u);
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	if(!visit[*it])	scc(adj,*it);
}
void trav(vector< vector<int> > &adj,int u){
	visit[u]=1;
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	if(!visit[*it])	trav(adj,*it);
	stk.push(u);	//Fill vertices in stack according to their finishing times
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b,x=0;	S2(V,e);	//V+=1;
    vector< vector<int> > adj1(V),adj2(V);
	rep(i,0,e){
	 	S2(a,b);	adj1[a].push_back(b);	adj2[b].push_back(a);
	}
	rep(i,0,V)	visit.push_back(0);
	rep(i,0,V)	if(!visit[i])	trav(adj1,i);
	visit.clear();
	rep(i,0,V)	visit.push_back(0);
	while(!stk.empty()){
		int u=stk.top();	stk.pop();
		if(!visit[u]){
			scc(adj2,u);	XL;
		}
	}
	return 0;
}
