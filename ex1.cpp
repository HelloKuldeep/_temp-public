#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt","r",stdin);
	int x; float y;	cin>>x>>y;
	if(x%5!=0 || x+0.50>y)	cout<<fixed<<setprecision(2)<<y;
	else cout<<fixed<<setprecision(2)<<y-x-0.50;
	cout<<endl;
	return 0;
}
