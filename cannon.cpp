#include<cstdio>
int a[1000002],n,c,m,k,l,t,u;
main()
{
	scanf("%d %d %d %d",&n,&m,&k,&l);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<k;i++)
	{
		c=0;
		int q=0;
		for(int j=0;j<m;j++)
		{
			scanf("%d",&t);
			for(;a[q]<=t+l&&q<n;q++)
			{
				if(a[q]>=t-l&&t+l>=a[q])
					c++;
			}
		}
		printf("%d\n",c);
	}
}
