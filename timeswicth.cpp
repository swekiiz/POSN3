#include<cstdio>
int n;
char q[5000001];
bool c(int x){
	for(int i=0;i<x;i++) for(int j=i;j<n;j+=x) if(q[i]!=q[j]) return false;
	return true;
}
main(){
	scanf("%d %s",&n,q);
	for(int i=1;i<=n;i++) if(n%i==0) if(c(i)){
		printf("%d",i);
		return 0;
	}
}
