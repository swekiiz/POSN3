#include<bits/stdc++.h>
int q,n,a[111],s,m[111][111];
int dp(int y,int x){
	if(x==0) return 1;
	if(y<0||x<0) return 0;
	if(m[y][x]!=-1) return m[y][x];
	return m[y][x]=dp(y-1,x)||dp(y-1,x-a[y]);
}
main(){
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		memset(m,-1,sizeof(m));
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
			s+=a[j];
		}
		if(s&1) printf("No\n");
		else if(dp(n,s>>1)) printf("Yes\n");
		else printf("No\n");
		s=0;
	}
}
