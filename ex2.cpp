#include<bits/stdc++.h>
using namespace std;
#define R 50
#define C 50
int maxArea(bool M[R][C],int n,int m){
	int a[n+1][m+1],ans=-1;
	for(int i=0;i<m+1;i++) a[0][i]=0;
	for(int i=0;i<n+1;i++) a[i][0]=0;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			a[i][j]=(M[i-1][j-1])?min(a[i-1][j-1],min(a[i-1][j],a[i][j-1]))+1:0;
			ans=max(ans,a[i][j]);
		}
	}
	return ans;
}
int main(){
	freopen("input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
    	int n,m; cin>>n>>m;
        bool M[R][C];
    	for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>M[i][j];
    	cout<<maxArea(M,n,m);
    	cout<<endl;
    }
    return 0;
}
