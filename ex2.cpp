#include<bits/stdc++.h>
using namespace std;
vector<int> Solution(vector<int> &A) {
    int x=0,i,n=A.size(),y=0;
    vector<int> ax;
    vector<int> bx;
    for(i=0;i<n;i++){	if(A[i]<0)  break;	else{	x+=A[i];	ax.push_back(A[i]);	}	}
    for(int j=i+1;j<n;j++){ y+=A[j]; bx.push_back(A[j]); }//cout<<x<<" "<<y<<" ";
    //for(int j=0;j<ax.size();j++) cout<<ax[j]<<" ";cout<<endl;	for(int j=0;j<bx.size();j++) cout<<bx[j]<<" ";
    if(x>y) return ax;
    else if(x<y)    return bx;
    else{
        if(ax.size()>bx.size()) return ax;
        else if(ax.size()<bx.size())    return bx;
        else if(ax[0]>bx[0])    return bx;
        else return ax;
    }
}
int main(){
freopen("input.txt","r",stdin);
	int n; cin>>n;
		vector<int> box(n);
		for(int i=0;i<n;i++)	cin>>box[i];
		vector<int> v=Solution(box);
		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		cout<<endl;
	return 0;
}
