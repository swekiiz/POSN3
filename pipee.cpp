#include<cstdio>
#include<queue>
using namespace std;
struct pi
{
	int p,w;
	bool operator < (const pi &d)const {return d.w<w;}
}temp,tt;
bool ch[15002];
priority_queue<pi> Q;
priority_queue<int> A;
int mem[15002],ganx[15002],gany[15002],s,te,n,k,t1,t2;
int as(int a)
{
	if(a>0) return a;
	return -a;
}
main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&t1,&t2);
		ganx[i]=t1,gany[i]=t2;
		if(i==1) continue;
		temp.p=i,temp.w=as(ganx[1]-t1)+as(gany[1]-t2);
		if(mem[i]>temp.w||mem[i]==0)
		{
			Q.push(temp);
			mem[i]=temp.w;
		}
	}
	ch[1]=true;
	while(!Q.empty()&&te<n-1)
	{
		AA:;
		temp=Q.top();Q.pop();
		if(ch[temp.p]) goto AA;
		ch[temp.p]=true;
		A.push(temp.w);
		s+=temp.w;
		for(int i=2;i<=n;i++)
		{
			if(!ch[i])
			{
				tt.p=i,tt.w=as(ganx[temp.p]-ganx[i])+as(gany[temp.p]-gany[i]);
				if(mem[i]>tt.w||mem[i]==0)
				{
					Q.push(tt);
					mem[i]=tt.w;
				}
			}
		}
		te++;
	}
	for(int i=0;i<k-1;i++,A.pop()) s-=A.top();
	printf("%d",s);
}

