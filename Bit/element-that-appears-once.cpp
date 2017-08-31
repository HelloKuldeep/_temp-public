#include<bits/stdc++.h>	//http://www.geeksforgeeks.org/find-the-element-that-appears-once/
using namespace std;
int p1(int a[],int n){
	int o=0,t=0,s;
	for(int i=0;i<n;i++){
		t|=o&a[i];
		o^=a[i];
		s=~(o&t);
		o&=s;
		t&=s;
	}
	return o;
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.	txt","w",stdout);
	int t;	cin>>t;	
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		cout<<p1(a,n);
		cout<<endl;
	}
    return 0;
}

