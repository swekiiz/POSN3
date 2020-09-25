#include<iostream>
#include<cstring>
using namespace std;
bool ch[52][52];
int q,w,a,n,m;
unsigned long long mem[52][52];
unsigned long long int dp(int y,int x)
{
	if(y==1&&x==1) return 1;
	if(x==0||y==0||ch[y][x]) return 0;
	if(mem[y][x]!=-1) return mem[y][x];
	return mem[y][x]=dp(y,x-1)+dp(y-1,x);
}
main()
{
	memset(mem,-1,sizeof(mem));
	cin>>n>>m>>a;
	for(int i=0;i<a;i++)
	{
		cin>>q>>w;
		ch[q][w]=1;
	}
	cout<<dp(n,m);
}
