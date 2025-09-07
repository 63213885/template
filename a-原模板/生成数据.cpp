#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define debug(var) \
	cerr << #var << " = " << var << endl
mt19937_64 rng(time(0));
const int N=1e5+10;
int n, m, q, x;
int a[N];

int rnd(int l,int r) {
	int len=r-l+1;
	int x=l+(rng()%len+len)%len;
	return x;
}

void solve()
{
	n = 1000;
	m = 100000;
	x = rnd(1, n);
	cout << n << " " << m << " " << x << endl;
	
	for (int i = 0; i < m; i++) {
		int u = rnd(1, n), v = rnd(1, n), w = rnd(1, 100);
		while (u == v) {
			u = rnd(1, n);
			v = rnd(1, n);
		}
		cout << u << " " << v << " " << w << endl;
	}
}
void init() {
	FILE *p1=freopen("ex_A1.in", "r", stdin);
	FILE *p2=freopen("ex_A1.out", "w", stdout);
	auto _clock_start=chrono::high_resolution_clock::now();
	solve();
	cerr<<"′e°?ò?éú3é?￡";
	cerr<<"ó?ê±￡o"<<chrono::duration_cast<chrono::milliseconds>
		(chrono::high_resolution_clock::now()-_clock_start).count() 
		<<"ms."<<endl;
	fclose(p1); fclose(p2);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	FILE *p = freopen("G.in", "w", stdout);
	auto _clock_start=chrono::high_resolution_clock::now();
	solve();
	cerr<<"数据已生成。";
	cerr<<"用时："<<chrono::duration_cast<chrono::milliseconds>
		(chrono::high_resolution_clock::now()-_clock_start).count()
		<<"ms."<<endl;
	fclose(p);
	return 0 ^ 0;
}
