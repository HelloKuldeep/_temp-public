#include<bits/stdc++.h>
using namespace std;
int maxArea(int a[],int n){
	stack<int> s;
	int ma=-1,sum,tp,i=0;
	while(i<n){
		if(s.empty()||a[s.top()]<=a[i])	s.push(i++);
		else{
			int x=s.top(); s.pop();
			sum=a[x]*(s.empty()?i:i-s.top()-1);
			ma=max(sum,ma);
		}
	}
	while(!s.empty()){
		int x=s.top(); s.pop();
		sum=a[x]*(s.empty()?i:i-s.top()-1);
		ma=max(sum,ma);
	}
	return ma;
}
int main(){
	freopen("input.txt","r",stdin);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<maxArea(a,n);
	cout<<endl;
	return 0;
}
