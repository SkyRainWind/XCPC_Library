#include <cstdio>
#include <iostream>
#define pii pair<int,int>
#define mpr make_pair
using namespace std;
const int mod = 1e9+7;
int pw(int x,int y){
    if(!y)return 1;
    if(y == 1)return x;
    int mid = pw(x, y>>1);
    if(y&1)return 1ll*mid*mid%mod*x%mod;
    return 1ll*mid*mid%mod;
}
int main(){
    int n,m;scanf("%d%d",&n,&m);
    if(n>m){int t=n;n=m;m=t;}
    if(n <= 3 && m <= 3){
        if(n == 2 && m == 2)puts("12");
        else if(n == 3 && m == 3)puts("112");
        else if((n==2&&m==3) || (n==3&&m==2))puts("36");
        else printf("%d\n",pw(2,m));
        return 0;
    }
    if(n==2)printf("%d\n",4ll*pw(3, m-1)%mod);
    else if(n==3)printf("%d\n",112ll*pw(3,m-3)%mod);
    else{
    	pii tb[]={mpr(912,2688),mpr(7136,21312),mpr(56768,170112),mpr(453504,1360128),mpr(3626752,10879488)};
    	if(n == m)printf("%d\n",tb[n-4].first);
    	else if(m == n+1)printf("%d\n",tb[n-4].second);
    	else printf("%d\n",1ll * tb[n-4].second * pw(3,m-n-1) % mod);
	}
    
    return 0;
}
