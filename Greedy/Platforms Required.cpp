#include <bits/stdc++.h>
using namespace std;
int train(int n,int a[],int b[]){
	sort(a,a+n);
	sort(b,b+n);
	int ans=1,u=1,i=1,j=0;
	while(i<n && j<n){
		if(a[i]<b[j])	i++,	u++,	ans=max(u,ans);
		else	j++,	u--;
	}
	return ans;
}
int main(void) {
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++)	cin>>b[i];
		cout<<train(n,a,b);
		cout<<endl;
	}
	return 0;
}
