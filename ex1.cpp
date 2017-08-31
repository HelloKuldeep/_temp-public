#include<bits/stdc++.h>	
using namespace std;
int bin(int n){
	if(n>1)	bin(n/2);
	cout<<n%2;
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	string a="ABC";
	cout<<a<<endl;
	swap((a+0), (a+0));
	cout<<a<<endl;
	cout<<endl;
    return 0;
}

