#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);	freopen("output.txt","w",stdout);
	long long n,m;	cin>>n>>m;
	long long a[n][m];
	for(long long i=0;i<n;i++)
		for(long long j=0;j<m;j++)
			cin>>a[i][j];
    long long u=0;
    for(long long i=0;i<n;i++)
    	for(long long j=0;j<m;j++){
    		if(i==0)	a[i][j]+=u;
    		a[i][j]+=a[i][j-1];
    		if(j==m-1)	u=a[i][j];
    	}
    long long t;  cin>>t;
    while(t--){
    	long long x,y;  cin>>x>>y;
        cout<<a[x-1][y-1]<<endl;
    }
    return 0;
}

