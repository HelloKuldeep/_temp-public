#include <bits/stdc++.h>
using namespace std;
bool sortmy(const pair<int,int> &a,const pair<int,int> &b){
	return (a.first>b.first);
}
pair<int,int> job(int n,int i2[],int d[],int p[]){
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)	v.push_back(make_pair(p[i],d[i]));
	sort(v.begin(),v.end(),sortmy);
	bool slot[n];
	int t=0,sum=0;
    for (int i=0;i<n;i++)
        slot[i]=false;
    for (int i=0;i<n;i++)
       for (int j=min(n,v[i].second)-1;j>=0;j--)
          if (slot[j]==false){
             sum+=v[i].first;
             slot[j]=true;
             t++;
             break;
          }
	return make_pair(t,sum);
}
int main(void) {
	//freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int i2[n],d[n],p[n];
		for(int i=0;i<n;i++)	cin>>i2[i], cin>>d[i], cin>>p[i];
		pair<int,int> p2=job(n,i2,d,p);
		cout<<p2.first<<" "<<p2.second<<endl;
	}
	return 0;
}
