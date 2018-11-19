///////////////////     1.base station
#include<iostream>
using namespace std;
int mat[20][20];
bool visited[20][20];
int n,m,mxsum=0;
int oddcol[2][6]={{-1,0,0,1,1,1},{0,-1,1,-1,0,1}};
int evencol[2][6]={{-1,-1,-1,0,0,1},{-1,0,1,-1,1,0}};
bool isvalid(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return false;
	return true;
}
void call(int x,int y,bool visited[20][20],int val,int &sum,int l)
{
	if(l==1)
	{
		sum=max(sum,val);
		return;
	}
	visited[x][y]=true;
	if(y%2!=0)//oddcol[2][6]={{-1,0,0,1,1,1},{0,-1,1,-1,0,1}};
	{
		for(int i=0;i<6;i++)
		{
			int nextx=x+oddcol[0][i];
			int nexty=y+oddcol[1][i];
			if(isvalid(nextx,nexty)&&!visited[nextx][nexty])
			{
				call(nextx,nexty,visited,val+mat[nextx][nexty],sum,l-1);
			}
		}
	}
	else //evencol[2][6]={{-1,-1,-1,0,0,1},{-1,0,1,-1,1,0}};
	{
		for(int i=0;i<6;i++)
		{
			int nextx=x+evencol[0][i];
			int nexty=y+evencol[1][i];
			if(isvalid(nextx,nexty)&&!visited[nextx][nexty])
			{
				call(nextx,nexty,visited,val+mat[nextx][nexty],sum,l-1);
			}
		}
	}
	visited[x][y]=false;
}
void cally(int x,int y)
{
	if(y%2==0)//evencol[2][6]={{-1,-1,-1,0,0,1},{-1,0,1,-1,1,0}};
	{
		int x1=x;
		int y1=y;
		int x2=x+evencol[0][0];
		int y2=y+evencol[1][0];
		int x3=x+evencol[0][2];
		int y3=y+evencol[1][2];
		int x4=x+evencol[0][5];
		int y4=y+evencol[1][5];
		if(isvalid(x1,x1)&&isvalid(x2,y2)&&isvalid(x3,y3)&&isvalid(x4,y4))
		{
			mxsum=max(mxsum,mat[x1][y1]+mat[x2][y2]+mat[x3][y3]+mat[x4][y4]);
		}
	}
	else//oddcol[2][6]={{-1,0,0,1,1,1},{0,-1,1,-1,0,1}};
	{
		int x1=x;
		int y1=y;
		int x2=x+oddcol[0][1];
		int y2=y+oddcol[1][1];
		int x3=x+oddcol[0][2];
		int y3=y+oddcol[1][2];
		int x4=x+oddcol[0][4];
		int y4=y+oddcol[1][4];
		if(isvalid(x1,x1)&&isvalid(x2,y2)&&isvalid(x3,y3)&&isvalid(x4,y4))
		{
			mxsum=max(mxsum,mat[x1][y1]+mat[x2][y2]+mat[x3][y3]+mat[x4][y4]);
		}
	}
}
void call_invy(int x,int y)
{
	if(y%2==0)//evencol[2][6]={{-1,-1,-1,0,0,1},{-1,0,1,-1,1,0}};
	{
		int x1=x;
		int y1=y;
		int x2=x+evencol[0][1];
		int y2=y+evencol[1][1];
		int x3=x+evencol[0][3];
		int y3=y+evencol[1][3];
		int x4=x+evencol[0][4];
		int y4=y+evencol[1][4];
		if(isvalid(x1,x1)&&isvalid(x2,y2)&&isvalid(x3,y3)&&isvalid(x4,y4))
		{
			mxsum=max(mxsum,mat[x1][y1]+mat[x2][y2]+mat[x3][y3]+mat[x4][y4]);
		}
	}
	else//oddcol[2][6]={{-1,0,0,1,1,1},{0,-1,1,-1,0,1}};
	{
		int x1=x;
		int y1=y;
		int x2=x+oddcol[0][0];
		int y2=y+oddcol[1][0];
		int x3=x+oddcol[0][3];
		int y3=y+oddcol[1][3];
		int x4=x+oddcol[0][5];
		int y4=y+oddcol[1][5];
		if(isvalid(x1,x1)&&isvalid(x2,y2)&&isvalid(x3,y3)&&isvalid(x4,y4))
		{
			mxsum=max(mxsum,mat[x1][y1]+mat[x2][y2]+mat[x3][y3]+mat[x4][y4]);
		}
	}
}
int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>mat[i][j];
			}
		}
		mxsum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				int sum=0;
				call(i,j,visited,mat[i][j],sum,4);
				mxsum=max(mxsum,sum);
				cally(i,j);
				call_invy(i,j);
			}
		}
		cout<<mxsum<<endl;
	}
}
//////////////////////////////////////////////////////////////////////////////
/////////////     2. fishery
#include<bits/stdc++.h>
using namespace std;
int visited[10000];
int n;
int fish(int pos,int man,int flag)
{
	int i,j;
	i=pos;
	j=pos;
	int dist=1;
	int total=0;
	for(int k=0;k<man;k++)
	{
		while(visited[i]==1&&visited[j]==1)
		{
			if(i+1<n)
			i++;
			if(j-1>=0)
			j--;
			dist++;
		}
		if(k==man-1)
		{
			total+=dist;
			if(visited[i]==0&&visited[j]==0)
			{
				if(flag)
				{
					visited[i]=1;
				}
				else
				{
					visited[j]=1;
				}
			}
			else
			{
				if(visited[i]==0)
				{
					visited[i]=1;
				}
				else
				{
					visited[j]=1;
				}
			}
		}
		else
		{
			total+=dist;
			if(visited[i]==0)
			{
				visited[i]=1;
			}
			else
			{
				visited[j]=1;
			}
		}	
	}
	return total;
}
int call(int g1[2],int g2[2],int g3[2])
{
	int l,i,j,k,res=INT_MAX,val;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
			{
				for(l=0;l<n;l++)
				{
					visited[l]=0;
				}
				val=fish(g1[0],g1[1],i)+fish(g2[0],g2[1],j)+fish(g3[0],g3[1],k);
				res=min(res,val);
			}
		}
	}
	return res;
}
int main()
{
	int t,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int gate1[2],gate2[2],gate3[2];
		cin>>gate1[0]>>gate1[1]>>gate2[0]>>gate2[1]>>gate3[0]>>gate3[1];
		gate1[0]--;
		gate2[0]--;
		gate3[0]--;
		int ans=INT_MAX,val;
		val=call(gate1,gate2,gate3);
		ans=min(ans,val);
		val=call(gate1,gate3,gate2);
		ans=min(ans,val);
		val=call(gate2,gate1,gate3);
		ans=min(ans,val);
		val=call(gate2,gate3,gate1);
		ans=min(ans,val);
		val=call(gate3,gate1,gate2);
		ans=min(ans,val);
		val=call(gate3,gate2,gate1);
		ans=min(ans,val);
		cout<<ans;
	}
}
/////////////////////////////////////////////////////////////////
///////////////////     3. product manufacturing
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		int D,E,F,d,e,a,b,c,p;
		cin>>D>>E>>F>>d>>e;
		cin>>n;
		int arr[n][4];
		for(i=0;i<n;i++)
		{
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
		}
		int x1,x2,x3;
		int mxprice=0;
		int price1=0,price2=0,price3=0,cpus,mem,board;
		for(i=0;i<n;i++)
		{
			for(x1=0;x1<=min(D/arr[i][0],min(E/arr[i][1],F/arr[i][2]));x1++)
			{
				cpus=D-x1*arr[i][0];
				mem=E-x1*arr[i][1];
				board=F-x1*arr[i][2];
				price1=x1*arr[i][3];
				mxprice=max(mxprice,price1+cpus*d+mem*e);
				for(j=i+1;j<n;j++)
				{
					for(x2=0;x2<=min(D/arr[j][0],min(E/arr[j][1],F/arr[j][2]));x2++)
					{
						cpus=cpus-x2*arr[j][0];
						mem=mem-x2*arr[j][1];
						board=board-x2*arr[j][2];
						price2=x2*arr[j][3];
						if(cpus>=0&&mem>=0&&board>=0)
						{
							mxprice=max(mxprice,price1+price2+cpus*d+mem*e);
							for(k=j+1;k<n;k++)
							{
								for(x3=0;x3<=min(D/arr[k][0],min(E/arr[k][1],F/arr[k][2]));x3++)
								{
									cpus=cpus-x3*arr[k][0];
									mem=mem-x3*arr[k][1];
									board=board-x3*arr[k][2];
									price3=x3*arr[k][3];
									if(cpus>=0&&mem>=0&&board>=0)
									{
										mxprice=max(mxprice,price1+price2+price3+cpus*d+mem*e);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<mxprice<<endl;
	}
}
////////////////////////////////////////////////////////////
//////////////////         4.mobile tower
#include<bits/stdc++.h>
using namespace std;
int dir[2][4]={{0,0,-1,1},{-1,1,0,0}};
int n;
bool isvalid(int x,int y)
{
	if(x<0||y<0||x>=n||y>=n)
		return false;
	return true;
}
void call(vector<vector<int> >&mat,int x,int y,int &c,vector<vector<bool> >&sec_vis,int val)
{
	sec_vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int next_x=x+dir[0][i];
		int next_y=y+dir[1][i];
		if(isvalid(next_x,next_y)&&!sec_vis[next_x][next_y]&&mat[next_x][next_y]==val)
		{
			c++;
			call(mat,next_x,next_y,c,sec_vis,val);
		}
	}
}
void zero(vector<vector<int> >&mat,int x,int y,int &val)
{
	map<int,int>mp;
	stack<pair<int,int> >st;
	st.push(make_pair(x,y));
	vector<vector<bool> >visited(n,vector<bool>(n,false));
	vector<vector<bool> >sec_vis(n,vector<bool>(n,false));
	int c;
	while(!st.empty())
	{
		pair<int,int>pp=st.top();
		st.pop();
		visited[pp.first][pp.second]=true;
		for(int i=0;i<4;i++)
		{
			int next_x=pp.first+dir[0][i];
			int next_y=pp.second+dir[1][i];
			if(isvalid(next_x,next_y)&&!visited[next_x][next_y])
			{
				if(mat[next_x][next_y]==0)
				{
					st.push(make_pair(next_x,next_y));
				}
				else
				{
					c=1;
					call(mat,next_x,next_y,c,sec_vis,mat[next_x][next_y]);
					mp[mat[next_x][next_y]]+=c;
				}
			}
		}
	}
	map<int,int>::iterator it;
	int mx=0,ele;
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>mx)
		{
			mx=it->second;
			ele=it->first;
		}
		if(it->second==mx)
		{
			ele=max(ele,it->first);
		}
	}
	val=ele;
}
void count(vector<vector<int> >&mat,int x,int y,vector<vector<bool> >&vis,int val)
{
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int next_x=x+dir[0][i];
		int next_y=y+dir[1][i];
		if(isvalid(next_x,next_y)&&!vis[next_x][next_y]&&mat[next_x][next_y]==val)
		{
			count(mat,next_x,next_y,vis,val);
		}
	}
}
int main()
{
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<vector<int> >mat(n,vector<int>(n));
		map<pair<int,int>,int>replace;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>mat[i][j];
			}
		}
		int val;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][j]==0)
				{
					val=0;
					zero(mat,i,j,val);
					replace[make_pair(i,j)]=val;
				}
			}
		}
		stack<pair<int,int> >fill;
		map<pair<int,int>,int>::iterator it;
		for(it=replace.begin();it!=replace.end();it++)
		{
			pair<int,int>xp=it->first;
			int x=xp.first;
			int y=xp.second;
			int ele=it->second;
			fill.push(make_pair(x,y));
			while(!fill.empty())
			{
				pair<int,int>pp=fill.top();
				fill.pop();
				mat[pp.first][pp.second]=ele;
				for(int i=0;i<4;i++)
				{
					int next_x=pp.first+dir[0][i];
					int next_y=pp.second+dir[1][i];
					if(isvalid(next_x,next_y)&&mat[next_x][next_y]==0)
					{
						mat[next_x][next_y]=ele;
						fill.push(make_pair(next_x,next_y));
					}
				}
			}
		}
		int ans=0;
		vector<vector<bool> >vis(n,vector<bool>(n,false));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(!vis[i][j])
				{
					count(mat,i,j,vis,mat[i][j]);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
////////////////////////////////////////////////////////
//////////////////      5. pipe
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct pipe
{
	bool left,right,up,down;	
};
pipe all[8]={{.left=false,.right=false,.up=false,.down=false},
		   {.left=true,.right=true,.up=true,.down=true},
		   {.left=false,.right=false,.up=true,.down=true},
		   {.left=true,.right=true,.up=false,.down=false},
		   {.left=false,.right=true,.up=true,.down=false},
		   {.left=false,.right=true,.up=false,.down=true},
		   {.left=true,.right=false,.up=false,.down=true},
		   {.left=true,.right=false,.up=true,.down=false}};
bool isvalid(int x,int y)
{
	if(x<0||y<0||x>=n||y>=m)
		return false;
	return true;
}
bool validpipe(vector<vector<int> >&mat,int pre_x,int pre_y,int next_x,int next_y)
{
	pipe p1=all[mat[pre_x][pre_y]];
	pipe p2=all[mat[next_x][next_y]];
	if(p1.down&&p2.up&&pre_x+1==next_x&&pre_y==next_y)
	{
		return true;
	}
	if(p1.left&&p2.right&&pre_y-1==next_y&&pre_x==next_x)
	{
		return true;
	}
	if(p1.right&&p2.left&&pre_y+1==next_y&&pre_x==next_x)
	{
		return true;
	}
	if(p1.up&&p2.down&&pre_x-1==next_x&&pre_y==next_y)
	{
		return true;
	}
	return false;
}
int dir[2][4]={{0,0,1,-1},{1,-1,0,0}};
int main()
{
	int t,i,j,r,c,l;
	cin>>t;
	while(t--)
	{
	cin>>n>>m>>r>>c>>l;
	vector<vector<int> >mat(n,vector<int>(m));
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}
	if(mat[r][c]==0||l==0)
	{
		cout<<0<<endl;
	}
	else
	{
		queue<pair<int,pair<int,int> > >Q;
		Q.push(make_pair(1,make_pair(r,c)));
		vector<vector<bool> >visited(n,vector<bool>(m,false));
		visited[r][c]=true;
		int count=1;
		while(!Q.empty())
		{
			pair<int,pair<int,int> >pp;
			pp=Q.front();
			Q.pop();
			int len=pp.first;
			int x=pp.second.first;
			int y=pp.second.second;
			for(i=0;i<4;i++)
			{
				int next_x=x+dir[0][i];
				int next_y=y+dir[1][i];
				if(isvalid(next_x,next_y)&&!visited[next_x][next_y])
				{
					if(mat[next_x][next_y]!=0&&validpipe(mat,x,y,next_x,next_y))
					{
						if(len+1<=l)
						{
							count++;
							visited[next_x][next_y]=true;
							Q.push(make_pair(len+1,make_pair(next_x,next_y)));
						}
					}
				}
			}
		}
		cout<<count<<endl;
	}
	}
}
/////////////////////////////////////////////////////////
/////////////       6. airoplane game
#include<bits/stdc++.h>
using namespace std;
int mat[13][5],vis[5][5];
void detonate(int r)
{
	for(int i=r;i>r-5;i--)
	{
		for(int j=0;j<5;j++)
		{
			vis[r-i][j]=0;
			if(i>=0&&mat[i][j]==2)
			{
				mat[i][j]=0;
				vis[r-i][j]=2;
			}
		}
	}
}
void undetonate(int r)
{
	for(int i=r;i>r-5;i--)
	{
		for(int j=0;j<5;j++)
		{
			if(i>=0&&vis[r-i][j]==2)
			{
				mat[i][j]=2;
			}
		}
	}
}
void call(int pos,int coin,int &mxcoin,int n)
{
	if(pos<0||pos>4||coin<0)
		return;
	if(mat[n-1][pos]==1)
		coin+=1;
	else if(mat[n-1][pos]==2)
		coin-=1;
	if(n==1)
	{
		if(mxcoin<coin)
			mxcoin=coin;
		return;
	}
	else
	{
		call(pos-1,coin,mxcoin,n-1);
		call(pos+1,coin,mxcoin,n-1);
		call(pos,coin,mxcoin,n-1);
	}
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
				cin>>mat[i][j];
		}
		int mxcoin=-1;
		for(i=n-1;i>0;i--)
		{
			int coin=-1;
			detonate(i);
			call(2,0,coin,n);
			if(mxcoin<coin)
				mxcoin=coin;
			undetonate(i);
		}
		cout<<mxcoin<0?-1:mxcoin;
		cout<<endl;
	}
}
/////////////////////////////////////////////////
///////////    7. marathon
#include<iostream>
using namespace std;
int pace[5][2];
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	int t,n,i,j,a,b;
	cin>>t;
	while(t--)
	{
		int energ,dist;
		cin>>energ>>dist;
		for(i=0;i<5;i++)
		{
			cin>>a>>b>>pace[i][1];
			pace[i][0]=a*60+b;
		}
		int dp[dist+1][energ+1];
		for(i=0;i<=dist;i++)
		{
			for(j=0;j<=energ;j++)
			{
				dp[i][j]=INT_MAX;
			}
		}
		for(i=0;i<5;i++)
		{
			dp[1][pace[i][1]]=pace[i][0];
		}
		for(i=2;i<=dist;i++)
		{
			for(j=1;j<=energ;j++)
			{
				int mina=INT_MAX;
				for(int k=0;k<5;k++)
				{
					if(j-pace[k][1]>0&&dp[i-1][j-pace[k][1]]!=INT_MAX&&dp[i-1][j-pace[k][1]]+pace[k][0]<mina)
					{
						mina=dp[i-1][j-pace[k][1]]+pace[k][0];
						//cout<<mina<<endl;
					}
				}
				dp[i][j]=mina;
			}
		}
		int ans=INT_MAX;
		for(i=1;i<=energ;i++)
		{
			ans=min(dp[dist][i],ans);
		}
		cout<<ans/60<<" "<<ans%60<<endl;
	}
}
///////////////////////////////////////////////
//////////////////       8. fuel
#include<bits/stdc++.h>
using namespace std;
int arr[9];
int visited[9];
int total_dist=999999;
void call(int n,int dist,int rem,int pindex,int cars,int ins,int gord)
{
	if(cars==n)
	{
		if(dist<total_dist)
		total_dist=dist;
		return;
	}
	if(rem<=0)
	return;
	if(ins==0&&gord==0)
	{
		for(int k=1;k<=n;k++)
		{
			if(!visited[k]&&arr[k]==1)
			{
				visited[k]=1;
				call(n,dist+abs(k-pindex),rem-1,k,cars+1,0,0);
				call(n,dist+abs(k-pindex),2,k,cars+1,1,0);
				call(n,dist+abs(k-pindex),2,k,cars+1,2,0);
				visited[k]=0;
			}
		}
	}
	if(ins==0&&gord==1)
	{
		for(int k=n;k>=1;k--)
		{
			if(!visited[k]&&arr[k]==2)
			{
				visited[k]=1;
				call(n,dist+abs(k-pindex),rem-1,k,cars+1,0,1);
				call(n,dist+abs(k-pindex),2,k,cars+1,1,1);
				call(n,dist+abs(k-pindex),2,k,cars+1,2,1);
				visited[k]=0;
			}
		}
	}
	if(ins==1)
	{
		call(n,dist+pindex,2,0,cars,0,0);
	}
	if(ins==2)
	{
		call(n,dist+abs(n+1-pindex),2,n+1,cars,0,1);
	}
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		call(n,0,2,0,0,0,0);
		if(total_dist==999999)
		{
			call(n,n+1,2,n+1,0,0,1);
		}
		cout<<total_dist<<endl;
	}
}
///////////////////////////////////////////////////////////
/////////////////////   9. rock climb
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

