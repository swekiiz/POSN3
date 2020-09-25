#include<bits/stdc++.h>
char c[2002][2002];
struct _{int x,y;}t,p;
int u,s,z[2][4]={{-1,1,0,0},{0,0,-1,1}},n,k,m,me[2002][2002];
std::queue<_> Q;
bool h[2002][2002];
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
		for(int j=0;j<m;j++){
			if(c[i][j]=='X') t.x=j,t.y=i,Q.push(t),h[i][j]=true;
			if(c[i][j]=='W') h[i][j]=true;
		}
	}
	for(;!Q.empty();Q.pop()){
		t=Q.front();
		if(c[t.y][t.x]=='A') s+=me[t.y][t.x]*2,k++;
		for(int i=0;i<4;i++){
			p.x=t.x+z[0][i],p.y=t.y+z[1][i];
			if(p.x>=0&&p.x<m&&p.y>=0&&p.y<n) if(!h[p.y][p.x]) h[p.y][p.x]=true,me[p.y][p.x]=me[t.y][t.x]+1,Q.push(p); 
		}
	}
	printf("%d %d",k,s);
}
