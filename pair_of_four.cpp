#include<bits/stdc++.h>
using namespace std;
int n,mem[2001][2001];
char c[2001];
int M[300];
vector<int> m[5];
bool rg=true;
int dp(int x,int y)
{
	if(y<=x) return 0;
	if(mem[x][y] != -1) 
		return mem[x][y];
	int mx=-1,len = m[ M[c[x]] ].size();
		
	for(int i=0;i<len;i++)
	{
		if(m[ M[c[x]] ][i]<=y && m[ M[c[x]] ][i]>x)
			mx = max( mx , dp(x+1 , m[ M[c[x]] ][i]-1 )+dp( m[ M[c[x]] ][i]+1,y)+1 );
	}
	
	return mem[x][y] = max(dp(x+1,y),mx);
}

main(){
	M['U']=0,M['B']=1,M['O']=2,M['N']=3;
	scanf("%d",&n);
	memset(mem,-1,sizeof(mem));
	for(int i=0;i<n;i++){
		scanf(" %c",&c[i]);
		m[M[c[i]]].push_back(i);
	}
	printf("%d",dp(0,n-1));
}
