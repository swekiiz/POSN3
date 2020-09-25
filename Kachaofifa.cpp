#include<cstdio>
#include<algorithm>
using namespace std;
struct pi {int p1,p2,w;};
int fe,v,he[2501],rk[2501],s,k,e,n,m,t1,t2,t3,no;
pi g[1000001];
bool cm(pi a,pi b)
{
	return a.w>b.w;
}
int fi(int x)
{
	if(he[x]==x) return x;
	return he[x]=fi(he[x]);
}
main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		g[fe++]=(pi){t1,t2,t3};
	}
	scanf("%d %d %d",&s,&e,&k);
	for(int i=1;i<2501;i++) he[i]=i;
	sort(g,g+m,cm);
	do
	{
		no=g[v].w,t1=g[v].p1,t2=g[v].p2;
		if(rk[fi(t1)]<=rk[fi(t2)]) he[fi(t1)]=fi(t2),rk[fi(t2)]++;
		else he[fi(t2)]=fi(t1),rk[fi(t1)]++;
		v++;
	}while(fi(s)!=fi(e));no--;
	if(k%no==0) no=k/no;
	else no=k/no+1;
	printf("%d",no);
}
