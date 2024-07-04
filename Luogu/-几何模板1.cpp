//���ζ���
struct Point { double x, y; };			//��
using Vec = Point;						//����
struct Line { Point P; Vec v; };		//ֱ�ߣ�����ʽ��
struct Seg { Point A, B; };				//�߶Σ��������˵㣩
struct Circle { Point o; double r; };	//Բ����Բ�ĺͰ뾶��
//���ó���
const Point O = {0, 0};							//ԭ��
const Line Ox = {O, {1, 0}}, Oy = {O, {0, 1}};	//������
const double PI = acos(-1), EPS = 1e-9;
//����Ƚ�
bool eq(double a, double b) { return abs(a - b) < EPS; }  // ==
bool gt(double a, double b) { return a - b > EPS; } 	  // >
bool lt(double a, double b) { return a - b < -EPS; }	  // <
bool ge(double a, double b) { return a - b > -EPS; }	  // >= 	
bool le(double a, double b) { return a - b < EPS; }		  // <= 
//��������
Vec r90a(Vec v) { return {-v.y, v.x}; }								//��ʱ����ת90�ȵ�����
Vec r90c(Vec v) { return {v.y, -v.x}; }								//˳ʱ����ת90�ȵ�����
Vec operator + (Vec u, Vec v) { return {u.x + v.x, u.y + v.y}; }  	//����������
Vec operator - (Vec u, Vec v) { return {u.x - v.x, u.y - v.y}; }	//����������
Vec operator * (double k, Vec v) { return {k * v.x, k * v.y}; }		//����
double operator * (Vec u, Vec v) { return u.x * v.x + u.y * v.y; }	//���
double operator ^ (Vec u, Vec v) { return u.x * v.y - u.y * v.x; }	//���
double len(Vec v) { return sqrt(v.x * v.x + v.y * v.y); }			//��������
double slope(Vec v) { return v.y / v.x; }							//б�� 
											//NOTE ��Ҫ��isinf�ж�б�ʲ����ڣ��ú����paral_y
