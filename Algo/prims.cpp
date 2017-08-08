#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
#define rep(i,a,b) for(long long i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%lld",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%lld\n",x)
vector<int> visit;
void initialise(int n){
	rep(i,0,n)	visit.push_back(0);
}
ll prims(vector<pair<ll,int> > vect[]){
	priority_queue<pll,vector<pll>,greater<pll> > pq;	ll minC=0;	int x,y;
	pq.push(make_pair(0,1));
	pair<ll,int> pa;
	while(!pq.empty()){
		pa=pq.top();
		pq.pop();
		x=pa.second;
		if(visit[x]==1)	continue;
		minC+=pa.first;
		visit[x]=1;
		for(int i=0;i<vect[x].size();i++){
			y=vect[x][i].second;
			if(visit[y]==0)
				pq.push(vect[x][i]);
		}
	}
	return minC;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,e,a,b;	S2(n,e);
	ll w;
	initialise(n+1);
	vector<pair<ll,int> > vect[e+1];
	rep(i,0,e){
		S2(a,b);	S(w);
		vect[a].push_back(make_pair(w,b));
		vect[b].push_back(make_pair(w,a));
	}
	P(prims(vect));
	return 0;
}
