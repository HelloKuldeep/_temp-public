#include <bits/stdc++.h>
using namespace std;
void office(int s[], int f[], int n)
{
    int i, j;
 
    //printf ("Following activities are selected n");
 
    // The first activity always gets selected
    i = 0;
    printf("%d ", i+1);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j+1);
          i = j;
      }
    }
}
int main(void) {
	freopen("input.txt","r",stdin);
	int t;	cin>>t;
	while(t--){
		int n;	cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)	cin>>a[i];
		for(int i=0;i<n;i++)	cin>>b[i];
		//cout<<
		office(a,b,n);
		cout<<endl;
	}
	return 0;
}
