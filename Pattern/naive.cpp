#include<bits/stdc++.h>
using namespace std;
int patt(string s,string p){
	int n=s.length(),m=p.length(),j;
    for(int i=0;i<=n-m;i++){
    	for(j=0;j<m;j++)
    		if(s[i+j]!=p[j])	break;
    	if(j==m)	return 1;
    }
	return 0;
}
int main(){
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;	cin.ignore();
	while(t--){
		string s;	getline(cin,s);
		string p;	getline(cin,p);
		(patt(s,p))?cout<<"YES":cout<<"NO";
		cout<<endl;
	}
	return 0;
}
