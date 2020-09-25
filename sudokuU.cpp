#include<cstdio>
char t[10][10];bool r[9][9],c[9][9],s[3][3][9];int _[9][9];
bool sol(int a,int b){
	if(t[a][b]!='.'){
		if(a==8&&b==8) return true;
		if(a==8) return sol(0,b+1);
		return sol(a+1,b);
	}
	for(int i=1;i<10;i++) if((!r[a][i])&&(!c[b][i])&&(!s[a/3][b/3][i])){
		_[a][b]=i;
		if(a==8&&b==8) return true;
		r[a][i]=true,c[b][i]=true,s[a/3][b/3][i]=true;
		if(a==8&&sol(0,b+1)) return true;
		if(a!=8&&sol(a+1,b)) return true;
		r[a][i]=false,c[b][i]=false,s[a/3][b/3][i]=false;
	}
	return false;
}
main(){
	for(int i=0;i<9;i++) for(int j=0;j<9;j++) scanf(" %c",&t[i][j]);
	for(int i=0;i<9;++i) for(int j=0;j<9;j++) if(t[i][j]!='.')
		_[i][j]=t[i][j]-'0',r[i][t[i][j]-48]=1,c[j][t[i][j]-48]=1,s[i/3][j/3][t[i][j]-48]=1;	
	if(sol(0,0)) for(int i=0;i<9;i++){
		for(int j=0;j<9;j++) printf("%d ",_[i][j]);
		puts("");
	}
}
