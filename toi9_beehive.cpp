#include<iostream>
int arr[1002][1002],n,m,mx,co;
void walk(int pb,int x,int y)
{
	int _=pb+arr[y][x];
	if(y+1==m)
	{
		if(mx==_) co++;
		else if(mx<_) mx=_,co=1;
		return;
	}
	if(y%2==0)
	{
		if(x-1>=0) walk(_,x-1,y+1);
		walk(_,x,y+1);
	}
	else
	{
		walk(_,x,y+1);
		if(x+1<n) walk(_,x+1,y+1);
	}
}
main()
{
	std::cin>>m>>n;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			std::cin>>arr[i][j];
	for(int i=0;i<n;++i) walk(0,i,0);
	std::cout<<mx<<' '<<co;
} 
