#include<cstdio>
#include<vector>
using namespace std;
vector<int> a[500001];
int n,k,t1,t2,mx=-1,in;
bool ch[500001],lp[500001];
int po(int x)
{
	int s=0,u=0;
	bool b=false;
	if(a[x].size()==1&&x!=k) return 1;
	for(int i=0;i<a[x].size();++i)
	{ 
		if(!ch[a[x][i]])
		{
			ch[a[x][i]]=true;
			u=po(a[x][i]);
			s+=u;
			if(u==0) b=true;
		}
		else if(a[x][i]==k) b=true;
	}
	if(mx==s&&x!=k) if(x<in) in=x;
	if(mx<s&&x!=k) mx=s,in=x;
	if(b||lp[x])
	{ 
		lp[x]=true;
		return 0;
	}
	return s+1;
}
main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&t1,&t2);
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	ch[k]=true;
	po(k);
	printf("%d\n%d",in,mx);
}
