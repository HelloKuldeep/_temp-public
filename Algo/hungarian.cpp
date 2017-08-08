#include <bits/stdc++.h>
using namespace std;
#define INF 100001
int size1,uu,size2;
int Array[10][10];
char Result[10][10];
void hungarian()
{
int i,j;

unsigned int m=size1,n=size2;
int k;
int l;
int s;
int col_mate[size1];
int row_mate[size2];
int parent_row[size2];
int unchosen_row[size1];
int t;
int q;
int row_dec[size1];
int col_inc[size2];
int slack[size2];
int slack_row[size2];
int unmatched;
int cost=0;

for (i=0;i<size1;++i)
  for (j=0;j<size2;++j)
    Result[i][j]=false;
for (l=0;l<n;l++)
{
  s=Array[0][l];
  for (k=1;k<n;k++)
    if (Array[k][l]<s)
      s=Array[k][l];
  cost+=s;
  if (s!=0)
    for (k=0;k<n;k++)
      Array[k][l]-=s;
}
t=0;
for (l=0;l<n;l++)
{
  row_mate[l]= -1;
  parent_row[l]= -1;
  col_inc[l]=0;
  slack[l]=INF;
}
for (k=0;k<m;k++)
{
  s=Array[k][0];
  for (l=1;l<n;l++)
    if (Array[k][l]<s)
      s=Array[k][l];
  row_dec[k]=s;
  for (l=0;l<n;l++)
    if (s==Array[k][l] && row_mate[l]<0)
    {
      col_mate[k]=l;
      row_mate[l]=k;
      goto row_done;
    }
  col_mate[k]= -1;
  unchosen_row[t++]=k;
row_done:
  ;
}
if (t==0)
  goto done;
unmatched=t;
while (1)
{
  q=0;
  while (1)
  {
    while (q<t)
    {
      {
        k=unchosen_row[q];
        s=row_dec[k];
        for (l=0;l<n;l++)
          if (slack[l])
          {
            int del;
            del=Array[k][l]-s+col_inc[l];
            if (del<slack[l])
            {
              if (del==0)
              {
                if (row_mate[l]<0)
                  goto breakthru;
                slack[l]=0;
                parent_row[l]=k;
                unchosen_row[t++]=row_mate[l];
              }
              else
              {
                slack[l]=del;
                slack_row[l]=k;
              }
          }
        }
      }
      q++;
    }
    s=INF;
    for (l=0;l<n;l++)
      if (slack[l] && slack[l]<s)
        s=slack[l];
    for (q=0;q<t;q++)
      row_dec[unchosen_row[q]]+=s;
    for (l=0;l<n;l++)
      if (slack[l])
      {
        slack[l]-=s;
        if (slack[l]==0)
        {
          k=slack_row[l];
          if (row_mate[l]<0)
          {
            for (j=l+1;j<n;j++)
              if (slack[j]==0)
                col_inc[j]+=s;
            goto breakthru;
          }
          else
          {
            parent_row[l]=k;
            unchosen_row[t++]=row_mate[l];
          }
        }
      }
      else
        col_inc[l]+=s;
  }
breakthru:
  while (1)
  {
    j=col_mate[k];
    col_mate[k]=l;
    row_mate[l]=k;
    if (j<0)
      break;
    k=parent_row[j];
    l=j;
  }
  if (--unmatched==0)
    goto done;
  t=0;
  for (l=0;l<n;l++)
  {
    parent_row[l]= -1;
    slack[l]=INF;
  }
  for (k=0;k<m;k++)
    if (col_mate[k]<0)
    {
      unchosen_row[t++]=k;
    }
}
done:
for (k=0;k<m;k++)
  for (l=0;l<n;l++)
    if (Array[k][l]<row_dec[k]-col_inc[l])
      exit(0);
for (k=0;k<m;k++)
{
  l=col_mate[k];
  if (l<0 || Array[k][l]!=row_dec[k]-col_inc[l])
    exit(0);
}
k=0;
for (l=0;l<n;l++)
  if (col_inc[l])
    k++;
if (k>m)
  exit(0);
for (i=0;i<m;++i)
{
  Result[i][col_mate[i]]=true;
}
for (k=0;k<m;++k)
{
  for (l=0;l<n;++l)
  {
    Array[k][l]=Array[k][l]-row_dec[k]+col_inc[l];
  }
}
for (i=0;i<m;i++)
  cost+=row_dec[i];
for (i=0;i<n;i++)
  cost-=col_inc[i];
printf("%d\n",cost);
}

int main()
{
int y,x,i;
int N;	cin>>N;
size1=N;
size2=N; 

for (y=0;y<N;++y)
  for (x=0;x<N;++x)
    cin>>Array[y][x];

hungarian();    
return 0;
}
