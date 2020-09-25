#include<bits/stdc++.h>
int mem[260][260][3],n,ta[3][3]={{2,1,0},{2,1,1},{1,2,1}};
char c[1000];
int dp(int l,int r,int x){
	if(mem[l][r][x]!=-1) return mem[l][r][x];
	if(l==r){
		if(c[r]-'0'==x) return mem[l][r][x]=1;
		else return mem[l][r][x]=0;
	}
	for(int i=l;i<r;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++)
				if(ta[j][k]==x&&dp(l,i,j)&&dp(i+1,r,k)) return mem[l][r][x]=1;
		}
	}
	return mem[l][r][x]=0;
}
main(){
	for(int i=1;i<=20;i++){
		memset(mem,-1,sizeof(mem));
		scanf("%d %s",&n,c);
		if(dp(0,n-1,0)==1) printf("yes\n");
		else printf("no\n");
	}
}
