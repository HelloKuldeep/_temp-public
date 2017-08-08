//	O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> visit,ind;	int V,e;
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b;	S2(V,e);	V+=1;
    vector< vector<int> > adj(V);
    rep(i,0,V){
    	visit.push_back(0);	ind.push_back(0);
    }
	rep(i,0,e){
	 	S2(a,b);	adj[a].push_back(b);	ind[b]++;
	}
	queue<int> q;
	rep(i,1,V)	if(!ind[i])	q.push(i);
	int count=0;
	while(!q.empty()){
		int u=q.front();	q.pop();
		P(u);
		for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	if(!(--ind[*it]))	q.push(*it);
		count++;
	}
	return 0;
}
