//	O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define MAX 100001
int V,e,v,u;
int bfs(int s,int t,int parent[],vector<vector<pair<int,int> >  > &adj){
	int visit[V];
	rep(i,0,V)	visit[i]=0;
	queue<int> q;
	q.push(s);	visit[s]=1;	parent[s]=-1;
	while(!q.empty()){
		int u=q.front();	q.pop();
		for(vector<pair<int,int> >::iterator it=adj[u].begin();it!=adj[u].end();it++)	
			if(!visit[it->first] && (it->second)>0){
				q.push(it->first);	parent[it->first]=u;	visit[it->first]=1;
			}
	}
	return visit[t]==1;
}
bool isele_a(const pair<int,int> &i){
	return i.first==v;
}
bool isele_b(const pair<int,int> &i){
	return i.first==u;
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
    int a,b,c,mflow=0;	S2(V,e);//V+=1;
    vector<vector<pair<int,int> > > adj(V);	
	rep(i,0,e){
	 	S2(a,b);	S(c);	adj[a].push_back(make_pair(b,c));	adj[b].push_back(make_pair(a,0));
	}
	int s,t;	S2(s,t);
	int parent[V];
	while(bfs(s,t,parent,adj)){	//cout<<"ttttttt\n";
		int pflow=MAX;
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];	//cout<<v<<" "<<u<<" "<<pflow<<"*";
			vector<pair<int,int> >::iterator it=find_if( adj[u].begin(), adj[u].end(), isele_a);
			pflow=min(pflow,it->second);	//cout<<it->second<<"/"<<pflow<<endl;
		}	//cout<<"------\n";
		for(v=t;v!=s;v=parent[v]){
			u=parent[v];
			vector<pair<int,int> >::iterator ita=find_if( adj[u].begin(), adj[u].end(), isele_a);
			vector<pair<int,int> >::iterator itb=find_if( adj[v].begin(), adj[v].end(), isele_b);	//cout<<ita->second<<"**";
			ita->second -= pflow;	//cout<<ita->second<<"|||"<<itb->second<<"**";
			itb->second += pflow;	//cout<<itb->second<<"\n";
		}
		mflow+=pflow;
	}
	P(mflow);
	return 0;
}
