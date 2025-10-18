#include <bits/stdc++.h>

#define rep(a,b,c) for(auto a = (b); a != (c); a++)
#define repD(a,b,c) for(auto a = (b); a != (c); a--)
#define repIn(a, b) for(auto& a : (b))
#define repIn2(a, b, c) for(auto& [a, b] : (c))

constexpr bool dbg = 0;
#define DEBUG if constexpr(dbg)
#define DC DEBUG std::cerr
#define eol std::endl

#define ll long long
#define ld long double
#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> where(k, {-1, -1});
    vector<vector<int>> b1(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) {
        cin >> b1[i][j];
        if(!b1[i][j]) continue;
        where[b1[i][j] - 1] = {i, j};
    }
    vector<vector<int>> b2(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> b2[i][j];

    repIn2(a, b, where) assert(a != -1);
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        bool a = b1[i][j];
        bool b = b1[i + 1][j];
        bool c = b1[i][j + 1];
        bool d = b1[i + 1][j + 1];
        assert(((int)a + b + c + d) <= 1);
    }
    rep(i, 0, n - 1) rep(j, 0, n - 1) {
        bool a = b2[i][j];
        bool b = b2[i + 1][j];
        bool c = b2[i][j + 1];
        bool d = b2[i + 1][j + 1];
        assert(((int)a + b + c + d) <= 1);
    }

    string s0;
    cin >> s0;
    string s;
    cin >> s;
    if(s != s0) { cout << "Oczekiwano " << s0 << " otrzymano " << s << '\n'; return 1; }
    if(s == "NIE") { cout << "OK\n"; return 0; }
    int ops;
    cin >> ops;
    if(ops > 5000000) { cout << "Zbyt duzo operacji - " << ops << "\n"; return 1; }
    rep(ruch, 0, ops) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        if(abs(b - where[a].first) > 1) { cout << "Ruch " << ruch << " na pole nieprzylegajace \n"; return 1; }
        if(abs(c - where[a].second) > 1) { cout << "Ruch " << ruch << " na pole nieprzylegajace \n"; return 1; }
        auto [d, e] = where[a];
        b1[d][e] = 0;
        where[a] = {b, c};
        b1[b][c] = a + 1;
        bool A = b1[b][c];
        bool B = (b + 1 < n ? b1[b + 1][c] : 0);
        bool C = (c + 1 < n ? b1[b][c + 1] : 0);
        bool D = (b + 1 < n && c + 1 < n ? b1[b + 1][c + 1] : 0);
        if(((int)A + B + C + D) > 1) { cout << "Ruch " << ruch << " doprowadza do ataku \n"; return 1; }
    }

    rep(i, 0, n) rep(j, 0, n) if(b1[i][j] != b2[i][j]) { cout << "Ruchy nie prowadza do stanu koncowego\n"; return 1; }
    cout << "OK\n";
}