clock_t start, end;
double cpu_time_used;

int matrix[MAX_SIZE][MAX_SIZE];
int visited_matrix[MAX_SIZE][MAX_SIZE];

int move[4][2] = {
	1, 0,
	-1, 0,
	0, -1,
	0, 1
};

int check_for_level(int dest_x, int dest_y);
int check_for_last_row(int dest_x, int dest_y, int level);

int row = 0;
int col = 0;

int prob(int x)
{
	if (rand() % 100 < x)
		return 1;
	else
		return 0;
}

void init_visited_matrix()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	for (j = 0; j < MAX_SIZE; j++)
		visited_matrix[i][j] = 0;
}

void print_matrix(int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	srand(10);
	int i, j, m, n, p, t, ans, loc_x, loc_y;
	int tc = 50;
	start = clock();
	for (t = 0; t < tc; t++)
	{
		m = 20 + rand() % 30;
		n = 20 + rand() % 30;

		//For safety, fill the whole matrix with -1 to start with
		for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = -1;


		//Fill the left corner with 2
		matrix[m - 1][0] = 2;

		//Fill the last line with all 1
		for (i = 1; i < n; i++)
			matrix[m - 1][i] = 1;

		//Pick a random location and fill it with 3
		loc_x = rand() % m;
		loc_y = rand() % n;
		matrix[loc_x][loc_y] = 3;

		//pick a random probability between 40 to 60 to fill with 1
		p = 0 + rand() % 20;

		//fill the rest of the matrix with 1s and 0s with probability p

		for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (-1 == matrix[i][j])
			{
				if (prob(p))
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}
		row = m;
		col = n;
		//print_matrix(m,n);
		
		ans = check_for_level(loc_x, loc_y);
		
		//printf("Row %d Col %d Loc_x %d Loc_y %d\n", m, n, loc_x, loc_y);
		printf("Case#%d: %d\n", t, ans);

	}
	end = clock();
	cpu_time_used = ((double)(end - start));
	printf("%lf\n", cpu_time_used);
	return 0;
}

