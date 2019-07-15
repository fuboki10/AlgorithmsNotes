// Fub0ki
// (づ°ω°)づﾐ★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long             ll;
typedef vector<int>           vi;
typedef vector<ll>            vll;
typedef pair<int, int>        ii;
typedef pair<int, ii>         iii;
typedef vector<ii>            vii;
typedef set<int>              si;
typedef map<string, int>      msi;
typedef map<string, string>   mss;
#define clr(x,v) memset(x,v,sizeof(x))
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define bn begin()
#define nd end()
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define NumofDigits(n) ((int)log10(n)+1)
#define sc1(x)  scanf("%d",&x)
#define sc2(x,y)  scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sz(v) (int)(v.size())
#define rep(i,v) for (int i = 0; i < sz(v); i++)
#define lp(i, a, b) for (int i = int(a); i < int(b); i++)
#define lpi(i, b, a) for (int i = int(b); i >= a; i--)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-10
#define MAX 1000005
#define INF 1e18
const double PI = acos(-1.0);
#define print_prec(ans,num) cout << fixed << setprecision(num) << (ans) << endl
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistic*/
/*max_element(all(m),
    [](const ii& p1, const ii& p2) {
        return p1.second < p2.second; });*/
#define DEG_TO_RAD(a)  (a * PI / 180.0)
struct point_i
{
    int x,y;
    point_i(int _x=0, int _y=0) {x = _x, y = _y;}
};
struct point
{
    double x,y;
    point() {x = y = 0;}
    point(double _x, double _y) {x = _x, y = _y;}
};
struct line
{
    double a,b,c;
};
void to_line(point_i p1, point_i p2, line& l)
{
    if (p1.x == p2.x)
    {
        l.b = 0.0;
        l.a = 1.0;
        l.c = -(double)p1.x;
    }
    else
    {
        l.b = 1.0;
        l.a = -(double)(p1.y - p2.y) / (double)(p1.x - p2.x);
        l.c = -(double)(p1.y + l.a * p1.x);
    }
}
bool are_parallel(line& l1, line& l2)
{
    return ((fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS));
}
bool are_same(line& l1, line& l2)
{
    return ((are_parallel(l1,l2)) && (fabs(l1.c - l2.c) < EPS));
}
bool are_intersect(line l1, line l2, point &p)
{
    if (are_parallel(l1,l2)) return 0;
    p.x = (l1.b * l2.c - l2.b * l1.c) / (l1.a * l2.b - l1.b * l2.a);
    if (fabs(l2.b) > EPS) p.y = -(l2.a * p.x + l2.c);
    else p.y = -(l1.a * p.x + l1.c);
    return 1;
}
double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
point rotate(point p1, double theta)
{
    double rad = DEG_TO_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}
struct vec
{
    double x,y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec to_vec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s)
{
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v)
{
    return point(p.x + v.x, p.y + v.y);
}
double dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}
double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c); } // Euclidean distance between p and c

    // returns the distance from p to the line segment ab defined by
    // two points a and b (still OK if a == b)
    // the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); // closer to a
    return dist(p, a); } // Euclidean distance between p and a
    if (u > 1.0) { c = point(b.x, b.y); // closer to b
    return dist(p, b); } // Euclidean distance between p and b
    return distToLine(p, a, b, c); } // run distToLine as above

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVector(o, a), ob = toVector(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
    // note: to accept collinear points, we have to change the ‘> 0’
    // returns true if point r is on the left side of line pq

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }

    // returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("write.txt", "w", stdout);
    //IO;
    return 0;
}
