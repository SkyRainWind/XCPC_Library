#include<bits/stdc++.h>
using namespace std;
const int N=9e5+55;
int a[N],b[N],c[N],d[N];
long long suma[N],sumb[N],sumc[N],sumd[N];
int zz[10];
int cnt[10];
int tong[N];
int n,m,k;
long long v[N];
int A,B;
priority_queue<long long> q;
priority_queue<long long,vector<long long>,greater<long long> > p;
long long qsum=0;
long long minn=1e18;
void init(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]);
    scanf("%d",&A);
    for(int i=1;i<=A;i++){
        int x;
        scanf("%d",&x);
        tong[x]++;
    }
    scanf("%d",&B);
    for(int i=1;i<=B;i++){
        int x;
        scanf("%d",&x);
        tong[x]+=2;
    }
//    a[++cnt[1]]=0;
//    b[++cnt[2]]=0;
//    c[++cnt[3]]=0;
//    d[++cnt[4]]=0;
    for(int i=1;i<=n;i++){
        if(tong[i]==0){
            cnt[4]++;
            d[cnt[4]]=v[i];
        }else if(tong[i]==1){
            cnt[1]++;
            a[cnt[1]]=v[i];
        }else if(tong[i]==2){
            cnt[2]++;
            b[cnt[2]]=v[i];
        }else if(tong[i]==3){
            cnt[3]++;
            c[cnt[3]]=v[i];
        }
    }
    sort(a+1,a+cnt[1]+1);
    sort(b+1,b+cnt[2]+1);
    sort(c+1,c+cnt[3]+1);
    sort(d+1,d+cnt[4]+1);
    for(int i=1;i<=cnt[1];i++)
        suma[i]=suma[i-1]+a[i];

    for(int i=1;i<=cnt[2];i++)
        sumb[i]=sumb[i-1]+b[i];

    for(int i=1;i<=cnt[3];i++)
        sumc[i]=sumc[i-1]+c[i];

    for(int i=1;i<=cnt[4];i++)
        sumd[i]=sumd[i-1]+d[i];
}
void PD(int x){
    int nd=max(0,k-x);
//    cout<<"**nd="<<nd<<endl;
    if(cnt[1]<nd||cnt[2]<nd) return ;
    int now=nd*2+x;
    int qk=m-now;
//    cout<<"qk="<<qk<<endl;
    for(int i=nd+1;i<=zz[1];i++){
        q.push(a[i]);
        qsum+=a[i];
    }
    for(int i=nd+1;i<=zz[2];i++){
        q.push(b[i]);
        qsum+=b[i];
    }
    zz[1]=nd;
    zz[2]=nd;
    while(1){
        if(!p.size()) break;
        if(!q.size()){
            q.push(p.top());
            qsum+=p.top();
            p.pop();
            continue;
        }
        long long ptop=p.top();
        long long qtop=q.top();
        if(ptop<qtop){
            p.pop();
            q.pop();
            p.push(qtop);
            q.push(ptop);
            qsum-=qtop;
            qsum+=ptop;
        }else{
            break;
        }
    }
    while(p.size()>0){
        if(!p.size()) break;
        if(q.size()>=qk) break;
        int ptop=p.top();
        p.pop();
        q.push(ptop);
        qsum+=ptop;
    }

    while(q.size()>=qk){
        if(!q.size()) break;
        if(q.size()==qk) break;
        int qtop=q.top();
        q.pop();
        p.push(qtop);
        qsum-=qtop;
    }
    if(q.size()!=qk) return ;
    long long NOW=sumc[x]+suma[nd]+sumb[nd];
    NOW+=qsum;
//    cout<<"nd="<<nd<<endl;
//    cout<<"NOW="<<NOW<<endl;
//    cout<<"qsum="<<qsum<<endl;
    minn=min(minn,NOW);
}
void doit(){
//    if(cnt[1]+cnt[3]<k||cnt[2]+cnt[3]<k){
//        cout<<-1<<endl;
//        exit(0);
//    }
    zz[1]=cnt[1];
    zz[2]=cnt[2];
    for(int i=1;i<=cnt[4];i++){
        q.push(d[i]);
        qsum+=d[i];
    }
    for(int i=0;i<=cnt[3];i++){
//        cout<<"i="<<i<<endl;
        PD(i);
        cerr<<i<<' '<<minn<<'\n';
    }
    if(minn==1e18) cout<<-1<<endl;
    else cout<<minn<<endl;
}
void ck(){
    cout<<"A--"<<endl;
    for(int i=1;i<=cnt[1];i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<"B--"<<endl;
    for(int i=1;i<=cnt[2];i++)
        cout<<b[i]<<" ";
    cout<<endl;

    cout<<"C--"<<endl;
    for(int i=1;i<=cnt[3];i++)
        cout<<c[i]<<" ";
    cout<<endl;

    cout<<"d--"<<endl;
    for(int i=1;i<=cnt[4];i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
int main(){
    freopen("CF799E.in","r",stdin);
//    freopen("b16.out","w",stdout);
    init();
//    ck();
    doit();
    return 0;
}
/*
10 8 5
3 6 8 5 6 14 16 8 20 17
6
2 9 5 1 8 4
6
7 6 4 9 8 2
*/
