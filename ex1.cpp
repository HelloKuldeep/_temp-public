#include<bits/stdc++.h>	//Kosaraju's Algo
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
vector<int> visit;	int V,a,b,n,m,x=0,sc=0;;	stack<int> stk;	string cats[100];
void scc(vector< vector<int> > &adj,int u){
	visit[u]=1;
	//P(u);
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	if(!visit[*it])	scc(adj,*it);
}
void trav(vector< vector<int> > &adj,int u){
	visit[u]=1;
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++)	if(!visit[*it])	trav(adj,*it);
	stk.push(u);
}
void inpu(){
	rep(i,0,n){//XL;
		getline(cin>>ws,cats[i]);		cout<<cats[i]<<" ";//cout<<i<<" "<<j<<" "<<cats[i][j]<<" "<<nodes[i][j]<<" || ";	
	}cout<<"t";cout<<"t";
}
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
	S2(n,m);		int nodes[n][m];	V=n*m;	cin.ignore();	cout<<n<<m<<V;//V+=1;
	inpu();
    vector<vector<int> > adj1(V),adj2(V);
    rep(i,0,n)	rep(j,0,m)	nodes[i][j]=x++;
	rep(i,0,n)	rep(j,0,m){
	 	if(cats[i][j]=='E')	b=nodes[i][j+1];	else if(cats[i][j]=='W')	b=nodes[i][j-1];	else if(cats[i][j]=='N')	b=nodes[i+1][j];	else if(cats[i][j]=='S')	b=nodes[i-1][j];
	 	a=nodes[i][j];
		adj1[a].push_back(b);	adj2[b].push_back(a);
	}
	rep(i,0,V)	visit.push_back(0);
	rep(i,0,V)	if(!visit[i])	trav(adj1,i);
	visit.clear();
	rep(i,0,V)	visit.push_back(0);
	while(!stk.empty()){
		int u=stk.top();	stk.pop();
		if(!visit[u]){
			scc(adj2,u);	sc++;
		}
	}
	P(sc);
	return 0;
}
