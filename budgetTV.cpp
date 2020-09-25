#include<cstdio>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
struct mst{int pi,w;bool operator <(const mst &ll)const{return ll.w<w;};}tem;
vector<mst> a[10001];
priority_queue<mst> S;
bool ch[10001];
int ne,w,st,ed,n,m,wl,t1,t2,t3,mems[10001],pre[10001],kad[10001],tg[10001];
main()
{
	for(int i=0;i<10001;i++) tg[i]=kad[i]=mems[i]=INT_MAX,pre[i]=-1;
	scanf("%d %d %d %d %d",&n,&m,&st,&ed,&wl);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		tem.pi=t2,tem.w=t3;
		a[t1].push_back(tem);
		tem.pi=t1,tem.w=t3;
		a[t2].push_back(tem);
	}
	tem.pi=st,tem.w=0;
	S.push(tem);
	mems[st]=0,pre[st]=st;
	while(!S.empty())
	{
		tem=S.top();S.pop();
		int x=tem.pi;
		for(int i=0;i<a[x].size();i++)
		{
			ne=a[x][i].pi,w=a[x][i].w;
			if(mems[x]==INT_MAX)
			{
				if(mems[ne]==INT_MAX)
				{
					if(kad[ne]>kad[x]+w) 
					{
						tg[ne]=tg[x],kad[ne]=kad[x]+w;
						tem.pi=ne,tem.w=w;
						S.push(tem);
					}
				}
			}
			else if(!ch[ne]||mems[ne]>mems[x]+w)
			{
				ch[ne]=true;
				if(mems[x]+w<=wl)
				{
					pre[ne]=x;
					mems[ne]=mems[x]+w;
				}
				else
				{
					if(kad[ne]==w&&mems[ne]==INT_MAX) if(tg[ne]>x) tg[ne]=x;
					if(kad[ne]>w&&mems[ne]==INT_MAX) kad[ne]=w,tg[ne]=x;
				}
				tem.pi=ne,tem.w=w;
				S.push(tem);
			}
		}
	}
	if(mems[ed]!=INT_MAX) printf("%d %d 0",ed,mems[ed]);
	else printf("%d %d %d",tg[ed],mems[tg[ed]],kad[ed]);
}











