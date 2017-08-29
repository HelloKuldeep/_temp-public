#include<bits/stdc++.h>	
using namespace std;
int bin(int n){
	if(n<=0) return 0;
	return n%2+bin(n/2);
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n,x=0;	cin>>n;
	for(int i=1;i<=n;i++)
		x+=bin(i);
	cout<<x<<endl;
    return 0;
}

