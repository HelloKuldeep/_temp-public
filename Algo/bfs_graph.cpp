#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define all(v) v.begin(),v.end()
#define sz(a) int((a).size()) 
#define pb push_back
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FF first
#define SS second
vi visit;	int V;
void bfs(int i,vvi &v){
	queue<int> q;
	q.push(i);
	visit[i]=1;
	while(!q.empty()){
		int u=q.front();	q.pop();	P(u);
		int ss=v[u].size();
		rep(i,0,ss){
			if(!visit[v[u][i]]){
				visit[v[u][i]]=1;
				q.push(v[u][i]);
				}
			}
	}
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
   	int e,a,b;	S2(V,e);
   	vvi v(V);
    for(int i=0;i<e;i++){
    	S2(a,b);
		v[a].push_back(b);
		v[b].push_back(a);
    }
    rep(i,0,V)	visit.push_back(0);
    rep(i,0,V){
    	if(!visit[i])
    		bfs(i,v);
	}
    return 0;
}
