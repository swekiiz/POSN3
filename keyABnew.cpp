#include<bits/stdc++.h>
char g[1001],c[1001],t[2003];
int q;
bool ch[1001][1001],mem[1001][1001];
bool dp(int x,int y){
	if(x<0||y<0) return true;
	if(ch[x][y]) return mem[x][y];
	ch[x][y]=true;
	if((dp(x-1,y)&&g[x]==t[x+y+1])||(dp(x,y-1)&&c[y]==t[x+y+1])) return mem[x][y]=true;
	return mem[x][y]=false;
}
main(){
	scanf("%s %s %d",g,c,&q);
	while(q--){
		scanf("%s",t);
		if(dp(strlen(g)-1,strlen(c)-1)) printf("Yes\n");
		else printf("No\n");
	}
}
