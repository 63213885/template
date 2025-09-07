#include<bits/stdc++.h>
using namespace std;
// `计算几何模板`
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1000010;
//`Compares a double to zero`
int sgn(double x) {
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	else return 1;
}
//square of a double
inline double sqr(double x) { return x * x; }
struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	void input() {
		cin >> x >> y;
	}
	void output() {
		cout << fixed << setprecision(2);
		cout << x << " " << y << endl;
	}
	bool operator == (Point b)const {
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
	}
	bool operator < (Point b)const {
		return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
	}
	Point operator -(const Point& b)const {
		return Point(x - b.x, y - b.y);
	}
	//叉积
	double operator ^(const Point& b)const {
		return x * b.y - y * b.x;
	}
	//点积
	double operator *(const Point& b)const {
		return x * b.x + y * b.y;
	}
	//返回长度
	double len() {
		return hypot(x, y);//库函数
	}
	//返回长度的平方
	double len2() {
		return x * x + y * y;
	}
	//返回两点的距离
	double distance(Point p) {
		return hypot(x - p.x, y - p.y);
	}
	Point operator +(const Point& b)const {
		return Point(x + b.x, y + b.y);
	}
	Point operator *(const double& k)const {
		return Point(x * k, y * k);
	}
	Point operator /(const double& k)const {
		return Point(x / k, y / k);
	}
	//`计算pa  和  pb 的夹角`
	//`就是求这个点看a,b 所成的夹角`
	//`测试 LightOJ1203`
	double rad(Point a, Point b) {
		Point p = *this;
		return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
	}
	//`化为长度为r的向量`
	Point trunc(double r) {
		double l = len();
		if (!sgn(l))return *this;
		r /= l;
		return Point(x * r, y * r);
	}
	//`逆时针旋转90度`
	Point rotleft() {
		return Point(-y, x);
	}
	//`顺时针旋转90度`
	Point rotright() {
		return Point(y, -x);
	}
	//`绕着p点逆时针旋转angle`
	Point rotate(Point p, double angle) {
		Point v = (*this) - p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
	}
};


int main(){
	double x1,y1,r1,x2,y2,r2;
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	C1={x1,y1,r1};
	C2={x2,y2,r2};
	Point q={0,0};
	C1.tangentline(q,la,lb);
	C2.tangentline(q,ra,rb);
	if(((C1.relationseg(ra)==0)||(C1.relationseg(rb)==0))&&((C2.relationseg(la)==0)||(C2.relationseg(lb)==0)))puts("Yes");
	else puts("No");
}