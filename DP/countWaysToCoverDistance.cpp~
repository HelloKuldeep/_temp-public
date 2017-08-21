#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int path(int n){
	int a[n+1];
	a[0]=1;	a[1]=1;	a[2]=2;
	rep(i,3,n+1)	a[i]=a[i-1]+a[i-2]+a[i-3];
	return a[n];
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n;	S(n);
	P(path(n));
	return 0;
}