int check_for_level(int dest_x, int dest_y)
{
	int level = 1;
	while (1)
	{
		init_visited_matrix();
		visited_matrix[dest_x][dest_y] = 1;
		if (1 == check_for_last_row(dest_x, dest_y, level))
		{
			return level;
		}
		level++;
	}
}

int check_for_last_row(int dest_x, int dest_y, int level)
{
	if (dest_x == row-1)
		return 1;

	int k, temp_x, temp_y;
	for (k = 0; k < (2 + 2 * level); k++)
	{
		if (k < 4)
		{
			temp_y = dest_y + move[k][1];
			temp_x = dest_x + move[k][0];
		}
		else
		{
			temp_y = dest_y;
			temp_x = dest_x + (k/2)*move[k%2][0];
		}
		if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col)
		{
			if (matrix[temp_x][temp_y] == 1 && visited_matrix[temp_x][temp_y] == 0)
			{
				visited_matrix[temp_x][temp_y] = 1;
				if (1 == check_for_last_row(temp_x, temp_y, level))
					return 1;
			}
		}
	}
	return 0;
}
/////////////////////////////////////////////////
///////////////     10. ballon
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int nums[n];
		for(i=0;i<n;i++)
		{
			cin>>nums[i];
		}
		int dp[n][n];
		int val;
		memset(dp,0,sizeof(dp));
		for(i=0;i<n;i++)
		{
			int prev=(i-1<0)?1:nums[i-1];
			int next=(i+1==n)?1:nums[i+1];
			dp[i][i]=prev*next;
		}
		for(int l=2;l<=n;l++)
		{
			for(i=0;i<n-l+1;i++)
			{
				j=i+l-1;
				for(k=i;k<=j;k++)
				{
					if(l==n)
					{
						val=nums[k]+(k-1<0?0:dp[i][k-1])+(k+1==n?0:dp[k+1][j]);
					}
					else
					{
						int prev,next;
						prev=(i-1<0)?1:nums[i-1];
						next=(j+1==n)?1:nums[j+1];
						val=prev*next+(k==i?0:dp[i][k-1])+(k==j?0:dp[k+1][j]);
					}
					dp[i][j]=max(dp[i][j],val);
				}
			}
		}
		cout<<dp[0][n-1]<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