//�������
double cos_t(Vec u, Vec v) { return u * v / (len(u)) / len(v); }	//�������ļн�����
Vec norm(Vec v) { return {v.x / len(v), v.y / len(v)}; }			//��һ������(��ԭ����������ͬ�ĵ�λ����)
Vec pnorm(Vec v) { return (v.x < 0 ? -1 : 1) / len(v) * v; }		//��ԭ����ƽ���Һ�������ڵ���0�ĵ�λ����
Vec dvec(Seg l) { return l.B - l.A; }								//�߶εķ�������
//ֱ�����
Line line(Point A, Point B) { return {A, B - A}; }									//����ʽֱ��
Line line(double k, double b) { return {{0, b}, {1, k}}; }							//б��ʽֱ��
Line line(Point P, double k) { return {P, {1, k}}; }								//��бʽֱ��
Line line(Seg l) { return {l.A, l.B - l.A}; }										//�߶�����ֱ��
double at_x(Line l, double x) { return l.P.y + (x - l.P.x) * l.v.y / l.v.x; }		//����ֱ�ߵĺ�������������
double at_y(Line l, double y) { return l.P.x - (y + l.P.y) * l.v.x / l.v.y; }		//����ֱ�ߵ��������������
Point pedal(Point P, Line l) { return l.P - (l.P - P) * l.v / (l.v * l.v) * l.v; }	//�㵽ֱ�ߵĴ���
Line perp(Line l, Point P) { return {P, r90c(l.v)}; }								//��ĳ����ֱ�ߵĴ���
Line bisec(Point P, Vec u, Vec v) { return {P, norm(u) + norm(v)}; }				//��ƽ����
//�߶����
//Vec dvec(Seg l) { return l.B - l.A; }										//�߶εķ�������
Point midp(Seg l) { return {(l.A.x + l.B.x) / 2, (l.A.y + l.B.y) / 2}; }	//�߶��е�
Line perp(Seg l) { return {midp(l), r90c(l.B - l.A)}; }						//�߶��д���
//���ζ���֮��Ĺ�ϵ
bool verti(Vec u, Vec v) { return eq(u * v, 0); }													//�����Ƿ��ഹֱ
bool paral(Vec u, Vec v) { return eq(u ^ v, 0); }													//�����Ƿ���ƽ��
bool paral_x(Vec v) { return eq(v.y, 0); }															//�����Ƿ���x��ƽ��
bool paral_y(Vec v) { return eq(v.x, 0); }															//�����Ƿ���y��ƽ��
bool on(Point P, Line l) { return eq((P.x - l.P.x) * l.v.y, (P.y - l.P.y) * l.v.x); }				//���Ƿ���ֱ����
bool on(Point P, Seg l) { return eq(len(P - l.A) + len(P - l.B), len(l.A - l.B)); }					//���Ƿ����߶���
bool operator == (Point A, Point B) { return eq(A.x, B.x) && eq(A.y, B.y); }						//�������Ƿ��غ�
bool operator == (Line a, Line b) { return on(a.P, b) && on(a.P + a.v, b); }						//����ֱ���Ƿ��غ�
bool operator == (Seg a, Seg b) { return (a.A == b.A && a.B == b.B) || (a.A == b.B && a.B == b.A); }	//�����߶��Ƿ��غ�
bool operator < (Point A, Point B) { return lt(A.x, B.x) || (eq(A.x, B.x) && lt(A.y, B.y)); }		//�Ժ�����Ϊ��һ�ؼ��ʡ�������Ϊ�ڶ��ؼ��ʱȽ�������
bool tangency(Line l, Circle C) { return eq(abs((C.o ^ l.v) - (l.P ^ l.v)), C.r * len(l.v)); }		//ֱ����Բ�Ƿ�����
bool tangency(Circle C1, Circle C2) { return eq(len(C1.o - C2.o), C1.r + C2.r); }					//Բ��Բ�Ƿ�����(����)
//����
double dis(Point A, Point B) { return len(A - B); }									//�����ľ���
double dis(Point P, Line l) { return abs((P ^ l.v) - (l.P ^ l.v)) / len(l.v); }		//�㵽ֱ�ߵľ���
double dis(Line a, Line b) { return abs((a.P ^ pnorm(a.v)) - (b.P ^ pnorm(b.v))); }	//ƽ��ֱ�߼�ľ���
//ƽ��
Line operator + (Line l, Vec v) { return {l.P + v, l.v}; }
Seg operator + (Seg l, Vec v) { return {l.A + v, l.B + v}; }
//��ת
Point rotate(Point P, double rad) { return {cos(rad) * P.x - sin(rad) * P.y, sin(rad) * P.x + cos(rad) * P.y}; }
Point rotate(Point P, double rad, Point C) { return C + rotate(P - C, rad); }
Line rotate(Line l, double rad, Point C = O) { return {rotate(l.P, rad, C), rotate(l.v, rad)}; }
Seg rotate(Seg l, double rad, Point C = O) { return {rotate(l.A, rad, C), rotate(l.B, rad, C)}; }
//���ڶԳ�
Point reflect(Point A, Point P) { return {P.x * 2 - A.x, P.y * 2 - A.y}; }
Line reflect(Line l, Point P) { return {reflect(l.P, P), l.v}; }
Seg reflect(Seg l, Point P) { return {reflect(l.A, P), reflect(l.B, P)}; }
//����ֱ�߶Գ�
Point reflect(Point A, Line ax) { return reflect(A, pedal(A, ax)); }
Vec reflect_v(Vec v, Line ax) { return reflect(v, ax) - reflect(O, ax); }    
Line reflect(Line l, Line ax) { return {reflect(l.P, ax), reflect_v(l.v, ax)}; }
Seg reflect(Seg l, Line ax) { return {reflect(l.A, ax), reflect(l.B, ax)}; }
//����
vector<Point> inter(Line a, Line b) { // ֱ����ֱ�߽���
	double c = a.v ^ b.v;
	if(eq(c, 0)) return {};
	Vec v = 1 / c * Vec{a.P ^ (a.P + a.v), b.P ^ (b.P + b.v)};
	return {{v * Vec{-b.v.x, a.v.x}, v * Vec{-b.v.y, a.v.y}}};
}
vector<Point> inter(Line l, Circle C) {// ֱ����Բ����
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
Point barycenter(Point A, Point B, Point C) { // �����ε�����
    return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
}
Point circumcenter(Point A, Point B, Point C) { // �����ε�����
    double a = A * A, b = B * B, c = C * C;
    double d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    return 1 / d * r90c(a * (B - C) + b * (C - A) + c * (A - B));
}
Point incenter(Point A, Point B, Point C) { // �����ε�����
    double a = len(B - C), b = len(A - C), c = len(A - B);
    double d = a + b + c;
    return 1 / d * (a * A + b * B + c * C);
}
Point orthocenter(Point A, Point B, Point C) { // �����εĴ���
    double n = B * (A - C), m = A * (B - C);
    double d = (B - C) ^ (A - C);
    return 1 / d * r90c(n * (C - B) - m * (C - A));
}
// Բ��Բ�� 
int T_C_C(Circle a,Circle b,vector<Point>&pa,vector<Point>&pb)
{
    if(a.r>b.r)swap(a,b),swap(pa,pb);
    double dis = len(a.p-b.p),rd = fabs(a.r-b.r),rs = a.r+b.r;
    if(dcmp(dis-rd)<0)return 0;
    if(!dcmp(dis)&&!dcmp(a.r-b.r))return -1;
    double rad = ang(b.p-a.p);	// atan2(y,x) 
    if(!dcmp(dis-rd))
    {
    	// a.point(rad) ��Բ�ĳ� rad �нǵ�Բ�ϵĵ� 
        pa.push_back(a.point(rad)),pb.push_back(b.point(rad));
        return 1;
    }
    double drad = acos(rd/dis);
    pa.push_back(a.point(rad+drad)),pb.push_back(b.point(rad+drad));
    pa.push_back(a.point(rad-drad)),pb.push_back(b.point(rad-drad));
    // �����⹫����
	 
    if(!dcmp(dis-rs))
    {
        pa.push_back(a.point(rad)),pb.push_back(b.point(-rad));
        return 3;
    }else if(dcmp(dis-rs)>0)
    {
        drad = acos(rs/dis);
        // �����ڹ����� 
        pa.push_back(a.point(rad+drad)),pb.push_back(b.point(rad-drad));
        pa.push_back(a.point(rad-drad)),pb.push_back(b.point(rad+drad));
        return 4;
    }else return 2;
}

