// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <complex>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;
const double pi = acos(-1.0), eps = 1e-6;

int n,m;
complex<double> a[maxn], b[maxn];

void fft(complex<double> a[], int n,int inv){
	if(n== 1)return ;
	int mid = n/2;
	complex<double> a1[mid+1], a2[mid+1];
	for(int i=0;i<=n;i+=2){
		a1[i/2] = a[i];
		a2[i/2] = a[i+1];
	}
	fft(a1, mid, inv);
	fft(a2, mid, inv);
	complex<double> w0(1,0), wn(cos(2*pi/n), inv*sin(2*pi/n));
	for(int i=0;i<mid;i++, w0 *= wn){
		a[i] = a1[i] + w0*a2[i];
		a[i+n/2] = a1[i] - w0*a2[i];
	}
}

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){
		double x;scanf("%lf",&x);
		a[i].real(x);
	}
	for(int i=0;i<=m;i++){
		double x;scanf("%lf",&x);
		b[i].real(x);
	}
	int len = 1<< max((int)ceil(log2(n+m)), 1);
	fft(a, len, 1);
	fft(b, len, 1);
	for(int i=0;i<=len;i++)a[i] = a[i] * b[i];
	fft(a, len, -1);
	for(int i=0;i<=n+m;i++)
		printf("%.0f ",a[i].real() / len +eps);

	return 0;
}


