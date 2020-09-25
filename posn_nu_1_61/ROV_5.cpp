#include<stdio.h>
int a[51][51],c,n,m,x,y,r;
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&y,&x);
		a[y][x]=1;
	}
	c=n;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&y,&x,&r);
		for(int j=y-r;j<=y+r;j++){
			for(int k=x-r;k<x+r;k++){
				if(a[j][k]==1){
					c--;
					a[j][k]=0;
				}
			}
		}
	}
	printf("%d",c);
}
