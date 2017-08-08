#include<bits/stdc++.h>	//This code may have poor T.C.
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define P2(x,y) printf("%d %d\n",x,y)
#define V 10
int NN,EE;
bool hamCycle(bool graph[V][V],int u,int *visit,queue<int> &q,int *io){	int x=*io;
	int count=0;	x++;
	rep(i,0,NN)	if(!graph[u][i])	count++;
	if(count==NN && x!=NN)	return false;
	visit[u]=1;
    rep(i,0,NN)	if(graph[u][i] && !visit[i])	q.push(i);
    while(!q.empty()){
    	int v=q.front();	q.pop();	hamCycle(graph,v,visit,q,&x);
    }
    rep(i,0,NN)	if(!visit[i])	return false;
    return true;
}
bool Hamil(bool graph[V][V]){
	queue<int> q;	int visit[NN],x=0;
	rep(j,0,NN)	visit[j]=0;
	rep(i,0,NN){
		
		if(hamCycle(graph,i,visit,q,&x))	return true;
	}
	return false;
}
int main(){
   freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b;	S2(NN,EE);
    bool graph1[V][V];
    for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)	graph1[i][j]=0;
	for(int i=0;i<EE;i++){
	 	S2(a,b);	graph1[a][b]=1;
	}
    (Hamil(graph1))?cout<<"YES":cout<<"NO";
    return 0;
}
