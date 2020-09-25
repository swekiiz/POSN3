#include<cstdio>
#include<cstring>
int n,g1,g2,sk,mem[1002][1002][2];
char p1[1002],p2[1002],k[2005];
int dp(int x1,int x2,char t)
{
	bool can=false;
	if(mem[x1][x2][t-65]!=-1) return mem[x1][x2][t-65];
	if(x1==g1&&x2==g2&&sk==x1+x2)
	{ 
		return mem[x1][x2][t-65]=1;
	}
	if(p1[x1]==t)
	{
		if(dp(x1+1,x2,k[x1+x2+1])) can=true;
	}
	if(p2[x2]==t)
	{
		if(dp(x1,x2+1,k[x1+x2+1])) can=true;
	}
	if(can) return mem[x1][x2][t-65]=1;
	return mem[x1][x2][t-65]=0;
}
main()
{
	scanf("%s %s %d",p1,p2,&n);
	g1=strlen(p1),g2=strlen(p2);
	for(int i=0;i<n;i++)
	{
		memset(mem,-1,sizeof(mem));
		scanf("%s",k);
		sk=strlen(k);
		if(dp(0,0,k[0])) printf("Yes\n");
		else printf("No\n");
	}
}
