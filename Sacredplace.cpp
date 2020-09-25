#include<iostream>
#include<algorithm>
using namespace std;
struct s {int p1,p2,w;};
bool c(s a,s b)
{
	return a.w>b.w;
}
int he[200001],v,n,d;
unsigned long long su;
s ar[1000002];
int fi(int x)
{
	if(he[x]==x) return x;
	return he[x]=fi(he[x]);
}
main()
{
	cin>>n>>v;
	for(int i=0;i<v;i++)
		cin>>ar[i].p1>>ar[i].p2>>ar[i].w;
	sort(ar,ar+v,c);
	for(int i=1;i<=n;i++) he[i]=i;
	for(int i=0;i<v;i++)
	{
		if(d==n-1) break;
		if(fi(ar[i].p1)!=fi(ar[i].p2))
		{
			he[fi(ar[i].p1)]=fi(ar[i].p2);
			su+=ar[i].w-1;
			d++;
		}
	}
	cout<<su;
}
