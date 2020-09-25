#include<cstdio>
#define miin(a,b) a<b ? a:b
long long int n,k,a[1000001],h,l,r,md,p=2e13;
main()
{
	scanf("%lld %lld",&n,&k);
	for(long long int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	l=0,r=1e13+1;
	while(l<=r)
	{
		h=0;
		md=(l+r)/2;
		for(long long int i=0;i<n;i++)
			h+=(md/a[i]);
		if(h>=k) r=md-1,p=miin(md,p);
		else l=md+1;
	}
	printf("%lld",p);
}
