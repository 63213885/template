//这回只花了114514min就打完了。
//真好。记得多手造几组。ACM拍什么拍。 
#include "bits/stdc++.h"
using namespace std;
template<class T1, class T2> istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin>>a.first>>a.second; }
template<class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const pair<T1, T2> &a) { return cout<<a.first<<' '<<a.second; }
template<class T1, class T2> ostream &operator<<(ostream &cout, const vector<pair<T1, T2>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const valarray<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<valarray<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }
template<class T1> ostream &operator<<(ostream &cout, const vector<vector<T1>> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<'\n'<<a[i]; return cout; }
template<class T1, class T2> bool cmin(T1 &x, const T2 &y) { if (y<x) { x=y; return 1; } return 0; }
template<class T1, class T2> bool cmax(T1 &x, const T2 &y) { if (x<y) { x=y; return 1; } return 0; }
template<class T1> vector<T1> range(T1 l, T1 r, T1 step=1) { assert(step>0); int n=(r-l+step-1)/step, i; vector<T1> res(n); for (i=0; i<n; i++) res[i]=l+step*i; return res; }
template<class T1> basic_string<T1> operator*(const basic_string<T1> &s, int m) { auto r=s; m*=s.size(); r.resize(m); for (int i=s.size(); i<m; i++) r[i]=r[i-s.size()]; return r; }

typedef unsigned ui;
typedef long double db;
typedef long long ll;
typedef __int128 lll;
istream &operator>>(istream &cin, lll &x) { x=0; static string s; cin>>s; for (char c:s) x=x*10+(c-'0'); return cin; }
ostream &operator<<(ostream &cout, lll x) { static char s[60]; int tp=1; s[0]='0'+(x%10); while (x/=10) s[tp++]='0'+(x%10); while (tp--) cout<<s[tp]; return cout; }
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int n, m, i;
	cin>>n>>m;
	vector<int> a(n);
	for (int &x:a) cin>>x, x%=m;
	sort(all(a)); a.resize(unique(all(a))-a.begin());
	queue<int> q;
	vector<int> d(m);
	q.push(0);
	while (q.size()&&!d[0])
	{
		int u=q.front(); q.pop();
		for (int v:a)
		{
			int k=(u+v)%m;
			if (!d[k]) q.push(k), d[k]=d[u]+1;
		}
	}
	cout<<d[0]<<endl;
}
