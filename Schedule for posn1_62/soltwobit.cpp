#include<cstdio>
int n,s[1000],t[1000],a[100],ch[1000],mx=-1;
void twobit(int c){
	if(c==n){
		int f=0,p=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				for(int j=s[i];j<=s[i]+t[i]-1;j++){
					if(ch[j]==1){
						f=1;
						break;
					}
					else ch[j]=1;
				}
				if(f==1) break;
				else p++;
			}
		}
		if(mx<p){
			mx=p;
		}
		for(int i=0;i<1000;i++){
			ch[i]=0;
		}
		return;
	}
	a[c]=0;
	twobit(c+1);
	a[c]=1;
	twobit(c+1);
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&s[i],&t[i]);
	twobit(0);
	printf("%d",mx);
}
