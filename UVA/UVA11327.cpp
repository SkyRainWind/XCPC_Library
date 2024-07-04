#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=2e5+5;

int phi[maxn], notpm[maxn], pm[maxn], pcnt=0;

void xxs(){
	notpm[1] = phi[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			phi[i] = i-1;
			pm[++ pcnt] = i;
		}
		for(int j=1;j<=pcnt && i*pm[j] <= maxn-5; j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] != 0){
				phi[i*pm[j]] = (pm[j] - 1) * phi[i];
			}
			if(i%pm[j] == 0){
				phi[i*pm[j]] = pm[j] * phi[i];
				break;
			}
		}
	}
}

long long n;
long long sumphi[maxn];

long long gcd(long long a,long long b){
	return !b?a:gcd(b,a%b);
}

void solve(){
	if(n == 1){
		puts("0/1");
		return ;
	}
	if(n == 2){
		puts("1/1");
		return ;
	}
	int lst = upper_bound(sumphi+1,sumphi+200001,n) - sumphi - 1;
	n -= sumphi[lst];
	if(n == 0){
		printf("%d/%d\n",lst-1, lst);
		return ;
	}
	for(long long  j=1;j<=lst + 1;j++){
		if(gcd(j,lst+1) == 1)-- n;
		if(n == 0){
			printf("%d/%d\n",j,lst + 1);
			return ;
		}
	}
}

int main(){
	xxs();
	phi[1] = 2;
	for(int i=1;i<=maxn-5;i++)sumphi[i] = sumphi[i-1] + phi[i];
	while(scanf("%lld",&n), n){
		solve();
	}
	
	return 0;
}
