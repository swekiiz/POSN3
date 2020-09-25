#include<cstdio>
#include<cstring>
int n,k,ar[1002],mem[1002][302];
int dp(int l,int b)
{
	if(mem[l][b]!=-1) return mem[l][b];
	if(b==1) return mem[l][b]=ar[n]-ar[l-1];
	int mn=2e9;
	for(int i=l;i<=n-b+1;i++)
	{
		int mx=0,t=dp(i+1,b-1),se=0;
		if(mx<t) mx=t;
		se=ar[i]-ar[l-1];
		if(mx<se) mx=se;
		if(mn>mx) mn=mx;
	}
	return mem[l][b]=mn;
}
main()
{
	memset(mem,-1,sizeof(mem));
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{ 
		scanf("%d",&ar[i]);
		ar[i]+=ar[i-1];
	}
	printf("%d",dp(1,k));
}
