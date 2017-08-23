#include<bits/stdc++.h>
using namespace std;
int n;
int part(vector<string> &a,string s){
	int i,j,t=0,x=0,r=0,w=0;
	for(i=0;i<n;i++){	cout<<"----"<<i<<"----\n"<<"t="<<t<<" r="<<r<<" x="<<x<<" ";
		t=r;	cout<<"t=r="<<t<<" a[i].length()="<<a[i].length()<<endl;
		for(j=0;j<a[i].length();j++){	cout<<"||||"<<j<<"||||\n";
			if(s[t]==a[i][j]){	cout<<"(1) s[t]="<<s[t]<<" a[i][j]="<<a[i][j];	t++;	
								cout<<" t="<<t;}
			else{	x=1;	
				cout<<"(2) x="<<x;
			break;}	cout<<endl;
		}
		if(x){ r=t; cout<<"(3) r=t="<<r;}
		else{ r=0;	w+=t;cout<<"(4) r="<<r<<" w="<<w;}
			cout<<endl;cout<<"t="<<t<<" s.length()="<<s.length()<<" w="<<w<<endl;
		if(w==s.length())	break;
	}	cout<<"t="<<t<<" s.length()="<<s.length()<<" w="<<w<<endl;
	return (w==s.length())?1:0;
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	cin>>n;
	vector<string> a;
	string x;
	for(int i=0;i<n;i++)	cin>>x,	a.push_back(x), cin.ignore();	//for(int i=0;i<n;i++)cout<<a[i]<<"\n";	cout<<endl;
	string s;
	cin>>s;	//cout<<s<<endl;
	(part(a,s))?cout<<"Y":cout<<"N";cout<<endl;
	return 0;
}
