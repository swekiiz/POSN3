#include<stdio.h>
#include<math.h>
main(){
	int n,p,count=0,i;
	scanf("%d",&n);
	for(i=pow(2,n)-1;i>=0;i--){
		p=0;
		for(int j=i;;j/=2){
			if(p==1&&j%2==1)
				break;
			if(j==0){
				count++;	
				break;
			}
			p=j%2;
		}
	}
	printf("%d",count);
}