///////////////////////////////////
////////////    11. toll gate
#include<bits/stdc++.h>
using namespace std;
int n;
void call(vector<vector<int> >&toll,int sum,int &pay,int m1,int m2,int m3,int i)
{
	int tot_battle=m1+m2+m3;
	if(sum>pay)
	{
		return;
	}
	if(i==n-1)
	{
		if(tot_battle>toll[i][0])
		{
			pay=min(sum,pay);
		}
		pay=min(sum+toll[i][1],pay);
		return;
	}
	call(toll,sum+toll[i][1],pay,m1,m2,m3,i+1);
	call(toll,sum+2*toll[i][1],pay,m1,m2,m3+toll[i][0],i+1);
	if(tot_battle>=toll[i][0])
	{
		if(m1+m2<toll[i][0])
		{
			m3=tot_battle-toll[i][0];
			m2=0;
			m1=0;
		}
		else if(m1<toll[i][0])
		{
			m2=(m1+m2)-toll[i][0];
			m1=0;
		}
		call(toll,sum,pay,m2,m3,0,i+1);
	}
}
int main()
{
	int t,i,j,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<vector<int> >toll(n,vector<int>(2));
		for(i=0;i<n;i++)
		{
			cin>>toll[i][0]>>toll[i][1];
		}
		int pay=INT_MAX;
		call(toll,0,pay,0,0,0,0);
		cout<<pay<<endl;
	}
}
///////////////////////////////////////////////////////
/////////////////     12. tunnel
#include <stdio.h>
int S[16][501];
int N,H,V;
int ans[16];
int final_min_cost= 60000000;// VERY_LARGE(taken around 60000000)
int new_cost;
int main()
{
	int i,j,k1,k2,v,T,test_case;
	int C1,C2,R1,R2,M1,M2;
	int max=60000000;// VERY_LARGE(60000000)
	int cost=0;
	int n1,n2,n3,n4,n5;
	scanf("%d",&T);
	for(test_case=1;test_case<=T;test_case++)
	{
		for(i=0;i<16;i++)
		{
			for(j=0;j<501;j++)
				S[i][j]=0;
		}
		for(i=0;i<16;i++)
			ans[i]=0;
		final_min_cost= 60000000;
		scanf("%d%d%d",&N,&H,&V);
		for(i=1;i<=V;i++)
		{
			for(j=1;j<=H;j++)
				scanf("%d",&S[i][j]);
		}
		scanf("%d%d%d",&C1,&R1,&M1);
		scanf("%d%d%d",&C2,&R2,&M2);

		// all inputs scanned..
		//Logic starts here
		for(v=1;v<=V;v++)  // for all the possible tunnels, find the min cost
		{
			max= 60000000;
			for(k1=0;k1<=H;k1++) // k1=0 means machine 1 works for 0 days
			{
				k2=H-k1; // k2 indicates the number of days machine 2 will work
				for(i=0;i<=k1;i++)
					cost = cost + (S[v][i]*C1);
				for(j=H;j>k1;j--)
					cost = cost + (S[v][j]*C2);
				// we have to add the cost for consecutive work.. that will be based on the number of days machine 1 and 2 have to work.. ie. k1 and k2
				if(k1>k2)// machine 1 has to work for more days than machine 2
					cost= cost + ((k1-k2-1)*R1);
				else if (k2>k1)// machine 2 has to work for more days than machine 1
					cost= cost + ((k2-k1-1)*R2);
				// this can be inferred from the example they have shown.. no need to take the combinations... since min cost will come if machines work alternate
				if(max>=cost)
					max=cost;
				cost=0; // for next iteration.
			}
			ans[v]=max; // for every possible tunnel, find the min cost
		}
		// we have to find the combination for N number of tunnels out of V possible tunnels such that cost is min
		if(N==1)
		{
			for(n1=1;n1<=V;n1++)
			{
				if(final_min_cost>=ans[n1])
					final_min_cost=ans[n1];
			}
		}
		else if(N==2)// 2 tunnels
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=V;n2++)
				{
					new_cost= ans[n1]+ans[n2]+ (M1*M1 + M2*M2)*(n2-n1);
					if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
				}
			}

		}
		else if(N==3) 
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++) // notice that n2<= V-((N-2)*2)... for n1 it is (N-1)
				{
					for(n3=n2+2;n3<=V;n3++)
					{
						new_cost= ans[n1]+ans[n2]+ ans[n3] + (M1*M1 + M2*M2)*(n3-n1); // last ie. n3 minus first ie. n1 (n3-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
					}
				}
			}
		}
	//	similarly... go for (N==4) and (N==5) // using nested loops :)
		else if(N==4)
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++)
				{
					for(n3=n2+2;n3<=(V-((N-3)*2));n3++)
					{
						for(n4=n3+2;n4<=V;n4++)
						{
							new_cost= ans[n1]+ans[n2]+ ans[n3] + ans[n4] + (M1*M1 + M2*M2)*(n4-n1); // last ie. n4 minus first ie. n1 (n4-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
						}
					}
				}
			}
		}
		else if (N==5)
		{
			//similar code
		}
		//in place of nested loops, you can find some other way to cover all the cases

			printf("#%d %d\n",test_case,final_min_cost);
	}
	return 0;
}
////////////////////////////////////////
//////////////   13. sky map
/*
In Practice, You should use the statndard input/output
in order to receive a score properly.
Do not use file input and output. Please be very careful.
*/

