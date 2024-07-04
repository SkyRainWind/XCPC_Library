int n;
struct Point{
	double x,y;
}p[maxn];

Point operator - (Point a,Point b){return Point{a.x - b.x, a.y - b.y};}
Point operator + (Point a,Point b){return Point{a.x + b.x, a.y + b.y};}

double cross(Point a,Point b){return a.x * b.y - a.y * b.x;}
// 右手定则拇指向上，叉积为正，否则为负 

Point rot(Point now,double th){	// 逆时针旋转 th 
	double x1 = now.x*cos(th) - now.y*sin(th);
	double y1 = now.x*sin(th) + now.y*cos(th);
	return Point{x1,y1};
}
