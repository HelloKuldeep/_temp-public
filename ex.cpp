#include<bits/stdc++.h>
using namespace std;
int remove_duplicate(int a[],int n){
	int t=0;
	for(int i=0;i<n-1;i++) if(a[i]==a[i+1]) t++;
	return n-t;
}
int main(){
	freopen("input.txt","r",stdin);
    int t; cin>>t;
    while(t--){
    	int n; cin>>n;
        int a[n];
    	for(int i=0;i<n;i++) cin>>a[i];
    	cout<<remove_duplicate(a,n);
    	cout<<endl;
    }
    return 0;
}
