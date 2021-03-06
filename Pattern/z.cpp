#include<bits/stdc++.h> //O(m+n) or O(n)
using namespace std;
void zArr(string s,vector<int> &z){
	int n=s.length();
	int L=0,R=0;
	for(int i=1;i<n;i++)
		if(i>R){
				L=R=i;
				while(R<n && s[R-L]==s[R])	R++;
				z[i]=R-L;
				R--;
		}
		else{
			int k=i-L;
			if(z[k]<R-i+1)	z[i]=z[k];
			else{
			 	L=i;
			 	while(R<n && s[R-L]==s[R])	R++;
				z[i]=R-L;
				R--;
			}
		}
}
void patt(string s,string p){
	int n=s.length(),m=p.length();
	vector<int> z(n+m+1);
	zArr(p+"$"+s,z);
	n=n+m+1;
	for(int i=m+1;i<n;i++)	if(z[i]==m)	cout<<i-m<<endl;
}
int main(){
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;	cin.ignore();
	while(t--){
		string s;	getline(cin,s);
		string p;	getline(cin,p);
		patt(s,p);
		cout<<endl;
	}
	return 0;
}
