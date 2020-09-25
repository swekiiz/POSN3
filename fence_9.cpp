#include<cstdio>
#include<algorithm>
int t,w,l,r,md,n,m,k,y,x,qs[502][502],p;
bool b;
main()
{
	for(int qw=0;qw<=1;qw++)
	{
		t=0,w=0,l=0,r=0,md=0,n=0,m=0,k=0,y=0,x=0,p=0;
		for(int i=0;i<=502;i++) for(int j=0;j<=502;j++) qs[i][j]=0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d %d",&y,&x);
			qs[y+1][x+1]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
		r=std::min(n,m);
		for(p=r;p>=0;p--)
		{
			b=false;
			md=p;
			for(int i=md;i<=n;i++)
			{
				for(int j=md;j<=m;j++)
				{
					t=qs[i][j]-qs[i][j-md]-qs[i-md][j]+qs[i-md][j-md];
					w=qs[i-1][j-1]-qs[i-1][j-md+1]-qs[i-md+1][j-1]+qs[i-md+1][j-md+1];
					if(t-w==0) b=true;
				}
			}
			if(b) 
			{
				printf("%d\n",p);
				break;
			}
		}
	}
}
