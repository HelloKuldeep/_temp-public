#include<bits/stdc++.h>	
using namespace std;
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int t;	scanf("%d",&t);
	while(t--){
		int n,u,count=0;	scanf("%d%d",&n,&u);
		int a[n],b[n+1];
		memset(b,0,sizeof(b));
		int l,r,v;
		for(int i=0;i<u;i++){
			scanf("%d%d%d",&l,&r,&v);
			b[l]+=v;	b[r+1]-=v;
		}
		for(int i=0;i<n;i++){
			count+=b[i];
			a[i]=count;
		}
		int q;	scanf("%d",&q);
		for(int i=0;i<q;i++){
			int x;	scanf("%d",&x);
			printf("%d\n",a[x]);
		}
	}
    return 0;
}

