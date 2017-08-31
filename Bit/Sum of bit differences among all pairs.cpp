#include<bits/stdc++.h>	
using namespace std;
int bin(int n){
	if(n>1)	bin(n/2);
	cout<<n%2;
}
int p1(int n,int a[]){
	int b=0;
	for(int i=0;i<32;i++){
		int x=0;
		for(int j=0;j<n;j++)
			if(a[j]&(1<<i))	x++;
		b+=x*(n-x)*2;	
	}
	return b;
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.	txt","w",stdout);
	int t;	cin>>t;	
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		cout<<p1(n,a)%1000000007;	//can remove modulo if not given in ques
		cout<<endl;
	}
    return 0;
}

