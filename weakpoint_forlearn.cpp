#include<bits/stdc++.h>
using namespace std;
vector<int> a[500001];
int n,m,t1,t2,mx=-1,y;
bool ch[500001],cycle_check[500001];

int dp(int x)
{
	int sum=0,t=0;
	bool in_circle=false;
	
	if(a[x].size()==1 && x!=m) 
		return 1;
	
	for(int i=0;i<a[x].size();++i)
	{
		if(!ch[a[x][i]])
		{
			ch[a[x][i]] = true;
			t = dp(a[x][i]);
			sum += t;
			if(t==0) 
				in_circle=true;
		}
		else if(a[x][i]==m) 
			in_circle=true;
	}
	
	if( mx < sum && x!=m ) 
		mx = sum , y = x;
	else if(mx == sum && x!=m && x<y) 
			y=x;
	
	if(in_circle || cycle_check[x])
	{ 
		cycle_check[x]=true;
		return 0;
	}
	return sum+1;
}

main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&t1,&t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	ch[m]=true;
	dp(m);
	printf("%d\n%d",y,mx);
}
