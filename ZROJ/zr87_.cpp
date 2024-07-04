#include <bits/stdc++.h>
#define ll long long
/*#define INF 2147483647
#define mem_INF 2139062143
#define ll_INF 9223372036854775807
#define eps 1e-8
#define fuckrand() ( ( rand() << 15 ) ^ rand() )*/
using namespace std;
inline int read() {
	int x = 0,tmp = 1;char ch = getchar();
	while( ch < '0' || ch > '9' ) { if( ch == '-' ) tmp = -1; ch = getchar();}
	while( ch >= '0' && ch <= '9'){ x = x * 10 + ch - '0'; ch = getchar(); }
	return x * tmp;
}
inline ll readll() {
	ll x = 0,tmp = 1;char ch = getchar();
	while( ch < '0' || ch > '9' ) {if ( ch == '-' ) tmp = -1; ch = getchar();}
	while( ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar(); }
	return x * tmp;
}
const int Pi = 1e9 + 7;
int C[110];
void updata( int i, const int& p ) {
	for( ; i ; i -= i&-i ) C[i] += p;
} 
#define __ %Pi
inline int dig( const ll& x ) {
	int cnt = 0;
	for( int i = 0 ; i < 60 ; ++ i ) if( x & ( 1ll << i ) ) cnt ++;
	return cnt;
}
ll pw[60], rev[60];
inline ll fast_pow( const int& x, int k ) {
	ll res = 1, tmp = x;
	for( ; k ; k >>= 1 ) {
		if( k & 1 ) res = res * tmp __;
		tmp = tmp * tmp __;
	}
	return res;
}
void init() {
	pw[0] = 1;
	for( int i = 1 ; i < 60 ; ++ i ) pw[i] = ( pw[i - 1] << 1 ) __;
	for( int i = 0 ; i < 60 ; ++ i ) rev[i] = fast_pow( pw[i], Pi );
}
int main() {
	init();
	int T = read();
	ll n, ans, p, q, now;
	while( T -- ) {
		ans = 0;
		n = read();
		for( int i = 1 ; i <= n ; ++ i ){
			for( int j = i ; j <= n ; ++ j ) {
				p = i - 1, q = j;
				while( p != 0 || q != 0 ) {
					if( p > q ) p -= p&-p, ans = ( ans + 1 ) __;
					else if( q > p ) q -= q&-q, ans = ( ans + 1 ) __ ;
					else break;
				}
			printf("%lld\n",ans);
			}
		}
		printf( "%lld\n", ans );
		/*ans = 0;
		if( n == 1 ) { puts( "1" ); continue; }
		else if( n == 2 ) { puts( "4" ); continue; }
		else ans = 2, ans = ( ans + (( n - 1 )__) * 4ll __ );
		//cout << ans << endl;
		for( int i = 2 ; i < 60 ; ++ i ) if( ( 1ll << i ) >= n ) break; else {
			ll tot = 0;
			for( int j = 1 ; j < i ; ++ j ) {
				now = ( pw[i - 1] - pw[j - 1] + Pi ) __;
				now = now * pw[j - 1] __; now = now * pw[i - j] __;
				tot = ( tot + now ) __;
			}
			tot = ( tot + ( pw[i] - 1 + Pi ) * ( pw[i - 1] )__ ) __; 
			ans = ( ans + tot ) __;
			cout << i << " " << tot << endl;
			ans = ( ans + ( ( pw[i] + pw[i - 1] * i ) __ ) * ( ( n - pw[i] + 1 ) __)  __ ) __;
			//cout << ( pw[i + 1] * ( ( n - pw[i] + 2 ) __) )  __ << endl;
		}
		printf( "%lld\n", ans );*/
	}
	

	return 0;
}
