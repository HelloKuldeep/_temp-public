//	O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define MAX 100001
#define V 7
int Vi,e;
int bfs(int s,int t,int parent[],int adj[V][V]){
	int visit[V];
	rep(i,0,V)	visit[i]=0;
	queue<int> q;
	q.push(s);	visit[s]=1;	parent[s]=-1;
	while(!q.empty()){
		int u=q.front();	q.pop();
		rep(v,0,V)	
			if(!visit[v] && adj[u][v]>0){
				q.push(v);	parent[v]=u;	visit[v]=1;
			}
	}
	return visit[t]==1;
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b,c,mflow=0;	S2(Vi,e);//V+=1;
    int adj[V][V];
    rep(i,0,V)rep(j,0,V)	adj[i][j]=0;
	rep(i,0,e){
	 	S2(a,b);	S(c);	adj[a][b]=c;
	}
	int s,t,v,u;	S2(s,t);
	int parent[V];
	while(bfs(s,t,parent,adj)){
		int pflow=MAX;
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];	pflow = min(pflow, adj[u][v]);
		}
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];	adj[u][v] -= pflow;	adj[v][u] += pflow;
		}
		mflow+=pflow;
	}
	P(mflow);
	return 0;
}
