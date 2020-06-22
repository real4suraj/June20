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

void solve() {
    int n, m;
    read(n, m);
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m, 0));
    vector<pair<int, int>> pos;
    vector<pair<int, int>> res;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            if(a[i][j]){
                pos.pb(mp(i, j));
            }
        }
    }
    for(auto x: pos){
        int i = x.x, j = x.y;
        if(i + 1 >= n || j + 1 >= m) continue;
        int p1 = a[i][j];
        int p2 = a[i + 1][j];
        int p3 = a[i][j + 1];
        int p4 = a[i + 1][j + 1];
        if(p1 == 1 && p2 == 1 && p3 == 1 && p4 == 1){
            b[i][j] = 1;
            b[i + 1][j] = 1;
            b[i][j + 1] = 1;
            b[i + 1][j + 1] = 1;
            res.pb(mp(i + 1, j + 1));
        }
    }
    bool f = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] != b[i][j]){
                f = 0;
                break;
            }
        }
    }
    if(f){
        cout << res.size() << endl;
        for(auto x : res) cout << x.x << " " << x.y << endl;
    }
    else cout << "-1\n";
}

int main() {
    fastIO;
//#ifndef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
#ifdef LOCAL
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
#endif

    return 0;
}
