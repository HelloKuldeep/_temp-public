#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
typedef long long int LL;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> pii;  
#define rep(i,a,b) for(int i = a; i < b; i++)
#define XL printf("\n")
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define sz(a) int((a).size()) 
#define pb push_back
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FF first
#define SS second

inline long long inp(){
    long long n = 0;
    char c = getchar_unlocked();
    while(c<'0'|| c>'9') c = getchar_unlocked();
    while(c>='0'&&c<='9'){
    	n =(n<<3)+(n<<1)+c - '0';
        c = getchar_unlocked();
    }
    return n;
} 
 
int main() {
	clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	t=inp();//faster input
	cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
	return 0;
}
 
