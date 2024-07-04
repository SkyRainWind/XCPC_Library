//几何对象
struct Point { double x, y; };			//点
using Vec = Point;						//向量
struct Line { Point P; Vec v; };		//直线（点向式）
struct Seg { Point A, B; };				//线段（存两个端点）
struct Circle { Point o; double r; };	//圆（存圆心和半径）
//常用常量
const Point O = {0, 0};							//原点
const Line Ox = {O, {1, 0}}, Oy = {O, {0, 1}};	//坐标轴
const double PI = acos(-1), EPS = 1e-9;
//浮点比较
bool eq(double a, double b) { return abs(a - b) < EPS; }  // ==
bool gt(double a, double b) { return a - b > EPS; } 	  // >
bool lt(double a, double b) { return a - b < -EPS; }	  // <
bool ge(double a, double b) { return a - b > -EPS; }	  // >= 	
bool le(double a, double b) { return a - b < EPS; }		  // <= 
//基础操作
Vec r90a(Vec v) { return {-v.y, v.x}; }								//逆时针旋转90度的向量
Vec r90c(Vec v) { return {v.y, -v.x}; }								//顺时针旋转90度的向量
Vec operator + (Vec u, Vec v) { return {u.x + v.x, u.y + v.y}; }  	//向量加向量
Vec operator - (Vec u, Vec v) { return {u.x - v.x, u.y - v.y}; }	//向量减向量
Vec operator * (double k, Vec v) { return {k * v.x, k * v.y}; }		//数乘
double operator * (Vec u, Vec v) { return u.x * v.x + u.y * v.y; }	//点乘
double operator ^ (Vec u, Vec v) { return u.x * v.y - u.y * v.x; }	//叉乘
double len(Vec v) { return sqrt(v.x * v.x + v.y * v.y); }			//向量长度
double slope(Vec v) { return v.y / v.x; }							//斜率 
											//NOTE 不要用isinf判断斜率不存在，用后面的paral_y
