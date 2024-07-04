//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
   int s=0,w=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
   return s*w;
}
int a[105],f1[150][150],f2[150][150];
char ch[105];
int main(){
	freopen("Luogu4342.in","r",stdin);
	freopen("Luogu4342-2.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ch[i]>>a[i];
        a[n+i]=a[i];ch[n+i]=ch[i];
    }
    for(int i=1;i<=n*2;i++)
	f1[i][i]=f2[i][i]=a[i];
    for(int len=2;len<=n;len++){
        for(int i=1;i<=2*n-len+1;i++){
	    	int j=i+len-1;f1[i][j]=-1e9,f2[i][j]=1e9;
            for(int k=i;k<j;k++){
                if(ch[k+1]=='x'){
		    		f1[i][j]=max(f1[i][j],max(f1[i][k]*f1[k+1][j],f2[i][k]*f2[k+1][j]));
		    		f2[i][j]=min(f2[i][j],min(f2[i][k]*f2[k+1][j],min(f1[i][k]*f1[k+1][j],min(f1[i][k]*f2[k+1][j],f2[i][k]*f1[k+1][j]))));
                }
                else if(ch[k+1]=='t'){
                    f1[i][j]=max(f1[i][j],f1[i][k]+f1[k+1][j]);
                    f2[i][j]=min(f2[i][j],f2[i][k]+f2[k+1][j]);
                }
            }
        }
    }
    int ans=-1e9;
    for(int i=1;i<=n;i++)
		ans=max(ans,f1[i][i+n-1]);
    printf("%d\n",ans);
//    return 0;
    for(int i=1;i<=n;i++)
		if(f1[i][i+n-1]==ans)printf("%d ",i);
    return 0;
}


