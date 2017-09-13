#include<bits/stdc++.h>
using namespace std;
bool mirrorUtil(vector<stack<int> >& tree1,vector<queue<int> >& tree2){
    for (int i = 1; i < tree1.size(); ++i) {
        stack<int>& s = tree1[i];
        queue<int>& q = tree2[i];
        while (!s.empty() && !q.empty()) {
            if (s.top() != q.front())
                return false;
            s.pop();
            q.pop();
        }
        if (!s.empty() || !q.empty())
            return false;
    }
    return true;
}
void areMirrors(int m, int n, int u1[], int v1[], int u2[], int v2[]){
    vector<stack<int> > tree1(m + 1);
    vector<queue<int> > tree2(m + 1);
    for (int i = 0; i < n; i++) 
        tree1[u1[i]].push(v1[i]);
    for (int i = 0; i < n; i++) 
        tree2[u2[i]].push(v2[i]);
    mirrorUtil(tree1, tree2)?cout<<1:cout<<0;
}
int main(){
	freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int m,n;	cin>>m>>n;
		int v1[n],u1[n],v2[n],u2[n];
		for(int i=0;i<n;i++)	cin>>v1[i],	cin>>u1[i];
		for(int i=0;i<n;i++)	cin>>v2[i],	cin>>u2[i];
		areMirrors(m,n,v1,u1,v2,u2);
		cout<<endl;
	}
	return 0;
}
