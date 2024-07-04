#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#include <string>
#include <array>
using namespace std;

#define lowbit(x) x&-x

typedef long long ll;

const int N = 500005;
const ll inf  = 1LL << 60;
const double eps = 1e-10;

int T, n;

int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) {
        x = _x, y = _y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    bool operator < (const Point &b) const {
        if (sgn(x - b.x) == 0) return y < b.y;
        return x < b.x;
    }
    bool operator == (const Point &b) const {
        if (sgn(x - b.x) == 0 && sgn(y - b.y) == 0) return true;
        return false;
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
}a[N], b[N];
vector<Point> res;

bool check(Point tmp) {
    for (int i = 1; i <= n; i++) {
        int num = 0;
        if (sgn(tmp.x - a[i].x) == 0) num++;
        if (sgn(tmp.y - a[i].y) == 0) num++;
        if (sgn( (tmp.x - a[i].x) - (tmp.y - a[i].y) ) == 0) num++;
        if (sgn( (tmp.x - a[i].x) - (a[i].y - tmp.y) ) == 0) num++;
        if (num == 0) return false;
    }
    return true;
}

array<double, 5> get(Point tmp, int op) {
    array<double, 5> res = {inf, inf, inf, inf};
    if (op == 1) 
        res[0] = tmp.x;
    if (op == 2)
        res[1] = tmp.y;
    if (op == 3)
        res[2] = tmp.y - tmp.x;
    if (op == 4)
        res[3] = tmp.x + tmp.y;
    return res;
}

Point get(int x, int y, int z) {
    array<double, 5> tmp[5], ans = {inf, inf, inf, inf};
    tmp[0] = get(res[0], x);
    tmp[1] = get(res[1], y);
    tmp[2] = get(res[2], z);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                if (sgn(tmp[j][i] - tmp[k][i]) != 0 && (sgn(tmp[j][i] - inf) != 0 && sgn(tmp[k][i] - inf) != 0))
                    return Point(0, 0);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i] = min(ans[i], tmp[j][i]);
        }
    }
    if (sgn(ans[0] - inf) != 0 && sgn(ans[1] - inf) != 0) {
        if (sgn(ans[1] - ans[0] - ans[2]) != 0 && sgn(ans[2] - inf) != 0) return Point(0, 0);
        if (sgn(ans[1] + ans[0] - ans[3]) != 0 && sgn(ans[3] - inf) != 0) return Point(0, 0);
        return Point(ans[0], ans[1]);
    }
    if (sgn(ans[0] - inf) == 0 && sgn(ans[1] - inf) == 0) {
        if (sgn(ans[2] - inf) == 0 || sgn(ans[3] - inf) == 0) return Point(0, 0);
        return Point((ans[3] - ans[2]) / 2, (ans[2] + ans[3]) / 2);
    }
    if (sgn(ans[0] - inf) != 0) {
        if (sgn(ans[2] - inf) != 0) {
            ll tmpy = ans[2] + ans[0];
            if (sgn(tmpy + ans[0] - ans[3]) != 0 && sgn(ans[3] - inf) != 0) return Point(0, 0);
            else return Point(ans[0], tmpy);
        }
        else {
            return Point(ans[0], ans[3] - ans[0]);
        }
    }
    if (sgn(ans[1] - inf) != 0) {
        if (sgn(ans[2] - inf) != 0) {
            ll tmpx = ans[1] - ans[2];
            if (sgn(tmpx + ans[1] - ans[3]) != 0 && sgn(ans[3] - inf) != 0) return Point(0, 0);
            else return Point(tmpx, ans[1]);
        }
        else 
            return Point(ans[3] - ans[1], ans[1]);
    }
} 

bool Solve() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if (i == j && j == k) continue;
                Point tmp = get(i, j, k);
                if (check(tmp)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d", &T);
    while (T--) {
        res.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            a[i].input();
        }
        sort(a + 1, a + n + 1);
        int m = unique(a + 1, a + n + 1) - (a + 1);
        n = m;
        if (n <= 2) {
            printf("YES\n");
        }
        else {
            for (int i = 2; i <= n; i++) 
                b[i] = a[i] - a[1];
            bool flag = true;
            for (int i = 3; i <= n; i++) {
                if (sgn(b[i] ^ b[2]) != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (sgn(b[2].x) == 0 || sgn(b[2].y) == 0 || sgn(b[2].x - b[2].y) == 0 || sgn(b[2].x + b[2].y) == 0)
                    printf("YES\n");
                else 
                    printf("NO\n");
            }
            else {
                int d = 2;
                for (d = 2; d <= n; d++) {
                    if ((b[d] ^ b[2]) != 0) {
                        break;
                    }
                }
                res.push_back(a[1]); 
                res.push_back(a[2]);
                res.push_back(a[d]);
                if (Solve()) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}
