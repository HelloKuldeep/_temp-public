#include<bits/stdc++.h>		//O(logN)
using namespace std;
int bin(int n,int m);
int leftMbit(int n){
	int c=0;
	while(n>1)	n>>=1,	c++;
	return c;
}
int countBit(int n){
	int m=leftMbit(n);
	return bin(n,m);
}
int bin(int n,int m){
	if(!n)	return 0;
	n=n-(1<<m);
	return (n+1)+countBit(n)+m*(1<<(m-1));
}
int main(){
	//freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n;	cin>>n;
	cout<<countBit(n)<<endl;
    return 0;
}

