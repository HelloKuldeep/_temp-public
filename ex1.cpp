#include<bits/stdc++.h>	
using namespace std;
int subsetSum(int a[],int s,int n){
	int count=0,sum=0,mask=0;
	while(mask < (1<<n)){
		sum=0;
		for(int i=0;i<n;i++)
			if(mask & (1<<i))	sum+=a[i];
		if(sum==s)	count++;
		mask++;
	}
	return count;
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int n;	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int s;	cin>>s;
	cout<<subsetSum(a,s,n)<<endl;
    return 0;
}

