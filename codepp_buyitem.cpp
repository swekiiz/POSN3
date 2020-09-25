#include<iostream>
using namespace std;
int n,a[9],m,c,mem[32][9];
int dp(int x,int y){
	if(x==0) return 1;
	if(x<0||y==0) return 0;
	if(mem[x][y]!=0) return mem[x][y];
	return mem[x][y]=dp(x,y-1)+dp(x-a[y],y);
}
main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	cout<<dp(n,m);
}
