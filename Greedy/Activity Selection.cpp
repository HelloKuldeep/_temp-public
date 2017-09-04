#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<pair<int,int>,int > &a,const pair<pair<int,int>,int > &b){
	return (a.first.second<b.first.second);
}
int office(int n,int a[],int b[]){
	vector<pair<pair<int,int>,int > > v;
		for(int i=0;i<n;i++)	v.push_back(make_pair(make_pair(a[i],b[i]),i+1));
	sort(v.begin(),v.end(),cmp);
	int i=0,x=1;
	for(int j=1;j<n;j++)	if(v[j].first.first >= v[i].first.second)	x++,	i=j;
	return x;
}
int main(void) {
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++)	cin>>b[i];
		cout<<office(n,a,b);
		cout<<endl;
	}
	return 0;
}
