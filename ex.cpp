#include<bits/stdc++.h>
using namespace std;
long long n;
long long stock(vector<pair<long long,long long> > &a,long long sum){
	int count=0;
	sort(a.begin(),a.end());	for(int i=0;i<n;i++){	cout<<endl;	for(int j=0;j<a[i].second;j++)	cout<<a[i].first<<" ";}cout<<endl<<endl;
	for(long long i=0;i<n;i++){
		long long g=a[i].second;
		if(g*a[i].first<=sum){	sum-=g*a[i].first;	count+=g;	cout<<g*a[i].first<<"x"<<endl;	continue;}
		for(long long j=0;j<g;j++){
			if(sum-a[i].first<0)	break;
			else {	sum-=a[i].first;	count++;}	cout<<a[i].first<<endl;
		}
	}
	return count;
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	long long x;	scanf("%lld",&n);
	vector<pair<long long,long long> > a;
	for(long long i=1;i<=n;i++)	scanf("%lld",&x),	a.push_back(make_pair(x,i));
	long long k;	scanf("%lld",&k);
	cout<<stock(a,k)<<endl;
	return 0;
}
