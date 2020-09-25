#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct xy{int p,d,t;}temp;
int f,c,r=2e9,n,m,k,t,tt,p,d,p1,raka[100001],ton[100001],mem[100001],timee[100001];
bool v,ch[100001];
vector<xy> a[100002];
queue<xy> Q;
main()
{
	scanf("%d %d %d %d",&n,&m,&k,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %d",&p1,&p,&d,&tt);
		temp.p=p,temp.d=d,temp.t=tt;
		a[p1].push_back(temp);
		temp.p=p1;
		a[p].push_back(temp);
	}
	for(int i=0;i<k;i++)
		scanf("%d %d",&raka[i],&ton[i]);
	for(int i=2;i<=n;i++) mem[i]=INT_MAX;
	temp.p=1,temp.d=0,temp.t=0;
	Q.push(temp),ch[1]=true;
	while(!Q.empty())
	{
		temp=Q.front();
		int x=temp.p,f=temp.d,c=temp.t;
		if(x==n && mem[x]>f) {
			mem[x] = f;
			timee[x] = c;
		}
		//printf("%d   <-\n",x);
		Q.pop();
		for(int i=0;i<a[x].size();++i)
		{
			p=a[x][i].p,d=a[x][i].d,tt=a[x][i].t;
			if(!ch[p] && c+tt<=t)
			{
			//	if(mem[p]>f+d)
			//	{
					
					ch[p]=true;
					mem[p]=f+d;
					timee[p]=c+tt;
					temp.p=p,temp.d=f+d,temp.t=c+tt;
					Q.push(temp);
			//	}
			//	else if(mem[p]==f+d)
				//{
				//	if(timee[p]>c+tt)
				//	{
//						ch[p]=true;
//						timee[p]=c+tt;
//						temp.p=p,temp.d=f+d,temp.t=c+tt;
//						Q.push(temp);
//					}
//				}
			}
		}
	}
//	for(int i=1;i<=n;i++) printf("%d    %d    %d\n",i,mem[i],timee[i]);
	if(mem[n]==INT_MAX)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		if(ton[i]>=mem[n]&&raka[i]<r)
		{
			r=raka[i];
			v=true;
		}
	}
	if(v) printf("%d",r);
	else printf("-1");
}
