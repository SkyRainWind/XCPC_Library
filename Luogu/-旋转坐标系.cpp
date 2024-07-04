int n;
struct Point{
	double x,y;
}p[maxn];

Point operator - (Point a,Point b){return Point{a.x - b.x, a.y - b.y};}
Point operator + (Point a,Point b){return Point{a.x + b.x, a.y + b.y};}

double cross(Point a,Point b){return a.x * b.y - a.y * b.x;}
// ���ֶ���Ĵָ���ϣ����Ϊ��������Ϊ�� 

Point rot(Point now,double th){	// ��ʱ����ת th 
	double x1 = now.x*cos(th) - now.y*sin(th);
	double y1 = now.x*sin(th) + now.y*cos(th);
	return Point{x1,y1};
}
