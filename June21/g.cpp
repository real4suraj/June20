//Lord Escanor : Sin Of Pride
//When I was writing this, only God and I knew what the code meant,
//But now, only God knows.
#include <bits/stdc++.h>

#define fo(i, n) for (int i = 0; i < int(n); i++)
#define of(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define Fo(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

#define endl '\n'
#define deb(x) cout << #x << " " << x << endl;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
template<typename... T>
void write(T&&... args) {
    ((cout << args << " "), ...);
}

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
const int mod = 1e9 + 7;

void solve() {
    int n, m;
    read(n, m);
    vector<int> a(n + 1), b(m + 1);
    vector<vector<int>> c(n + 3, vector<int>(m + 3, 0));
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int j = 1; j <= m; ++j) cin >> b[j];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= a[i]; ++j){
            c[i][j] = 1;
        }
        c[i][a[i] + 1] = 2;
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= b[i]; ++j){
            if(c[j][i] == 2){
                cout << 0 << endl;
                return;
            }
            c[j][i] = 1;
        }
        if(c[b[i] + 1][i] == 1){
            cout << 0 << endl;
            return;
        }
        c[b[i] + 1][i] = 2;
    }
    int z = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!c[i][j]){
                z += z;
                if(z >= mod) z -= mod;
            }
        }
    }
    cout << z << endl;
}

int main() {
    fastIO;
//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}

