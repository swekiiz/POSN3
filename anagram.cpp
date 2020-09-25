#include<bits/stdc++.h>
char a[2003],b[2003];
int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
long long g=1;
std::map<long long,std::vector<long long> > m;
main(){
	scanf("%s %s",a,b);
	for(int r=std::min(strlen(a),strlen(b));r>'\0';--r){
		for(int i=0;i<=strlen(a)-r;i++,g=1){
			for(int j=i;j<r+i;g*=p[a[j++]-'A']);
			m[g%(LLONG_MAX-1)].push_back(g);
		}
		for(int i=0;i<=strlen(b)-r;i++,g=1){
			for(int j=i;j<r+i;g*=p[b[j++]-'A']);
			for(int k=0;k<m[g%(LLONG_MAX-1)].size();++k)
				if(m[g%(LLONG_MAX-1)][k]==g){
					printf("%d",r);
					return 0;
				}
		}

	}
}