#include <stdio.h>
#define MAX_ROW 25
#define MAX_COL 25
int N;
int data[MAX_ROW][MAX_COL];
int visited[MAX_ROW][MAX_COL];
int max_star_count;
int num_constellation;

int traverse(int i, int j)
{
    int star_count = 0;

    //if boundary is met, then return
    if (i < 0 || j < 0 || i >= MAX_ROW || j >= MAX_COL)
        return 0;

    //if already visited or zero value
    if ((data[i][j] == 0) || visited[i][j])
        return 0;

    visited[i][j] = 1;
    star_count++;

    star_count += traverse(i, j + 1);
    star_count += traverse(i + 1, j);
    star_count += traverse(i, j - 1);
    star_count += traverse(i - 1, j);

    return star_count;

}

int main(void)
{
    int test_case;
    int T;
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (test_case = 0; test_case < T; test_case++)
    {
        int i, j, temp;
        int S, C;

        int star_count = 0;
        //reset the variables back to zero
        N = 0;
        num_constellation = 0;
        max_star_count = 0;
        for (i = 0; i < MAX_ROW; i++)
        {
            for (j = 0; j < MAX_COL; j++)
            {
                data[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        scanf("%d", &N);

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                scanf("%d", &temp);
                data[i][j] = temp;
            }
        }
        //start traversing the array for constellation search, unit-by-unit
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if ((data[i][j] == 1) && (!visited[i][j]))
                {
                    num_constellation++;
                    star_count += traverse(i, j);
                }

                if (star_count > max_star_count)
                    max_star_count = star_count;
                //reset the star count after each constellation visit
                star_count = 0;
            }
        }

        S = max_star_count;
        C = num_constellation;

        // Print the answer to standard output(screen).
        printf("%d %d\n", C, S);

    }

    return 0;//Your program should return 0 on normal termination.
}
/////////////////////////////////////////////
////////////////  14. chessmap
#include <stdio.h>
#define INF 999999
#define MAX_SIZE 51
int chessmap[MAX_SIZE][MAX_SIZE];
int rowsize = 0;
int colsize = 0;
int Answer = 0;
int start_x = 0;
int start_y = 0;
int end_x = 0;
int end_y = 0;


