#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi; 
typedef vector<vi> vvi;  
#define rep(i,a,b) for(long long i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%lld",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%lld\n",x)
vi id;
void initialise(int n){
	rep(i,0,n)	id.push_back(i);
}
int root(int x){
	while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(int x,int y){
	int p=root(x),q=root(y);
	id[p]=id[q];
}
ll kruskal(pair<ll,pair<int,int> > vect[],int e){
	int x,y;	ll cost,minC=0;
	rep(i,0,e){
		x=vect[i].second.first;
		y=vect[i].second.second;
		cost=vect[i].first;
		if(root(x)!=root(y)){
			minC+=cost;	union1(x,y);
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
	pair<ll,pair<int,int> > vect[e];
	rep(i,0,e){
		S2(a,b);	S(w);
		vect[i]=make_pair(w,make_pair(a,b));
	}
	sort(vect,vect+e);
	P(kruskal(vect,e));
	return 0;
}
