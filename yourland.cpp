#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
struct qw{
    int first;
    long long second;
    bool operator <(const qw &d)const{
        if(d.second==second) return first<d.first;
        return second>d.second;
    }
}temp;
vector<qw> a[300001];
priority_queue<qw> Q;
int u,last,c,n,t,t1,t2,t3,degree[300001];
long long s[300001];
bool ch[300001];
main(){
    scanf("%d",&u);
    for(int z=0;z<u;z++)
    {
        for(int i=0;i<=n;i++) s[i]=0,degree[i]=0,ch[i]=false;
        last=0,c=0,n=0,t=0,t1=0,t2=0,t3=0;
        memset(a,0,sizeof(a));
        while(!Q.empty()) Q.pop();
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&t1,&t2,&t3);
            degree[t1]++,degree[t2]++;
            temp.first=t2,temp.second=(long long)t3;
            a[t1].push_back(temp);
            temp.first=t1;
            a[t2].push_back(temp);
        }
        for(int i=1;i<=n;i++){
            if(degree[i]==1){
                temp.first=i,temp.second=0LL;
                Q.push(temp);
            }
        }
        while(!Q.empty()&&c<n-1){
            temp=Q.top();Q.pop();
            int x=temp.first;
            long long w=temp.second;
            //printf("%d <-- %d\n",x, w);
            ch[x]=true;
            for(int i=0;i<a[x].size();i++){
                if(!ch[a[x][i].first]&&s[a[x][i].first]<w+a[x][i].second){
                    s[a[x][i].first]=w+a[x][i].second;
                }
                if(--degree[a[x][i].first]==1){
                    temp.first=a[x][i].first,temp.second=s[a[x][i].first];
                    Q.push(temp);
                }
            }
            c++;
        }
        for(int i=1;i<=n;i++){
            if(!ch[i]){
                printf("%d %lld\n",i,s[i]);
                break;
            }
        }
    }
}
