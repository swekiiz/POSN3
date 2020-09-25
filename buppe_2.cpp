#include<iostream>
#include<queue>
using namespace std;
struct xy{int y,x,w;};
bool mapa[102][102];
int ans[102][102],yu,n,m,x1,y1,x2,y2;
main()
{
	cin>>n>>m>>y1>>x1>>y2>>x2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>yu;
			if(yu==1) mapa[i][j]=true;
			else mapa[i][j]=false;
		}
	queue<xy> Q;
	xy temp={y1,x1,0};
	Q.push(temp);
	while(!Q.empty())
	{
		int w=Q.front().w,x=Q.front().x,y=Q.front().y;
		Q.pop();
		if(mapa[y][x]==true) continue;
		mapa[y][x]=true;
		ans[y][x]=w;
		if(!mapa[y][x-1]&&x-1>0)
		{
			temp.x=x-1,temp.y=y,temp.w=w+1;
			Q.push(temp);
		}
		if(!mapa[y-1][x]&&y-1>0)
		{
			temp.x=x,temp.y=y-1,temp.w=w+1;
			Q.push(temp);
		}
		if(!mapa[y][x+1]&&x<m)
		{
			temp.x=x+1,temp.y=y,temp.w=w+1;
			Q.push(temp);
		}
		if(!mapa[y+1][x]&&y<n)
		{
			temp.x=x,temp.y=y+1,temp.w=w+1;
			Q.push(temp);
		}
		if(x==x2&&y==y2) break;
	}
	if(mapa[y2][x2]==0) cout<<"-1";
	else cout<<ans[y2][x2];
}