void traverse(int i, int j, int counter)
{
    //return if array out of bounds
    if ((i < 1) || (j < 1) || (i > rowsize) || (j > colsize))
        return;
    //return if destination has reached
    if ((i == end_x) && (j == end_y))
    {
        if (counter < Answer)
            Answer = counter;
        return;
    }
    //This question does not need forward condition check
    //like skymap has 0 condition check, same is the case with DFS

    //pruning, if needed
    if (counter > Answer)
        return;

    //visiting and already visited place
    if (chessmap[i][j] > 0)
    {
        if (chessmap[i][j] > counter)
            chessmap[i][j] = counter;
        else
            return;
    }

    //do the needful in this step
    chessmap[i][j] = counter;

    //traverse further positions
    traverse(i + 2, j + 1, counter + 1);
    traverse(i + 2, j - 1, counter + 1);

    traverse(i - 2, j + 1, counter + 1);
    traverse(i - 2, j - 1, counter + 1);

    traverse(i + 1, j + 2, counter + 1);
    traverse(i - 1, j + 2, counter + 1);

    traverse(i + 1, j - 2, counter + 1);
    traverse(i - 1, j - 2, counter + 1);

    return;
}

int main(void)
{
    int tc, T;
    int i, j;

    //freopen("chess_sample_input.txt", "r", stdin);


    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        //reset all variables before starting the test case
        rowsize = 0;
        colsize = 0;
        Answer = INF;
        start_x = 0;
        start_y = 0;
        end_x = 0;
        end_y = 0;

        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                chessmap[i][j] = 0;
            }
        }



        scanf("%d", &rowsize);
        scanf("%d", &colsize);

        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);

        traverse(start_x, start_y, 0);

        // Print the answer to standard output(screen).
        printf("%d \n", Answer);


    }

    return 0;//Your program should return 0 on normal termination.
}
////////////////////////////////////////////////////////////////////
/////////// 15. matrix chem substance
#include <stdio.h>

