#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],s,d,f,e,t1,t2,t3,mem[102][102],ds[102][102];
bool ch[102];
struct ne{int nx,w;bool operator<(const ne &rh)const{return w>rh.w;};};
ne mp(int a,int b){ne t;t.nx=a,t.w=b;return t;}
vector<ne> v[102];
priority_queue<ne> Q;
int dp(int x,int o){
	if(x==s) return 0;
	if(mem[x][o]!=-1) return mem[x][o];
	for(int i=1;i<=n;i++){
		if(f-ds[x][i]>=0){
			if(i==x){
				
			}
			else{
				mem[x][o]=min(mem[x][o],min(dp(i,ds[x][i])+a[x]*o,dp(i,f)+(o-ds[x][i])*a[x]));
			}
		}
	}	
}
main(){
	for(int i=0;i<102;i++) for(int j=0;j<102;j++) mem[i][j]=INT_MAX;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d %d %d %d",&s,&d,&f,&e);
	for(int i=0;i<e;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		v[t1].push_back(mp(t2,t3));
		v[t2].push_back(mp(t1,t3));
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) ds[i][j]=INT_MAX;
	for(int j=1;j<=n;j++){
		ds[j][j]=0;
		for(int i=0;i<=n;i++) ch[i]=false;
		for(Q.push(mp(j,0));!Q.empty();Q.pop()){
			if(!ch[Q.top().nx]){
				ch[Q.top().nx]=true;
				for(int i=0;i<v[Q.top().nx].size();i++){
					if(!ch[v[Q.top().nx][i].nx]&&ds[j][v[Q.top().nx][i].nx]>ds[j][Q.top().nx]+v[Q.top().nx][i].w){
						ds[j][v[Q.top().nx][i].nx]=ds[j][Q.top().nx]+v[Q.top().nx][i].w;
						Q.push(mp(v[Q.top().nx][i].nx,ds[j][v[Q.top().nx][i].nx]));
					}
				}
			}
		}
	}
	
	
	puts("");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",ds[i][j]);
		}
		puts("");
	}
	
}
