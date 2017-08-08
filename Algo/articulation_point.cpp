//	O(v*(v+e))
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
#define P(x) printf("%d ",x)
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
	//cout<<a<<" ";
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
	 	S2(a,b);	
		v[a].push_back(b);
		v[b].push_back(a);
	}	//for(vector< vector<int> >::iterator ii=v.begin();ii!=v.end();ii++){	
		//	for(vector<int>::iterator iii=ii->begin();iii!=ii->end();iii++)	cout<<*iii<<" ";	XL;	} XL;XL;XL;
	stack<int> stk;	int kk,cc=0,mm=0;	set<int> ans;
	//for(l i=0;i<V;i++)	visit.push_back(0);
	for(int j=0;j<V;j++){	//cout<<j<<"-----\n";
		for(l i=0;i<V;i++)	visit.push_back(0);
		for(int u=0;u<V;u++){	//cout<<u;
			if(u==j)	continue;
			vector<int >::iterator it=find(v[u].begin(), v[u].end(), j);
			if(it != v[u].end()){
				stk.push(u);
				v[u].erase(it);
			}
		}
		for(l i=0;i<V;i++){
			if(i==j)	continue;
			if(!visit[i]){
				cc++;
				traverse(i,v);
			}
		}	//cout<<cc<<"//\n";
		if(cc>=mm){	//cout<<"tt\n";
			mm=cc;	ans.insert(j);
		}
		cc=0;
		while(!stk.empty()){
			kk=stk.top();	stk.pop();
			v[kk].push_back(j);
		}
		visit.clear();
	}	//for(vector< vector<int> >::iterator ii=v.begin();ii!=v.end();ii++){	
		//	for(vector<int>::iterator iii=ii->begin();iii!=ii->end();iii++)	cout<<*iii<<" ";	XL;	} 
	cout<<mm;	XL;	set<int>::iterator its;
	for(its=ans.begin();its!=ans.end();its++)	P(*its);	
    return 0;
}
