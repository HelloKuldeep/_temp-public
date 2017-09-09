#include<bits/stdc++.h> //O(m+n) or O(n)
using namespace std;
int patt(string s,string p){
	int n=s.length(),m=p.length(),i=1,j=0;
	vector<int> pa(m);
	pa[0]=0;
	while(i<m)
		if(p[j]==p[i]){ pa[i]=j+1; j++; i++; }
		else{ 
			if(j==0){ pa[i]=0; i++; }
			else j=pa[j-1]; 
		}
	j=0,i=0;
    while(i<n){
    	if(s[i]!=p[j]){ i++; j++; if(j==m) return 1; }
    	else{
    		if(j==0) i++;
    		else j=pa[j-1];
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
