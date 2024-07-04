int sgn(double x) {
    if (fabs(x)<eps) return 0;
    if (x<0) return -1;
    return 1;
}

// 感谢板子 
struct Point {
    double x,y;
    Point (){}
    Point (double _x,double _y):x(_x),y(_y){}
    double distance(const Point &b) const{
        return hypot(x-b.x,y-b.y);
    }
    double len(){return hypot(x,y);}
    Point operator +(const Point &b) const{return Point (x+b.x,y+b.y);}
    Point operator -(const Point &b) const{return Point (x-b.x,y-b.y);}
    double operator *(const Point &b)const{return x*b.x+y*b.y;}
    Point operator *(const double &k) const{return Point (x*k,y*k);}
    Point operator /(const double &k) const{return Point (x/k,y/k);}
    double operator ^(const Point &b)const {return x*b.y-y*b.x;}
    double len2(){return x*x+y*y;}	// hypot
    Point trunc(double r){
        double l=len();
        if (!sgn(l)) return *this;
        r/=l;
        return Point(x*r,y*r);
    }
    // 向左/右转 90 
    Point rotleft() {return Point(-y,x);}
    Point rotright(){return Point(y,-x);}
};
struct Line{
    Point s,e;
    double angle(){	// 求倾斜角 [0,2*pi] 
        double k=atan2(e.y-s.y,e.x-s.x);
        if (k<0) k+=2*pi;return k;
    }
    Line(){}
    Line(Point _s,Point _e):s(_s),e(_e){} 
    double length(){return hypot(e.x-s.x,e.y-s.y);}
    Point lineprog(Point p){
        return s+(((e-s)*((e-s)*(p-s)))/(e-s).len2());
    }
    double dispointtoline(Point p){return fabs((p-s)^(e-s))/length();}
};
struct Circle{
    Point p;double r;
    Circle(){}
    Circle(Point _p,double _r):p(_p),r(_r){}
    // 2 点在圆内 1 上 0 外 
    int relation(Point b){
        double dst=b.distance(p);
        if (sgn(dst-r)<0) return 2;
        if (sgn(dst-r)==0) return 1;
        return 0;
    }
    // 2 线与圆相交 1 相切 0 相离 
    int relationline(Line v){
        double dst=v.dispointtoline(p);
        if (sgn(dst-r)<0) return 2;
        if (sgn(dst-r)==0)return 1;
        return 0;
    }
    // 求线与圆的交点 p1,p2 
    int pointcrossline(Line v,Point &p1,Point &p2){
        if (!relationline(v)) return 0;
        Point a=v.lineprog(p);
        double d=v.dispointtoline(p);
        d=sqrt(r*r-d*d);
        if (sgn(d)==0) {p1=p2=a;return 1;}
        p1=a+(v.e-v.s).trunc(d);
        p2=a-(v.e-v.s).trunc(d);
        return 2;
    }
    int tangentline(Point q,Line &u,Line &v){
        int x=relation(q);
        if (x==2) return 0;
        if (x==1) {
            u=Line(q,q+(q-p).rotleft());
            v=Line(q,q+(q-p).rotright());
            return 2;
        }
        double d=p.distance(q),l=r*r/d,h=sqrt(r*r-l*l);
        u=Line(q,p+((q-p).trunc(l)+(q-p).rotleft().trunc(h)));
        v=Line(q,p+((q-p).trunc(l)+(q-p).rotright().trunc(h)));
        return 2;
    }
    void circlewithcircle_s_tangentline1(Circle b,Line &u,Line &v){
        Point mid=(p+b.p)/2,p1,p2;
        tangentline(mid,u,v);
        v.e=v.e-v.s;v.s=Point(0,0);
        v.e=v.e.rotright();
        u.e=u.e-u.s;u.s=Point(0,0);
        u.e=u.e.rotleft();
        swap(u,v);
    }
    void circlewithcircle_s_tangentline2(Circle b,Line &u,Line &v){
        Point mid=(p+b.p)/2;
        tangentline(mid,u,v);
    }
}O1,O2,O3;
