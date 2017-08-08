#include<bits/stdc++.h>
using namespace std; 
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
int lengthOfLIS(vector<int>& nums){
	int len=nums.size();
    if(!len)    return 0;
    int ans[len];
    for(int i=0;i<len;i++)	ans[i]=1;
    for(int i=1;i<len;i++)
    	for(int j=0;j<i;j++)
        	if(nums[j]<nums[i])
            ans[i]=max(ans[i],ans[j]+1);
    return *max_element(ans,ans+len);
}
int main(){
	freopen("input.txt","r",stdin);	//freopen("output.txt","w",stdout);
	int u;	S(u);
	while(u--){
		int n,x;	S(n);
		vector<int> vec;
		rep(i,0,n){
			S(x);	vec.push_back(x);
		}
		P(lengthOfLIS(vec));
	}
	return 0;
}
