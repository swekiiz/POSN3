#include<stdio.h>
int n,a[100];
void recur(int s,int x,int b){
	if(x==1&&s!=1){
		for(int i=0;i<s;i++)
			printf("%d ",a[i]);
		puts("");
		return;
	}
	for(int i=b;i<=x;i++){
		if(x%i==0){
			a[s]=i;
			recur(s+1,x/i,i);
		}
	}
}
main(){
	scanf("%d",&n);
	recur(0,n,2);
}
