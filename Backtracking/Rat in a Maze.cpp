#include <bits/stdc++.h>	//This code is not running for now
using namespace std;
#define N 10
//int box[N][N];
int n;
void rat(vector<vector<int> > &box,int x,int y,vector<vector<int> > &vis,vector<string> &ans,string &ss){
	if(x<0 && x>=n && y<0 && y>=n && !box[x][y] && vis[x][y])	return;
	if(x==n-1 && y==n-1){ ans.push_back(ss); return; }
	vis[x][y]=1;
    ss.push_back('U');
    rat(box,x-1,y,vis,ans,ss);	
    ss[ss.length()-1]='D';
    rat(box,x+1,y,vis,ans,ss);
    ss[ss.length()-1]='R';
    rat(box,x,y+1,vis,ans,ss);
    ss[ss.length()-1]='L';
    rat(box,x,y-1,vis,ans,ss);
}
int main(){
	freopen("input.txt","r",stdin);
	int t,x;	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int> > box(n,vector<int>(n));
		//memset(box,-1,sizeof(box));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)	cin>>x, box[i][j]=x;	//for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<box[i][j]<<"-";
		vector<string> ans;cout<<"t";
		string ss;
		vector<vector<int> > vis(n,vector<int>(n));
		rat(box,0,0,vis,ans,ss);
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)	cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
