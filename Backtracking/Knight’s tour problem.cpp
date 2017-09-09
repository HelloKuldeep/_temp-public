#include <bits/stdc++.h>
using namespace std;
#define N 8
int box[N][N];
int knight(int x,int y,int t,int u[],int v[]){
	if(t==N*N) return 1;
	int m,n;
	for(int i=0;i<8;i++){
		m=x+u[i],n=y+v[i];
		if(m>=0 && m<N && n>=0 && n<N && box[m][n]==-1){
			box[m][n]=t;
			if(knight(m,n,t+1,u,v))	return 1;
			else box[m][n]=-1;
		}
	}
	return 0;
}
int main(void) {
	freopen("input.txt","r",stdin);
	memset(box,-1,sizeof(box));
	box[0][0]=0;
	int u[8]={2,1,-1,-2,-2,-1, 1,2};
    int v[8]={1,2,2,1,-1,-2,-2,-1};
	if(knight(0,0,1,u,v)) for(int i=0;i<N;i++){ cout<<endl; for(int j=0;j<N;j++) cout<<box[i][j]<<" "; }
	else cout<<"No";
	cout<<endl;
	return 0;
}
