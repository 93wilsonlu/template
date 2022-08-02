using ll = long long;

ll pow(ll a, ll b, ll m) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        return a * pow(a, b - 1, m) % m;
    }
    ll result = pow(a, b >> 1, m);
    return result * result % m;
}