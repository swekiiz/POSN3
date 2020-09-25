#include<bits/stdc++.h>
using namespace std;
string s,t;
int c[100],u,p,q;
main(){
	cin>>q>>s>>t;
	for(int i=0;i<t.size();i++)
		c[t[i]-'0'+1]++;
	for(int i=0;i<s.size();i++){
		if(c[s[i]-'0'+1]>0){
			u+=1+i+q*p;
			c[s[i]-'0'+1]--;
			p--;
		}
	}
	for(int i=0;i<26;i++) if(c[i]>0) u=-1;
	cout<<u;
}