//向量相关
double cos_t(Vec u, Vec v) { return u * v / (len(u)) / len(v); }	//两向量的夹角余弦
Vec norm(Vec v) { return {v.x / len(v), v.y / len(v)}; }			//归一化向量(与原向量方向相同的单位向量)
Vec pnorm(Vec v) { return (v.x < 0 ? -1 : 1) / len(v) * v; }		//与原向量平行且横坐标大于等于0的单位向量
Vec dvec(Seg l) { return l.B - l.A; }								//线段的方向向量
//直线相关
Line line(Point A, Point B) { return {A, B - A}; }									//两点式直线
Line line(double k, double b) { return {{0, b}, {1, k}}; }							//斜截式直线
Line line(Point P, double k) { return {P, {1, k}}; }								//点斜式直线
Line line(Seg l) { return {l.A, l.B - l.A}; }										//线段所在直线
double at_x(Line l, double x) { return l.P.y + (x - l.P.x) * l.v.y / l.v.x; }		//给定直线的横坐标求纵坐标
double at_y(Line l, double y) { return l.P.x - (y + l.P.y) * l.v.x / l.v.y; }		//给定直线的纵坐标求横坐标
Point pedal(Point P, Line l) { return l.P - (l.P - P) * l.v / (l.v * l.v) * l.v; }	//点到直线的垂足
Line perp(Line l, Point P) { return {P, r90c(l.v)}; }								//过某点作直线的垂线
Line bisec(Point P, Vec u, Vec v) { return {P, norm(u) + norm(v)}; }				//角平分线
//线段相关
//Vec dvec(Seg l) { return l.B - l.A; }										//线段的方向向量
Point midp(Seg l) { return {(l.A.x + l.B.x) / 2, (l.A.y + l.B.y) / 2}; }	//线段中点
Line perp(Seg l) { return {midp(l), r90c(l.B - l.A)}; }						//线段中垂线
//几何对象之间的关系
bool verti(Vec u, Vec v) { return eq(u * v, 0); }													//向量是否互相垂直
bool paral(Vec u, Vec v) { return eq(u ^ v, 0); }													//向量是否互相平行
bool paral_x(Vec v) { return eq(v.y, 0); }															//向量是否与x轴平行
bool paral_y(Vec v) { return eq(v.x, 0); }															//向量是否与y轴平行
bool on(Point P, Line l) { return eq((P.x - l.P.x) * l.v.y, (P.y - l.P.y) * l.v.x); }				//点是否在直线上
bool on(Point P, Seg l) { return eq(len(P - l.A) + len(P - l.B), len(l.A - l.B)); }					//点是否在线段上
bool operator == (Point A, Point B) { return eq(A.x, B.x) && eq(A.y, B.y); }						//两个点是否重合
bool operator == (Line a, Line b) { return on(a.P, b) && on(a.P + a.v, b); }						//两条直线是否重合
bool operator == (Seg a, Seg b) { return (a.A == b.A && a.B == b.B) || (a.A == b.B && a.B == b.A); }	//两条线段是否重合
bool operator < (Point A, Point B) { return lt(A.x, B.x) || (eq(A.x, B.x) && lt(A.y, B.y)); }		//以横坐标为第一关键词、纵坐标为第二关键词比较两个点
bool tangency(Line l, Circle C) { return eq(abs((C.o ^ l.v) - (l.P ^ l.v)), C.r * len(l.v)); }		//直线与圆是否相切
bool tangency(Circle C1, Circle C2) { return eq(len(C1.o - C2.o), C1.r + C2.r); }					//圆与圆是否相切(外切)
//距离
double dis(Point A, Point B) { return len(A - B); }									//两点间的距离
double dis(Point P, Line l) { return abs((P ^ l.v) - (l.P ^ l.v)) / len(l.v); }		//点到直线的距离
double dis(Line a, Line b) { return abs((a.P ^ pnorm(a.v)) - (b.P ^ pnorm(b.v))); }	//平行直线间的距离
//平移
Line operator + (Line l, Vec v) { return {l.P + v, l.v}; }
Seg operator + (Seg l, Vec v) { return {l.A + v, l.B + v}; }
//旋转
Point rotate(Point P, double rad) { return {cos(rad) * P.x - sin(rad) * P.y, sin(rad) * P.x + cos(rad) * P.y}; }
Point rotate(Point P, double rad, Point C) { return C + rotate(P - C, rad); }
Line rotate(Line l, double rad, Point C = O) { return {rotate(l.P, rad, C), rotate(l.v, rad)}; }
Seg rotate(Seg l, double rad, Point C = O) { return {rotate(l.A, rad, C), rotate(l.B, rad, C)}; }
//关于对称
Point reflect(Point A, Point P) { return {P.x * 2 - A.x, P.y * 2 - A.y}; }
Line reflect(Line l, Point P) { return {reflect(l.P, P), l.v}; }
Seg reflect(Seg l, Point P) { return {reflect(l.A, P), reflect(l.B, P)}; }
//关于直线对称
Point reflect(Point A, Line ax) { return reflect(A, pedal(A, ax)); }
Vec reflect_v(Vec v, Line ax) { return reflect(v, ax) - reflect(O, ax); }    
Line reflect(Line l, Line ax) { return {reflect(l.P, ax), reflect_v(l.v, ax)}; }
Seg reflect(Seg l, Line ax) { return {reflect(l.A, ax), reflect(l.B, ax)}; }
//交点
vector<Point> inter(Line a, Line b) { // 直线与直线交点
	double c = a.v ^ b.v;
	if(eq(c, 0)) return {};
	Vec v = 1 / c * Vec{a.P ^ (a.P + a.v), b.P ^ (b.P + b.v)};
	return {{v * Vec{-b.v.x, a.v.x}, v * Vec{-b.v.y, a.v.y}}};
}
vector<Point> inter(Line l, Circle C) {// 直线与圆交点
	Point P = pedal(C.o, l);
	double h = len(P - C.o);
	if(gt(h, C.r)) return {};
	if(eq(h, C.r)) return {P};
	double d = sqrt(C.r * C.r - h * h);
	Vec vec = d / len(l.v) * l.v;
	return {P + vec, P - vec};
}
vector<Point> inter(Circle C1, Circle C2) {
	Vec v1 = C2.o - C1.o, v2 = r90c(v1);
	double d = len(v1);
	if(gt(d, C1.r + C2.r) || gt(abs(C1.r - C2.r), d)) return {};
	if(eq(d, C1.r + C2.r) || eq(d, abs(C1.r - C2.r))) return {C1.o + C1.r / d * v1};
	double a = ((C1.r * C1.r - C2.r * C2.r) / d + d) / 2;
	double h = sqrt(C1.r * C1.r - a * a);
	Vec av = a / len(v1) * v1, hv = h / len(v2) * v2;
	return {C1.o + av + hv, C1.o + av - hv};
}
Point barycenter(Point A, Point B, Point C) { // 三角形的重心
    return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
}
Point circumcenter(Point A, Point B, Point C) { // 三角形的外心
    double a = A * A, b = B * B, c = C * C;
    double d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    return 1 / d * r90c(a * (B - C) + b * (C - A) + c * (A - B));
}
Point incenter(Point A, Point B, Point C) { // 三角形的内心
    double a = len(B - C), b = len(A - C), c = len(A - B);
    double d = a + b + c;
    return 1 / d * (a * A + b * B + c * C);
}
Point orthocenter(Point A, Point B, Point C) { // 三角形的垂心
    double n = B * (A - C), m = A * (B - C);
    double d = (B - C) ^ (A - C);
    return 1 / d * r90c(n * (C - B) - m * (C - A));
}
// 圆与圆交 
int T_C_C(Circle a,Circle b,vector<Point>&pa,vector<Point>&pb)
{
    if(a.r>b.r)swap(a,b),swap(pa,pb);
    double dis = len(a.p-b.p),rd = fabs(a.r-b.r),rs = a.r+b.r;
    if(dcmp(dis-rd)<0)return 0;
    if(!dcmp(dis)&&!dcmp(a.r-b.r))return -1;
    double rad = ang(b.p-a.p);	// atan2(y,x) 
    if(!dcmp(dis-rd))
    {
    	// a.point(rad) 与圆心成 rad 夹角的圆上的点 
        pa.push_back(a.point(rad)),pb.push_back(b.point(rad));
        return 1;
    }
    double drad = acos(rd/dis);
    pa.push_back(a.point(rad+drad)),pb.push_back(b.point(rad+drad));
    pa.push_back(a.point(rad-drad)),pb.push_back(b.point(rad-drad));
    // 两条外公切线
	 
    if(!dcmp(dis-rs))
    {
        pa.push_back(a.point(rad)),pb.push_back(b.point(-rad));
        return 3;
    }else if(dcmp(dis-rs)>0)
    {
        drad = acos(rs/dis);
        // 两条内公切线 
        pa.push_back(a.point(rad+drad)),pb.push_back(b.point(rad-drad));
        pa.push_back(a.point(rad-drad)),pb.push_back(b.point(rad+drad));
        return 4;
    }else return 2;
}

