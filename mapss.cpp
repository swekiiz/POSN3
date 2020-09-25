#include<cstdio>
#include<queue>
using namespace std;
struct xy {int up,down,left,right;};
struct noww {int q,y,x;};
int m,n,mymap[500][500],pt,t,tt;
char ct;
xy W[50000];
bool ch[50000];
main()
{
	scanf("%d %d",&m,&n);
	pt=m*n;
	for(int i=1;i<pt;i++)
	{
		scanf("%d %c %d",&t,&ct,&tt);
		if(ct=='U')
		{
			W[t].down=tt;
			W[tt].up=t;
		}
		if(ct=='L')
		{
			W[t].right=tt;
			W[tt].left=t;
		}
	}
	queue<noww> Q;
	noww tem={0,250,250};
	Q.push(tem);
	while(!Q.empty())
	{
		noww yy=Q.front();
		Q.pop();
		noww rtm;
		int tp=yy.q,x=yy.x,y=yy.y;
		mymap[y][x]=tp;
		if(!ch[W[tp].up]&&W[tp].up!=0)
		{
			ch[W[tp].up]=true;
			rtm.q=W[tp].up,rtm.y=y-1,rtm.x=x;
			Q.push(rtm);
		}
		if(!ch[W[tp].down]&&W[tp].down!=0)
		{
			ch[W[tp].down]=true;
			rtm.q=W[tp].down,rtm.y=y+1,rtm.x=x;
			Q.push(rtm);
		}
		if(!ch[W[tp].left]&&W[tp].left!=0)
		{
			ch[W[tp].left]=true;
			rtm.q=W[tp].left,rtm.y=y,rtm.x=x-1;
			Q.push(rtm);
		}
		if(!ch[W[tp].right]&&W[tp].right!=0)
		{
			ch[W[tp].right]=true;
			rtm.q=W[tp].right,rtm.y=y,rtm.x=x+1;
			Q.push(rtm);
		}
	}
	for(int i=0;i<500;i++)
	{
		bool hy=false;
		for(int j=0;j<500;j++)
		{
			if(mymap[i][j]!=0||(i==250&&j==250))
			{
				printf("%d ",mymap[i][j]);
				hy=true;
			}
		}
		if(hy) puts("");
	}
}