int map[102][102];
int visited[102][102];
int row=0;
int col=0;
int count=0;
int N;

typedef struct C{
	int row;
	int col;
	int size;
}container;

container Ctr[102];

int traverse_data(int x, int y)
{
	if(x<0||x>=N||y<0||y>=N)
		return 0;
	if(map[x][y]==0)
		return 0;
	if(visited[x][y])
		return 0;

	visited[x][y]=1;
	
	if(traverse_data(x,y+1))
	{
		count++;
		
	}
	if(traverse_data(x+1,y))
	{
		count++;
		
	}
	return 1;
}

void swap(int x, int y)
{

	container temp;
	temp = Ctr[x];
	Ctr[x]= Ctr[y];
	Ctr[y] = temp;
}
int partition(int l, int h)
{
	int x = Ctr[h].size;
	int i = l-1;
	int j;

	for(j=l;j<h;j++)
	{
		if(Ctr[j].size<x)
		{
			i++;
			swap(i,j);
		}
	}
	swap(i+1,j);

   return i+1;

}
void quick_sort(int l, int h)
{
	int p;
	if(l<h)
	{
		p = partition(l,h);
		quick_sort(l,p-1);
		quick_sort(p+1,h);
	}
}

void find_row_col(int i, int j)
{

   while(visited[i][j])
   {
	   col++;
	   j++;
   }

   
   row = count/col;
}


int main(void)
{
	int test_case;
	int T;
	int i,j,k;
	int c=0;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	   Read each test case from standard input.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&map[i][j]);
				visited[i][j]=0;
			}
		}

		
		
		c=0;
		count = row = col =0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j] && !visited[i][j])
				{
					count+=traverse_data(i,j);
					find_row_col(i,j);
					Ctr[c].size = count;
					Ctr[c].row = row;
					Ctr[c].col = col;
					c++;
					count = row = col =0;
				}
			}
		}
		
		if(c>0)
		{
		quick_sort(0,c-1);

		
		// Print the answer to standard output(screen). 
		printf("#%d ", test_case);
		printf("%d ",c);
		i=0;
		while(i<c)
		{
			
			if(Ctr[i].size<Ctr[i+1].size)
			{
				printf("%d %d ",Ctr[i].row,Ctr[i].col);
				i++;
			}
			else  //Same Rect size
			{
				bool bswap= false;
				for(j=i;j<c;j++)
				{
					bswap = false;
					for(k=i;k<c-j-1;k++)
					{
						if(Ctr[j].size==Ctr[j+1].size)
						{
							if(Ctr[j].row>Ctr[j+1].row)
							{
								swap(j,k);
								bswap = true;
							}

						}
					}
					if(swap==false) //No elements are swapped by inner loop- so break
					break;
				}

				printf("%d %d ",Ctr[i].row,Ctr[i].col);
				i++;
			}
			
		}
		
		}
		else
		{
			printf("#%d ", test_case);
			printf("0");
		}
		printf("\n");
	}
	return 0; //Your program should return 0 on normal termination.
}
/////////////////////////////////////////////////////////////
////////////////////////  16. rare elements
#include<bits/stdc++.h>
using namespace std;
int n;
int dir[2][4]={{-1,1,0,0},{0,0,-1,1}};
bool isvalid(int x,int y)
{
	if(x<0||y<0||x>=n||y>=n)
		return false;
	return true;
}
void bfs(vector<vector<int> >&mat,vector<vector<int> >&final_dist,int x,int y)
{
	int i,j;
	vector<vector<int> >dist(n,vector<int>(n,0));
	queue<pair<int,int> >Q;
	Q.push(make_pair(x,y));
	vector<vector<bool> >visited(n,vector<bool>(n,false));
	visited[x][y]=true;
	while(!Q.empty())
	{
		pair<int,int>pp=Q.front();
		Q.pop();
		for(i=0;i<4;i++)
		{
			int next_x=pp.first+dir[0][i];
			int next_y=pp.second+dir[1][i];
			if(isvalid(next_x,next_y)&&!visited[next_x][next_y]&&mat[next_x][next_y]==1)
			{
				dist[next_x][next_y]=dist[pp.first][pp.second]+1;
				Q.push(make_pair(next_x,next_y));
				visited[next_x][next_y]=true;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			final_dist[i][j]=max(final_dist[i][j],dist[i][j]);
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	int t,c,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		int rare[c][2];
		for(i=0;i<c;i++)
		{
			cin>>rare[i][0]>>rare[i][1];
			rare[i][0]--;
			rare[i][1]--;
		}
		vector<vector<int> >mat(n,vector<int>(n));
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>mat[i][j];
			}
		}
		vector<vector<int> >final_dist(n,vector<int>(n,0));
		for(int k=0;k<c;k++)
		{
			bfs(mat,final_dist,rare[k][0],rare[k][1]);
		}
		int ans=INT_MAX;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(mat[i][j])
				ans=min(ans,final_dist[i][j]);
			}
		}
		cout<<ans<<endl;
	}
}
///////////////////////////////////////////////////////////
///////////////// 17 . laughing bomb

