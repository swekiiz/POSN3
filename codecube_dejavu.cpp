#include<bits/stdc++.h>
using namespace std;
int n,s[100002],q=1;
long long u;
vector<int> a;
priority_queue<int> f[100002];
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);
    a.assign(n,0);
	a[0]=s[0];
	f[0].push(s[0]);
    for(int i=1;i<n;++i){ 
        if(s[i]<a[0]){
            a[0]=s[i];
            f[0].push(s[i]);
        }
        else if(s[i]>=a[q-1]){
        	f[q].push(s[i]);
            a[q++]=s[i];
        }
		else{
			int l=-1,r=q-1;
			while(r-l>1){ 
		    	int m=l+(r-l)/2; 
		    	if(a[m]>s[i]) r=m; 
		    	else l=m; 
			}
            a[r]=s[i];
            f[r].push(s[i]);
		}
    }
    a[q-1]=f[q-1].top();
    for(int i=q-2;i>=0;i--){
       	while(1){
       		if(f[i].empty()) break;
       		if(f[i].top()<=a[i+1]) break;
			f[i].pop();
		}
    	a[i]=f[i].top();
	}
    for(int i=0;i<q;i++) u+=a[i];
    printf("%d %lld",q,u);
}
