// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int tb[1005];
int notpm[1005],pm[1005],pcnt=0;

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=1000;i++){
		if(!notpm[i])pm[++ pcnt]=i;
		for(int j=1;j<=pcnt && i*pm[j] <= 1000;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0){
				break;
			}
		} 		
	}
}
int ys[1005],cnt=0;
int cmp(int a,int b){return a>b;} 
LL pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	LL mid = pw(x,y>>1);
	if(y&1)return 1ll*mid*mid*x;
	return 1ll*mid*mid;
}
signed main(){
	tb[1]=1,tb[2]=2,tb[3]=4,tb[4]=6,tb[5]=16,tb[6]=12,tb[7]=64,tb[8]=24,tb[9]=36,tb[10]=48,tb[11]=1024,tb[12]=60,tb[14]=192,tb[15]=144,tb[16]=120,tb[18]=180,tb[20]=240,tb[21]=576,tb[24]=360,tb[25]=1296,tb[27]=900,tb[28]=960,tb[30]=720,tb[32]=840,tb[36]=1260,tb[40]=1680;
	int n;scanf("%d",&n);
	if(tb[n])return printf("%d\n",tb[n]),0;
	xxs();
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			while(n%i == 0){
				ys[++cnt]=i;
				n /= i;
			}
		}
	}
	if(n != 1)ys[++ cnt]=n;
	sort(ys+1,ys+cnt+1,cmp);
	LL ans = 1, cc=0;
	for(int i=1;i<=cnt;i++){
		ans = 1ll*ans*pw(pm[++ cc], ys[i]-1);
	}
	printf("%I64d\n",ans);

	return 0;
}


