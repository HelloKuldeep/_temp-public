#include <bits/stdc++.h>
using namespace std;
int rope(int n,int a[]){
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<n;i++)	pq.push(a[i]);
	int ans=0;
	while(pq.size()!=1){
		int a=pq.top();	pq.pop();
		int b=pq.top();	pq.pop();
		pq.push(a+b);
		ans+=a+b;
	}
	return ans;
}
int main(void) {
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		cout<<rope(n,a);
		cout<<endl;
	}
	return 0;
}
