#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int high(ll a) //求有二进制多少位的板子
{
    int cnt = 0;
    while (a)
    {
        a >>= 1;
        cnt++;
    }
    return cnt - 1;
}
int main()
{
    int n;
    cin >> n;
    ll l, r;
    while (n--)
    {
        cin >> l >> r;
        ll lena = high(l);
        ll lenb = high(r);
        if (lena == lenb)
        {
            ll lenc = high(l ^ r);
            for (ll i = 0; i <= lenc; i++)
            {
//补1必须得强制化为longlong类型否则那个1默认为int会数据溢出
                r |= ((ll)1 << i); 
            }
            cout << r << endl;
        }
        else
        {
            for (ll i = 0; i <= lenb; i++)
            {
                r |= ((ll)1 << i);
            }
            cout << r << endl;
        }
    }
}