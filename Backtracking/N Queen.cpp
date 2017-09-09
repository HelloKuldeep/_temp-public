#include <bits/stdc++.h>
using namespace std;
bool isSafe(int i,int j,vector<vector<int> > &board,int n){
	for(int k = 0; k < n; k++) if(board[i][k] || board[k][j] ) return false;
    for(int k = 0; k < j; k++) if(i-(j-k)>= 0 && board[i-(j-k)][k]) return false;
    for(int k = j+1; k < n; k++) if(i-(k-j) >= 0 && i-(k-j)< n && board[i-(k-j)][k]) return false;
    return true;
}
void queen(int n,int row,vector<vector<int> > &box,vector<vector<int> > &ans,vector<int> temp){
	if(row==n-1){ 
		for(int j = 0; j < n; j++)
		        if(isSafe(row,j,box,n) ){	temp.push_back(j);	ans.push_back(temp);	}
        return;
    }
	for(int i=0;i<n;i++)
		if(isSafe(row,i,box,n)){
			vector<int> resultTmp = temp;
            resultTmp.push_back(i);
            box[row][i]=1;
            queen(n,row+1,box,ans,resultTmp);
            box[row][i]=0;		
		}
}
int main(){
	//freopen("input.txt","r",stdin);
	int t,x;	cin>>t;
	while(t--){
		int n; cin>>n;
		vector<vector<int> > box(n,vector<int>(n));
		for(int i=0;i<n;i++)	for(int j=0;j<n;j++)	box[i][j]=0;	
		vector<vector<int> > ans;
		vector<int> temp;
		queen(n,0,box,ans,temp);
		if(!ans.size()) cout<<-1;
		else for(int i=0;i<ans.size();i++){ cout<<"["; for(int j=0;j<ans[i].size();j++)	cout<<ans[i][j]+1<<" ";	cout<<"] ";}
		cout<<endl;
	}
	return 0;
}
