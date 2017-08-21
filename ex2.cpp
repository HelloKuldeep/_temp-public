#include<bits/stdc++.h>
using namespace std;
int n;
int part(vector<int> &a){
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<n+1;i++){
		int u=INT_MIN;
		for(int j=0;j<i;j++)
			u=max(u,a[j]+dp[i-j-1]);
		dp[i]=u;
	}
	return dp[n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int x,sum=0;	scanf("%d",&n);
	vector<int> a;
	for(int i=0;i<n;i++)	scanf("%d",&x),	a.push_back(x);	//for(int i=0;i<n;i++)cout<<a[i]<<" ";	cout<<endl;
	cout<<part(a)<<endl;
	return 0;
}
