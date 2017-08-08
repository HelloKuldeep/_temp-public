#include<bits/stdc++.h>
using namespace std;
typedef int l;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;  
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz(a) int((a).size()) 
#define pb push_back
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FF first
#define SS second
vi visit;	l V;
void traverse(l a,vector< vector<int> > &v){
	visit[a]=1;
	cout<<a<<" ";
	l ss=v[a].size();
	rep(i,0,ss){
		if(!visit[v[a][i]])
			traverse(v[a][i],v);
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    l e,a,b;	S2(V,e);
    vector< vector<int> > v(V);
	for(l i=0;i<e;i++){
	 	S2(a,b);	v[a].push_back(b);
	}
	vector<l>::iterator it;
	for(l i=0;i<V;i++)	visit.push_back(0);
	for(l i=0;i<V;i++){
		if(!visit[i]){
			traverse(i,v);
		}
	}
	cout<<endl;
    return 0;
}
