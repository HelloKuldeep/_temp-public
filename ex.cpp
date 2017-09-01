#include <bits/stdc++.h>
using namespace std;
int coin(int n,int a[],int k){
	int t=0;
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[j]-a[i]>k)	t+=a[j]-a[i]-k,	a[j]-=(a[j]-a[i]-k);
	return t;
}
int main(void) {
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n,k;	cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		cout<<coin(n,a,k);
		cout<<endl;
	}
	return 0;
}
