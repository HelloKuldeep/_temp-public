#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
	int n; cin>>n;
	while(n--){
		int a,u,s=0; cin>>a;
		while(u){
			int x=1;
			u=a/(pow(5,x));
			x++;
			s+=u;
		}
		cout<<s<<endl;
	}
	return 0;
}
