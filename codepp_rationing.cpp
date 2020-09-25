#include<iostream>
using namespace std;
int q,x,c[3],v1,v2,v3,cc,s[3];
bool ch(int x,bool b){
	if(b==1) q=s[2];
	if(b==2) q=s[2]+s[1];
	if(b==3) return true;
	if(x>q) return false;
	return true;
}
void recur(int x,int b){
	if(x==0){
		if(c[0]<=v1&&c[1]<=v2&&c[2]<=v3) cc++;
		return;
	}
	for(int i=b;i>0;i--){
		if(x-i>=0){
			c[i-1]++,s[i-1]-=i;
			if(c[0]<=v1&&c[1]<=v2&&c[2]<=v3&&ch(x-i,i)) recur(x-i,i);
			c[i-1]--,s[i-1]+=i;
		}
	}
}
main(){
	cin>>x>>v1>>v2>>v3;
	x<<=1;
	s[2]=v1,s[1]=v2*2,s[0]=v3*3;
	recur(x,3);
	cout<<cc;
}
