#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,y=1,t=0;
	cin>>a;
	int m[a-1];
	for(int i=0;i<a-1;i++)
		m[i]=i+2;
	int hash[a-1];
	int p=2;
	for(int i=0;i<a-1;i++)
		hash[i]=0;
	while(y){
		int x=1;
		y=0;
		for(int i=t+1;i<a-1;i++){
			if(m[i]%p==0)
				if(!hash[i])	hash[i]=1;
		}
		for(int i=t+1;i<a-1;i++){
			if(!hash[i]){
				t=i;
				p=m[i];
				y=1;
				break;
			}
		}
	}
	for(int i=0;i<a-1;i++)
		if(!hash[i])	cout<<m[i]<<" ";
	cout<<endl;
	return 0;
}
