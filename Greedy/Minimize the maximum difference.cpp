#include <bits/stdc++.h>
using namespace std;
int height(int n,int k,int a[]){
	if(n==1)	return 0;
	sort(a,a+n);
	int ans=a[n-1]-a[0];
	int sma=a[0]+k,lar=a[n-1]-k;
	if(sma>lar)	swap(sma,lar);
	for(int i=1;i<n-1;i++){
		int x=a[i]-k,y=a[i]+k;
		if(x>=sma || y<=lar)	continue;
		if(lar-x <= y-sma)	sma=x;
		else lar=y;
	}
	return min(ans,lar-sma);
}
int main(void) {
	freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n,k;	cin>>k>>n;
		int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		cout<<height(n,k,a);
		cout<<endl;
	}
	return 0;
}
