#include<bits/stdc++.h>
using namespace std;
string pat,txt;
int lps[100];
void find_lps(){
	int len=0;
	lps[0]=0;
	for(int i=1;i<pat.size();){
		if(pat[i]==pat[len]){
			len++;
			lps[i++]=len;
		}
		else{
			if(len!=0) len=lps[len-1];
			else lps[i++]=0;
		}
	}
}
main(){
	cin>>txt>>pat;
	find_lps();
	int i=0,j=0;
	for(int i=0;i<pat.length();i++)cout<<lps[i]<<" ";
	cout<<endl;
	while(i<txt.size()){
		cout<<i<<"   "<<j<<endl;
		if(pat[j]==txt[i]){
			i++,j++;
		}
		if(j==pat.size()){
			cout<<"found at : "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<txt.size()&&pat[j]!=txt[i]){
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
	
}
