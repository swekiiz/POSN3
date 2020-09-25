#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct aaa{int pi;long long int w;bool operator <(const aaa &dd)const {return dd.w<w;};}t;
int x,n,p,m,pre[100001],ans[100001];
bool ch[100001];
long long int mem[100001],w;
priority_queue<aaa> S;
vector<aaa> a[100001];
main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) mem[i]=2000000000;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&p,&x,&w);
		t.w=w,t.pi=x;
		a[p].push_back(t);
		t.pi=p;
		a[x].push_back(t);
	}
	t.pi=1,t.w=0;
	S.push(t),ch[1]=true;
	while(!S.empty())
	{
		t=S.top();
		x=t.pi;
		S.pop();
		for(int i=0;i<a[x].size();++i)
		{
			p=a[x][i].pi,w=a[x][i].w;
			if(!ch[p]||mem[p]>w+mem[x])
			{
				ch[p]=true;
				pre[p]=x;
				mem[p]=w+mem[x];
				t.pi=p,t.w=w+mem[x];
				S.push(t);
			}
		}
	}
	if(mem[n]==2000000000)
	{
		printf("-1");
		return 0;
	}
	x=n,p=0;
	A:;
	ans[p++]=x;
	x=pre[x];
	if(x!=0) goto A;
	for(int i=p-1;i>=0;i--) printf("%d ",ans[i]);
}
