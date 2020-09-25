#include<cstdio>
#include<stack>
using namespace std;
struct k {int y,x;};
int n,m,c;
stack<k> s;
bool ch[2002][2002],mem[2002][2002],p[2002][2002];
main()
{
	char t;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;)
		{
			scanf("%1c",&t);
			if(t=='\n') continue;
			if(t=='1')ch[i][j]=1;
			++j;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ch[i][j]&&!mem[i][j])
			{
				c++;
				mem[i][j]=1;
				s.push((k){i,j});
				while(!s.empty())
				{
					int x=s.top().x,y=s.top().y;p[y][x]=1;s.pop();
					if(y!=1&&x!=1&&!p[y-1][x-1]&&ch[y-1][x-1]) {mem[y-1][x-1]=1;s.push((k){y-1,x-1});}
					if(y!=1&&!p[y-1][x]&&ch[y-1][x]) {mem[y-1][x]=1;s.push((k){y-1,x});}
					if(y!=1&&x!=m&&!p[y-1][x+1]&&ch[y-1][x+1]) {mem[y-1][x+1]=1;s.push((k){y-1,x+1});}
					if(x!=1&&!p[y][x-1]&&ch[y][x-1]) {mem[y][x-1]=1;s.push((k){y,x-1});}
					if(x!=m&&!p[y][x+1]&&ch[y][x+1]) {mem[y][x+1]=1;s.push((k){y,x+1});}
					if(y!=n&&x!=1&&!p[y+1][x-1]&&ch[y+1][x-1]) {mem[y+1][x-1]=1;s.push((k){y+1,x-1});}
					if(y!=n&&!p[y+1][x]&&ch[y+1][x]) {mem[y+1][x]=1;s.push((k){y+1,x});}
					if(y!=n&&x!=m&&!p[y+1][x+1]&&ch[y+1][x+1]) {mem[y+1][x+1]=1;s.push((k){y+1,x+1});} 
				}
			}
	printf("%d",c);
}
