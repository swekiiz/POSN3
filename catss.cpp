#include<stdio.h>
int a[2000001],p,r=-1,n,l,m,f;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		r=r>a[i]?r:a[i];
	}
	while(l<r){
		m=l+(r-l)/2,p=-1,f=0;
		for(int i=0;i<n;i++)
			if(a[i]>m){
				if(p==-1) p=a[i];
				else if(p==a[i]) p=-1;
				else{
					f=1;
					break;
				}
			}
		if(f) l=m+1;
		else r=m;
	}
	printf("%d",l);
}
