#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d ",x)
#define P2(x,y) printf("%d %d\n",x,y)
#define V 10
int NN,EE;
void printSolution(int path[]);
bool isSafe(int v, bool graph[V][V], int path[], int pos){
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
bool hamCycleUtil(bool graph[V][V], int path[], int pos){
    if (pos == NN){
        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
    for (int v = 1; v < NN; v++){
        if (isSafe(v, graph, path, pos)){
            path[pos] = v;
            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;
            path[pos] = -1;
        }
    }
    return false;
}
bool hamCycle(bool graph[V][V]){
    int *path = new int[NN];
    for (int i = 0; i < NN; i++)
        path[i] = -1;
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false ){
        cout<<"NO";	return false;
    }
    printSolution(path);
    return true;
}
void printSolution(int path[]){
    cout<<"YES";
    //for (int i = 0; i < NN; i++)	P(path[i]);	P(path[0]);
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
    hamCycle(graph1);
 
    return 0;
}
