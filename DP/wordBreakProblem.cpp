#include<bits/stdc++.h>
using namespace std;
int dict(vector<string> &a,string s){
	int n=a.size();
	for(int i=0;i<n;i++)
		if(!s.compare(a[i]))	return 1;
	return 0;
}
int word(vector<string> &a,string s){
	int n=s.size();
	if(!n)	return 1;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(!dp[i] && dict(a,s.substr(0,i)))
			dp[i]=1;
		if(dp[i]){
			if(i==n)	return 1;
			for(int j=i+1;j<=n;j++){
				if(!dp[j] && dict(a,s.substr(i,j-i)))
					dp[j]=1;
				if(j==n && !dp[j])
					return 1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n;	cin>>n;
	vector<string> a;	string x;
	for(int i=0;i<n;i++)	cin>>x,	a.push_back(x), cin.ignore();	//for(int i=0;i<n;i++)cout<<a[i]<<"\n";	cout<<endl;
	string s;	cin>>s;	//cout<<s<<endl;
	(word(a,s))?cout<<"Y":cout<<"N";cout<<endl;
	return 0;
}
/*
int word(vector<string> &a,string s){	//Recursion
	int n=s.size();
	if(!n)	return 1;
	for(int i=1;i<=n;i++)
		if(dict(a,s.substr(0,i)) && word(a,s.substr(i,n-i)))	return 1;
	return 0;
}
*/
