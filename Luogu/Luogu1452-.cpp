#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50000
using namespace std;
int n;struct P
{
	int x,y;I P(CI a=0,CI b=0):x(a),y(b){}
	I P operator + (Con P& o) Con {return P(x+o.x,y+o.y);}
	I P operator - (Con P& o) Con {return P(x-o.x,y-o.y);}
	I int operator ^ (Con P& o) Con {return x*o.y-y*o.x;}
	I bool operator < (Con P& o) Con {return x^o.x?x<o.x:y<o.y;}
	I int L2() {return x*x+y*y;}
}p[N+5];
int T;P s[N+5];I void Get()//求凸包
{
	#define pd(A,B,C) (((C-B)^(B-A))>0||(((C-B)^(B-A))==0&&(A<B)==(B<C)))//平行也需要弹去
	RI i;for(sort(p+1,p+n+1),i=1;i<=n;s[++T]=p[i++]) W(T>1&&pd(s[T-1],s[T],p[i])) --T;
	for(i=n-1;i;s[++T]=p[i--]) W(T>1&&pd(s[T-1],s[T],p[i])) --T;--T;
}
I void Rotate()//旋转卡壳
{
	RI i,j,t=(p[1]-p[n]).L2();for(i=1,j=3;i<=T;++i)//枚举每一条边
	{
		printf("%d %d\n",s[i].x,s[i].y);
		W(((s[i+1]-s[i])^(s[j]-s[i]))<((s[i+1]-s[i])^(s[j%T+1]-s[i]))) j=j%T+1;//双指针维护最远点
		t=max(t,max((s[j]-s[i]).L2(),(s[j]-s[i+1]).L2()));//与两端点距离
		t=max(t,max((s[j%T+1]-s[i]).L2(),(s[j%T+1]-s[i+1]).L2()));//最远点可能有两个
	}printf("%d\n",t);
}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d%d",&p[i].x,&p[i].y);
	return Get(),Rotate(),0;
}

