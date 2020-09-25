#include<cstdio>
int n,m,qs[2002][2002];
main()
{
	char c[2002];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c);
		for(int j=1;j<=m;j++)
			qs[i][j]+=(c[j-1]-'0')+qs[i-1][j]-qs[i-1][j-1]+qs[i][j-1];
	}
	int l=1,r=(n>m) ? n:m,md;
	do
	{
		if(l==r)
		{
			md=r;
			break;
		}
		bool c=false;
		md=(l+r)/2;
		if(l+1==r) md++;
		for(int i=0;i<=n-md;i++)
		{
			for(int j=0;j<=m-md;j++)
			{
				if(qs[md+i][md+j]-qs[i][md+j]-qs[md+i][j]+qs[i][j]==0)
					c=true;
				if(c) break;
			}
			if(c) break;
		}
		if(c) l=md;
		else r=md-1;
	}while(l<=r);
	printf("%d",md);
}
