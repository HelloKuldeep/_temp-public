#include<bits/stdc++.h> //O(m+n) or O(n)
using namespace std;
int patt(string s,string p){
	int n=s.length(),m=p.length();
	int pr=101,prarr[m];		long long hp=0;
	for(int i=0;i<m;i++) prarr[i]=pow(pr,i); 
	for(int i=0;i<m;i++) hp+=int(p[i])*prarr[i];
	long long temp=0;
	for(int i=0;i<n-m+1;i++){
		if(i==0){
			for(int k=0;k<m;k++)	temp+=int(s[k])*prarr[k];	//cout<<s.substr(i,m)<<" ";
			if(temp==hp) if(p.compare(s.substr(i,m))==0)	return 1;
		}	
		else{
			temp=((temp-int(s[i-1]))/pr)+int(s[i+m-1])*prarr[m-1];
			if( temp == hp ) if(p.compare(s.substr(i,m))==0)	return 1;
		}
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
