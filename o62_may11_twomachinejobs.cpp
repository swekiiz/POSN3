#include<cstdio>
int n,q,a,b,t,y,p;
int main(){
	scanf("%d %d %d %d",&n,&q,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%d %d",&t,&y);
		if(i==0||q==1) printf("%d\n",p=t+y);
		else printf("%d\n",p=((t+p%a)+(y+p%b)));
	}
	return 0;
}
