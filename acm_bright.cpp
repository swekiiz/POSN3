#include<bits/stdc++.h>
using namespace std;
int v,s,p,n,q,mem[100002][102],k,a[100002],m[100002],b;
int dp(int x,int g){
	int z=INT_MIN;
	if(mem[x][g]!=-1) return mem[x][g];
	if(x==1) return mem[x][g]=a[1];
	z=max(z,dp(x-1,g));
	if(g>0) for(int i=p-1;i>=0;i--) if(m[i]<=x) z=max(z,dp(m[i]-1,g-1));
	return mem[x][g]=z+a[x];
}
main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) mem[i][j]=-1;
		for(p=0,v=1;v<=n;v++){
			scanf("%d",&a[v]);
			if(a[v]<0&&!b&&v>1) b=true,s=v;
			if(b&&a[v]>=0) m[p++]=s,b=false;
		}
		if(b) m[p++]=s;
		printf("%d\n",dp(n,k));
	}
}
