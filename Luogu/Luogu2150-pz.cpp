#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline int read(){
    int re=0,flag=1;char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-') flag=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
    return re*flag;
} 
int n,MOD;
int p[10]={0,2,3,5,7,11,13,17,19,0};
struct node{
    int val,big,S;//big���Ǵ���������S��С����������
    void init(){
        int i,tmp=val;big=-1;
        for(i=1;i<=8;i++){//�ֽ�������
            if(tmp%p[i]) continue;
            S|=(1<<i-1);
            while(tmp%p[i]==0) tmp/=p[i];
        }
        if(tmp!=1) big=tmp; 
    }
}a[510];
inline bool cmp(node l,node r){
    return l.big<r.big;
}
int pl(int l,int r){
    l+=r;
    return l>=MOD?l-MOD:l;
}
int dp[300][300],f1[300][300],f2[300][300];
int main(){
	freopen("2150-1.out","w",stdout);
    n=read();MOD=read();int i,j,k;
    for(i=2;i<=n;i++) a[i-1].val=i,a[i-1].init();
    sort(a+1,a+n,cmp);
    dp[0][0]=1;
    for(i=1;i<n;i++){
        if(i==1||a[i].big!=a[i-1].big||a[i].big==-1){
            memcpy(f1,dp,sizeof(f1));
            memcpy(f2,dp,sizeof(f2));
        }
        for(j=255;j>=0;j--){
            for(k=255;k>=0;k--){//��Ϊ�ǹ������飬����һ��Ҫ������
                if(j&k) continue;
                if((a[i].S&j)==0) f2[j][k|a[i].S]=pl(f2[j][k|a[i].S],f2[j][k]);
                if((a[i].S&k)==0) f1[j|a[i].S][k]=pl(f1[j|a[i].S][k],f1[j][k]);
            }
        }
        if(i==n-1||a[i].big!=a[i+1].big||a[i].big==-1){
            for(j=0;j<=255;j++){
                for(k=0;k<=255;k++){
                    if(j&k) continue;
                    dp[j][k]=pl(f1[j][k],pl(f2[j][k],MOD-dp[j][k]));
                }
            }
        }
    }
    for(int j=0;j<=255;j++,puts(""))
    	for(int k=0;k<=255;k++)printf("%d ",dp[j][k]);
    ll ans=0;
    for(j=0;j<=255;j++){
        for(k=0;k<=255;k++){
            if((j&k)==0&&dp[j][k]) ans=pl(ans,dp[j][k]);
        }
    }
    cout<<ans;
}
