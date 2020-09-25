#include <bits/stdc++.h>
using namespace std;
int b[26][26],a[26],be,al;
bool il(char x){return (x<='z'&&x>='a');}
main(){
    string s;
    cin>>s;
    int i=0;
    while(s[i]!='\0'){
        if(!il(s[i])){
            if(s[i+1]!='\0'&&il(s[i+1])){
                if(b[s[i]-'A'][s[i+1]-'a'] == 0)be++;
                b[s[i]-'A'][s[i+1]-'a']++;
                i+=2;
            } 
			else{
                if(a[s[i]-'A'] == 0) al++;
                a[s[i]-'A']++;
                i++;
            }
        }
    }
    printf("%d\n",al);
    for(int i=0;i<26;i++) if(a[i]) printf("%c %d\n",i + 'A',a[i]);
    printf("%d\n",be);
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) if(b[i][j]) printf("%c%c %d\n",i + 'A',j+'a',b[i][j]);
}

