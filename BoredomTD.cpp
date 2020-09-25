#include<iostream>
#include<cstring>
using namespace std;
int n,g,mx;
long long int a[100002],mem[100002];
long long int dp(int x)
{
	if(mem[x]!=-1) return mem[x];
	if(x<=0) return 0;
	return mem[x]=(dp(x-1)>dp(x-2)+a[x]*x) ? dp(x-1):dp(x-2)+a[x]*x;
}
main()
{
	memset(mem,-1,sizeof(mem));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>g;
		a[g]++;
		if(mx<g) mx=g;
	}
	cout<<dp(mx);
}
