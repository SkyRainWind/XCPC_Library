// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

namespace bignum{ 
	const int bse = 1e7;
	struct haa{
		LL a[10005];int len;
		haa(){len = 1, memset(a,0,sizeof(a));}
		haa(int x){
	        memset(a,0,sizeof(a));len = 1;
	        while(x){a[len++] = x % bse,x /= bse;}len --;
	    }
		void print(){
	        printf("%lld",a[len]);
	        for(int i = len-1 ; i ; i --)printf("%07lld",a[i]);
	        exit(0);
	    }
		void toint(char *s){	// 1-index
			int ns = strlen(s + 1);
			int t1 = 0, i = ns;
			for(;i-6>=1;i-=7){
				int cur = 0;
				for(int j = i-6;j<=i;j++)
					cur = cur * 10 + s[j] - '0';
				a[len ++] = cur;
				t1 = 0;
			}
			int cur = 0;
			if(i >= 1){
				for(int j = 1; j <= i; j++)cur = cur * 10 + s[j] - '0'; 
				a[len ++] = cur;
			}
			-- len;
		}
	}; 
	haa operator + (haa& a,haa& b){
		haa ret = 0; ret.len = max(a.len,b.len) + 1;
		for(int i = 1 ; i <= ret.len ; i ++)
			ret.a[i] += a.a[i] + b.a[i],
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
		for(int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
		while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
		return ret;
	}
	haa operator * (haa& a,haa& b){
		haa ret = 0; ret.len = a.len + b.len + 1;
		for(int i = 1 ; i <= a.len ; i ++)
			for(int j = 1 ; j <= b.len ; j ++)
				ret.a[i+j-1] += a.a[i] * b.a[j],
				ret.a[i+j] += ret.a[i+j-1] / bse,
				ret.a[i+j-1] %= bse;
		for(int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse ,
			ret.a[i] %= bse;
		while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
		return ret;
	}
	void div2(haa &a) {
        for(int i = 1; i <= a.len; i ++) {
            if(a.a[i] & 1) a.a[i - 1] += bse >> 1;
            a.a[i] >>= 1;
        }
        for(; !a.a[a.len] && a.len > 1; a.len --);
    }
    int iszero(haa &a){
    	return a.len == 1 && a.a[1] == 0;
	}
	int iseven(haa &a){
		return !iszero(a) && a.a[1]%2==0;
	}
	haa operator * (haa& a,int b){
		haa ret = 0 ; ret.len = a.len;
		int x = b;
		while(x) ret.len ++ , x /= bse;
		for(int i = 1 ; i <= a.len ; i ++)
			ret.a[i] += a.a[i] * b,
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
		for(int i = 1 ; i <= ret.len ; i ++)
			ret.a[i+1] += ret.a[i] / bse,
			ret.a[i] %= bse;
		while(ret.len > 1 && !ret.a[ret.len]) ret.len --;
		return ret;
	}
	inline void operator -= (haa &a, haa &b) {
        for(int i = 1; i <= a.len; i ++) {
            if(i <= b.len) {
                a.a[i] -= b.a[i];
                if(a.a[i] < 0) a.a[i + 1] --, a.a[i] += bse;
            }
        }
        for(; !a.a[a.len] && a.len > 1; a.len --);
    }
	inline void operator += (haa& a,haa& b){a = a+b;}
	inline void operator *= (haa& a,int b){a = a*b;}
	inline void operator *= (haa& a,haa& b){a = a*b;}
	bool operator < (const haa& a,const haa& b){
		if(a.len != b.len) return a.len < b.len;
		for(int i = a.len ; i ; i --)
			if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
		return 0;
	}
	bool operator == (const haa& a,const haa& b){
		if(a.len != b.len) return 0;
		for(int i = a.len ; i ; i --)
			if(a.a[i] != b.a[i]) return 0;
		return 1;
	}
	bool operator > (const haa& a,const haa& b){return !(a<b) && !(a == b);}
};
using namespace bignum;

char a[23333], b[23333];
signed main(){
//	debug();
	haa qa, qb;
	scanf("%s", a+1);
	scanf("%s", b+1);
//	debug();
	qa.toint(a);
	qb.toint(b);
	if(iszero(qa))qb.print();
	if(iszero(qb))qa.print();
	int i1 = 0, i2 = 0;
	for(;iseven(qa);++i1)div2(qa);
	for(;iseven(qb);++i2)div2(qb);
	haa h2 = 2;
	while(1){
		if(qa > qb){
			qa -= qb;
			if(iszero(qa)){
				for(int i = 1;i<=min(i1, i2);i++)qb *= h2;
				qb.print();
			}
			while(iseven(qa))div2(qa);
		}else{
			qb -= qa;
			if(iszero(qb)){
				for(int i = 1;i<=min(i1, i2);i++){
					qa *= 2;
				}
				qa.print();
			}
			while(iseven(qb))div2(qb);
		}
	}
//	div2(qa);
//	qa.print();

	return 0;
}


