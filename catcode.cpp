#include<cstdio>
#include<vector>
struct gg{
    int val,node;
};
using namespace std;
int aaa,u,a,s,k,m,v,t;
gg table[8000009];
char c[1000001];
bool ch[100001];
void hashy(int x,int f){
    int i=x%8000009;
    while(table[i%8000009].val!=0) i+=5, i%=8000009;
    table[i%8000009].val=x,table[i%8000009].node=f;
}
int access(int x){
    int i=x%8000009;
    while(table[i%8000009].val!=x&&table[i%8000009].val!=0) i+=5, i%=8000009;
    if(table[i%8000009].val==x) return table[i%8000009].node;
    return 0;
}
int powtwo(int x,int y){
    if(y==0) return 1;
    if(y%2==0){
        int temp=powtwo(x,y/2);
        return temp*temp;
    }
    return x*powtwo(x,y-1);
}
main(){
    scanf("%d %d",&k,&m);
    u=powtwo(2,m);
    for(int i=0;i<k;i++){
        scanf("%s",c);
        s=0;
        for(int j=0;j<m;j++){
            s<<=1;
            if(c[j]=='1') s++;
        }
        //printf("%d <------\n",s);
        hashy(s,i+1);
    }
    scanf("%d",&v);
    for(int i=0;i<v;i++){
        scanf("%d %s",&t,c);
        s=0,a=0;
        for(int j=0;j<t;j++){
            aaa=access(s);
            if(aaa&&j>=m-1){
               a++;
               //printf("%d access\n",access(s));
               ch[aaa]=true;
            }
            s<<=1;
            if(c[j]=='1') s++;
            s%=u;
            //printf("%d <>\n",s);
        }
        if(a==0) printf("OK\n");
        else{
            for(int j=1;j<=k;j++)
                if(ch[j]){
                    printf("%d ",j);
                    ch[j]=false;
                }
            puts("");
        }
    }
}
