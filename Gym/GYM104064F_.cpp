#include <bits/stdc++.h>

using i64 = long long;
template<class T>
class Frac {
private:
    T num;
    T den;
public:
    Frac(T num, T den) : num(num), den(den) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num) : Frac(num, 1) {}
    double toDouble() const {
        return 1.0 * num / den;
    }
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {
        return lhs += rhs;
    }
    friend Frac operator-(Frac lhs, const Frac &rhs) {
        return lhs -= rhs;
    }
    friend Frac operator*(Frac lhs, const Frac &rhs) {
        return lhs *= rhs;
    }
    friend Frac operator/(Frac lhs, const Frac &rhs) {
        return lhs /= rhs;
    }
    friend Frac operator-(const Frac &a) {
        return Frac(-a.num, a.den);
    }
    friend bool operator==(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den == rhs.num * lhs.den;
    }
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den != rhs.num * lhs.den;
    }
    friend bool operator<(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den < rhs.num * lhs.den;
    }
    friend bool operator>(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den > rhs.num * lhs.den;
    }
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den <= rhs.num * lhs.den;
    }
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {
        return lhs.num * rhs.den >= rhs.num * lhs.den;
    }
};

using T = i64;
struct Point {
    T x;
    T y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    
    Point &operator+=(const Point &p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x, y -= p.y;
        return *this;
    }
    Point &operator*=(const T &v) {
        x *= v, y *= v;
        return *this;
    }
    friend Point operator-(const Point &p) {
        return Point(-p.x, -p.y);
    }
    friend Point operator+(Point lhs, const Point &rhs) {
        return lhs += rhs;
    }
    friend Point operator-(Point lhs, const Point &rhs) {
        return lhs -= rhs;
    }
    friend Point operator*(Point lhs, const T &rhs) {
        return lhs *= rhs;
    }
};

T dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

T cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    Point a;
    Point b;
    Line(const Point &a = 0, const Point &b = 0) : a(a), b(b) {}
};

Point rotate(const Point &a) {
    return Point(-a.y, a.x);
}

int sgn(const Point &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0) ? 1 : -1;
}
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

i64 solve(Point s, Point e, std::vector<Point> p) {
    const int n = p.size();
    
    i64 ans = 0;
    Fenwick<int> fen(n);
    
    std::vector<int> x(n), y(n);
    
    std::vector<int> q(n);
    std::iota(q.begin(), q.end(), 0);
    
    std::sort(q.begin(), q.end(), [&](int i, int j) {
        return cross(p[i] - s, p[j] - s) > 0;
    });
    
    for (int i = 1; i < n; i++) {
        x[q[i]] = x[q[i - 1]] + (cross(p[q[i - 1]] - s, p[q[i]] - s) > 0);
    }
    
    std::sort(q.begin(), q.end(), [&](int i, int j) {
        return cross(p[i] - e, p[j] - e) < 0;
    });
    
    for (int i = 1; i < n; i++) {
        y[q[i]] = y[q[i - 1]] + (cross(p[q[i - 1]] - e, p[q[i]] - e) < 0);
    }
    
    std::sort(q.begin(), q.end(), [&](int i, int j) {
        return x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]);
    });
    
    for (int i = 0; i < n; i++) {
        ans += fen.sum(y[q[i]] + 1);
        fen.add(y[q[i]], 1);
    }
    
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int xs, ys, xe, ye;
    std::cin >> xs >> ys >> xe >> ye;
    
    Point s(xs, ys);
    Point e(xe, ye);
    
    int n;
    std::cin >> n;
    
    std::vector<Point> tl, tr, sl, sr;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        
        Point p(x, y);
        
        i64 cr = cross(e - s, p - s);
        if (cr > 0) {
            sl.push_back(p);
        } else if (cr < 0) {
            sr.push_back(p);
        } else if (dot(e - s, p - s) > 0) {
            tr.push_back(p);
        } else {
            tl.push_back(p);
        }
    }
    
    i64 ans = 0;
    
    ans += tl.size() * (tl.size() - 1) / 2;
    ans += tr.size() * (tr.size() - 1) / 2;
    
    ans += solve(s, e, sl);
    ans += solve(e, s, sr);
    
    std::cout << ans << "\n";
    
    return 0;
}

