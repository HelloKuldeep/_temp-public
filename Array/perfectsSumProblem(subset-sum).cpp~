#include<bits/stdc++.h> //counts and prints subarray having given sum
using namespace std;
void find(int a[],int x,int n,int sum,int &count,vector<int> &v){
	if(sum==0){
		for(int i=0;i<v.size();i++)	cout<<v[i]<<" ";
		cout<<endl;
		count++;
		return;
	}
	if(x==n || sum<0)
	return;
	for(int i=x;i<n;i++){
		v.push_back(a[i]);
		find(a,i+1,n,sum-a[i],count,v);
		v.pop_back();
	}
}
int main(){
    int t;	cin>>t;
    while(t--){
		int n; cin>>n; int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		int sum; cin>>sum;
		vector<int> v;
		int count=0;
		find(a,0,n,sum,count,v);
		cout<<count<<endl;
	}
	return 0;
}
