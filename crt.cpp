using ll = long long;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

void crt(ll& p1, ll& r1, ll p2, ll r2) {
    ll x, y;
    ll g = exgcd(p1, p2, x, y);
    if ((r2 - r1) % g) {
        return;
    }
    ll s = x % (p2 / g);
    r1 += s * p1;
    p1 *= p2 / g;
}