#include <stdio.h>
#define MAX_SIZE 101
int citymap[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int Answer;
int row_size = 0;
int col_size = 0;
int bomb_row, bomb_col;

void traverse(int row, int col, int cur_value)
{
    //check booundary condition
    if ((row < 1) || (row > row_size) || (col < 1) || (col > col_size))
        return;

    //check for data-retrun condition in the map
    if (citymap[row][col] == 0)
        return;
    //depth check
    
    //check for visited or anyother condition given additionally like compatibilit of traversal etc
    if (visited[row][col])
    {
        if(citymap[row][col] > cur_value)
        {
            citymap[row][col] = cur_value;
        }
        else
        {
            return;
        }
    }
    else
    { //if not returning , execute steps at this level
        visited[row][col] = 1;
        citymap[row][col] = cur_value;
    }

    //traverse forward once done with this level
    traverse(row, col+1, cur_value + 1);
    traverse(row+1, col, cur_value + 1);
    traverse(row, col-1, cur_value + 1);
    traverse(row-1, col, cur_value + 1);

    return;
}

int main(void)
{
    int tc, T;

    int i, j;


     //freopen("sample_input_laughingbomb_debug.txt", "r", stdin);

    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        //reset all varaiables
        row_size = 0;
        col_size = 0;

        bomb_row = 0;
        bomb_col = 0;

        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                citymap[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        Answer = 0;

        scanf("%d", &col_size);
        scanf("%d", &row_size);


        for (i = 1; i <= row_size; i++)
        {
            for (j = 1; j <= col_size; j++)
            {
                scanf("%d", &citymap[i][j]);
            }
        }

        scanf("%d %d", &bomb_col, &bomb_row);
        citymap[bomb_row][bomb_col] = 1;
        traverse(bomb_row, bomb_col,1);
        

        
        for (i = 1; i <= row_size; i++)
        {
            for (j = 1; j <= col_size; j++)
            {
                if (Answer < citymap[i][j])
                    Answer = citymap[i][j];
            }
            
        }

        printf("%d \n", Answer);
    }

    return 0;//Your program should return 0 on normal termination.
}
/////////////////////////////////////////////////
/////////////////// 18. air fare
#include <stdio.h>
int input[15][15];
int G_cost = 0xFFFFFF;
int visited[15];

int calculate(int in, int n_cities, int cities_covered, int local_cost)
{
    int i, j;

    if (cities_covered >= n_cities && input[in][1])
    {
        if (local_cost + input[in][1] < G_cost)
        {
            G_cost = local_cost + input[in][1];
        }
        return 1;
    }

    if (local_cost > G_cost) return 1;


    for (j = 1; j <= n_cities; j++)
    {
        if (input[in][j] && !visited[j] && in != j)
        {
            visited[j] = 1;
            calculate(j, n_cities, cities_covered + 1, local_cost + input[in][j]);
            visited[j] = 0;

        }
    }

}

int main(void)
{
    int tc, T, i, j, fare;
    int num_cities = 0;

    scanf("%d", &T);
    for (tc = 0; tc < T; tc++)
    {
        G_cost = 0xFFFF;
        scanf("%d", &num_cities);

        for (i = 1; i <= num_cities; i++)
        {
            for (j = 1; j <= num_cities; j++)
            {
                scanf("%d", &fare);
                input[i][j] = fare;
            }
        }
        visited[1] = 1;
        calculate(1, num_cities, 1, 0);
        printf("%d\n", G_cost);
    }
    return 0;//Your program should return 0 on normal termination.
}
/////////////////////////////////////////////////////
///////////////////// 19. picking jewels
#define MAXN 11
#include<stdio.h>
int N;
int map[MAXN][MAXN];
int visited[MAXN][MAXN];

int num_jewels;

int path[MAXN][MAXN];

void traverse(int x, int y, int jewel_cnt)
{
    int i, j;
    if (x<1 || x>N || y<1 || y>N || map[x][y] == 1 || visited[x][y])
        return;

    if (y == N && x == N)
    {
        if (num_jewels <= jewel_cnt)
        {
            num_jewels = jewel_cnt;

            //Take a snapshot of the path
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if (visited[i][j] == 3)
                        path[i][j] = 3;
                    else
                        path[i][j] = map[i][j];
                }
            }
            path[x][y] = 3;
        }
        return;
    }

    visited[x][y] = 3;
    if (map[x - 1][y] == 2)
        traverse(x - 1, y, jewel_cnt + 1);
    else
        traverse(x - 1, y, jewel_cnt);
    if (map[x + 1][y] == 2)
        traverse(x + 1, y, jewel_cnt + 1);
    else
        traverse(x + 1, y, jewel_cnt);
    if (map[x][y - 1] == 2)
        traverse(x, y - 1, jewel_cnt + 1);
    else
        traverse(x, y - 1, jewel_cnt);
    if (map[x][y + 1] == 2)
        traverse(x, y + 1, jewel_cnt + 1);
    else
        traverse(x, y + 1, jewel_cnt);
    visited[x][y] = 0;
}

int main(void)
{
    int tc, T;

    //freopen("pick_jewel.txt","r",stdin);
    setbuf(stdout, NULL);
    scanf("%d", &T);

    for (tc = 0; tc<T; tc++)
    {
        int i, j;
        scanf("%d", &N);
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                scanf("%d", &map[i][j]);
                path[i][j] = map[i][j];
                visited[i][j] = 0;
            }
        }
        num_jewels = 0;
        traverse(1, 1, 0);

        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
        printf("%d\n\n", num_jewels);
    }
    return 0;
}
/////////////////////////
