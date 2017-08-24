#include<bits/stdc++.h>
using namespace std;
int n;
bool sortby(const vector<int> &a, const vector<int> &b){
    return (a[0]*a[1] > b[0]*b[1]);
}
bool sortby2(const int &a, const int &b){
    return (a > b);
}
int Box2(vector<vector<int> > &box){
	int t=n,dp[3*n];
	for(int i=0;i<n;i++){
		box[t].push_back(box[i][1]); box[t].push_back(box[i][2]); box[t++].push_back(box[i][0]);
		box[t].push_back(box[i][2]); box[t].push_back(box[i][0]); box[t++].push_back(box[i][1]);
	}
	for(int i=0;i<n*3;i++)	sort(box[i].begin(),box[i].begin()+2,sortby2);	//to arrange first 2 elements
	sort(box.begin(),box.end(),sortby);
	for(int i=0;i<n*3;i++)	dp[i]=box[i][2];
	for(int i=1;i<n*3;i++)
		for(int j=0;j<i;j++)
			if(box[i][0]*box[i][1] < box[j][0]*box[j][1] && box[i][0]<box[j][0] && box[i][1]<box[j][1])
				dp[i]=dp[j]+box[i][2];
	return *max_element(dp,dp+3*n);
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	cin>>t;
	while(t--){
		int x,y,z; scanf("%d",&n);
		vector<vector<int> > box(3*n);
		for(int i=0;i<n;i++) cin>>x>>y>>z, box[i].push_back(x), box[i].push_back(y), box[i].push_back(z);
		cout<<Box2(box)<<endl;
	}
	return 0;
}
/*
int dice(int n,int m,int k){	//Recursion
	if(k<1)	return 0;
	if(n==1)	return k<=m;
	int u=0;
	for(int i=1;i<=m;i++)
		u+=dice(n-1,m,k-i);
	return u;
}
*/
