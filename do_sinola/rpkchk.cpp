#include <bits/stdc++.h>

#define rep(a,b,c) for(auto a = (b); a != (c); a++)
#define repD(a,b,c) for(auto a = (b); a != (c); a--)
#define repIn(a, b) for(auto& a : (b))
#define repIn2(a, b, c) for(auto& [a, b] : (c))

constexpr bool dbg = 1;
#define DEBUG if constexpr(dbg)
#define DC DEBUG std::cerr
#define eol std::endl

#define ld long double
#define pb push_back


#include "oi.h"
using namespace std;

void endf(const char *msg, int line, int) {
    cout << "WRONG" << endl;
    cout << "Wiersz " << line << ": " << msg << endl;
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        cerr << "Uruchomienie: " << argv[0] << " in out wzo" << endl;
        return 1;
    }

    ifstream fin(argv[1]);
    int n, k;
    fin >> n >> k;
    vector<pair<int, int>> where(k, {-1, -1});
    vector<vector<int>> b1(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) {
        fin >> b1[i][j];
        if(!b1[i][j]) continue;
        where[b1[i][j] - 1] = {i, j};
    }
    vector<vector<int>> b2(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) fin >> b2[i][j];

    ifstream fwzo(argv[3]);
    string trueAns;
    fwzo >> trueAns;

    oi::Scanner zaw(argv[2], endf, oi::PL);
    
    char s[5];
    int cnt = zaw.readString(s, 5);
    if(cnt != 3) { 
        cout << "WRONG\n";
        cout << "Zla dlugosc napisu (TAK/NIE): " << cnt << '\n';
        exit(1);
    }
    string S;
    rep(i, 0, 3) S.pb(s[i]);
    if(S != trueAns) {
        cout << "WRONG\n";
        cout << "Niepoprawny napis: oczekiwano " << trueAns << ", a otrzymano " << S << '\n';
        exit(1);
    }
    if(S == "NIE") {
        cout << "OK\n";
        return 0;
    }

    zaw.skipWhitespaces();

    int ops = zaw.readInt();
    zaw.readEoln();
    if(ops > 5000000 || ops < 0) { 
        cout << "WRONG\n";
        cout << "Niepoprawna liczba ruchow: " << ops << '\n';
        exit(1);
    }
    rep(ruch, 0, ops) {
        int a = zaw.readInt(1, k);
        zaw.readSpace();
        int b = zaw.readInt(1, n);
        zaw.readSpace();
        int c = zaw.readInt(1, n);
        zaw.readEoln();
        a--, b--, c--;
        if((abs(b - where[a].first) > 1) || (abs(c - where[a].second) > 1)) {
            cout << "WRONG\n";
            cout << "Ruch " << ruch + 1 << " prowadzi na nieprzylegajace pole\n";
            exit(1);
        }
        auto [d, e] = where[a];
        b1[d][e] = 0;
        where[a] = {b, c};
        b1[b][c] = a + 1;
        bool A = b1[b][c];
        bool B = (b + 1 < n ? b1[b + 1][c] : 0);
        bool C = (c + 1 < n ? b1[b][c + 1] : 0);
        bool D = (b + 1 < n && c + 1 < n ? b1[b + 1][c + 1] : 0);
        if(((int)A + B + C + D) > 1) {
            cout << "WRONG\n";
            cout << "Ruch " << ruch + 1 << " prowadzi do ataku krolow\n";
            exit(1);
        }
    }

    rep(i, 0, n) rep(j, 0, n) if(b1[i][j] != b2[i][j]) {
            cout << "WRONG\n";
            cout << "Nie doprowadzono do stanu docelowego\n";
            exit(1);
    }

    cout << "OK\n";
    // cout << "comment\n";
    // cout << "100\n";  // % of points
    return 0;
}




