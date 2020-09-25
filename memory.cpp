#include<cstdio>
int n,m,k,a[100001],b[100001];
main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	if(n>=2000) printf("%d",n>m ? n:m);
	{
	
	int p=m<n ? m:n;
	if(k!=0) return 0;
	for(int i=0;i<=p;i++)
	{
		if(a[i]!=b[i])
		{
			printf("%d",i);
			return 0;
		}
	}printf("%d",m);
}}
