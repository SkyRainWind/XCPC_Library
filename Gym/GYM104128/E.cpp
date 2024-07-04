// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1005;

int n,k,a[maxn],s[maxn];
double get_time(){return (double)clock()/CLOCKS_PER_SEC;}
signed main(){
	for(int n=12;n<=12;n++)for(int k=5;k<=n;k++){
		for(int i=1;i<=n;i++)a[i]=i;
		int f=0;
		do{
			for(int i=1;i<=n;i++)s[i] = s[i-1] + a[i];
			set<int>S;
			for(int i=1;i+k-1<=n;i++){
				int j=i+k-1;
				int r = s[j] - s[i-1];
				S.insert(r%2);
			}
			if(S.size()==1){f=1;break;}
		}while(next_permutation(a+1,a+n+1) && get_time() <= 5.0*k);
		printf("%d,%d: ",n,k);
		puts(f ? "Yes" : "No");
		if(n==12&&k==5)for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	}

	return 0;
}

