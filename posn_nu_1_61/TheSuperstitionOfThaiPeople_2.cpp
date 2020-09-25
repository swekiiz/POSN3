#include<stdio.h>
main(){
	int k,g,n,i,j,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		k=a*b;
		while(k>=10){
			g=0;
			for(;k!=0;k/=10){
				g+=k%10;
			}
			k=g;
		}
		if(k==3)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
