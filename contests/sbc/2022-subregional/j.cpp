#include <bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> pi;
typedef long long ll;

#define endl '\n'
#define ff first
#define ss second

#define INF 1e9

signed main(void) {
    FAST_IO;

    vector<pi> cartas(13);
    for (int i = 0; i < 10; i++) {
        cartas[i].ff = i+1;
        cartas[i].ss = 4;
    }

    for (int i = 10; i < 13; i++) {
        cartas[i].ff = 10;
        cartas[i].ss = 4;
    }

    int pts_joao = 0;
    int pts_maria = 0;
    int n; cin >> n;

    // Leitura Joao
    for (int i = 0; i < 2; i++) {
        int x; cin >> x;
        pts_joao += cartas[x - 1].ff; 
        cartas[x - 1].ss--;
    }

    // Leitura Maria
    for (int i = 0; i < 2; i++) {
        int x; cin >> x;
        pts_maria += cartas[x - 1].ff; 
        cartas[x - 1].ss--;
    }

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pts_joao += cartas[x - 1].ff; 
        pts_maria += cartas[x - 1].ff; 
        cartas[x - 1].ss--;
    }
    
    // Maria chegar em 23
    int resp1 = INF;
    int obj = 23 - pts_maria;
    if (obj <= 10) {
        if (obj == 10) {
            // Precisa de 10, uma valeta, dama ou rei
            if (cartas[9].ss > 0) {
                resp1 = 10;
            } else if (cartas[10].ss > 0) {
                resp1 = 11;
            } else if (cartas[11].ss > 0) {
                resp1 = 12;
            } else if (cartas[12].ss > 0) {
                resp1 = 13;
            }
        } else {
            // < 10
            if (cartas[obj-1].ss > 0) {
                resp1 = obj;
            }
        }
    }


    // Joao estourar os 23
    int resp2 = INF;
    obj = 24 - pts_joao;
    if (obj <= 10) {
        if (obj == 10) {
            // Precisa de 10, uma valeta, dama ou rei
            if (cartas[9].ss > 0) {
                resp2 = 10;
            } else if (cartas[10].ss > 0) {
                resp2 = 11;
            } else if (cartas[11].ss > 0) {
                resp2 = 12;
            } else if (cartas[12].ss > 0) {
                resp2 = 13;
            }
        } else {
            // < 10
            for (int i = obj-1; i < 13; i++) {
                if (cartas[i].ff + pts_maria > 23) break;
                if (cartas[i].ss > 0) {
                    resp2 = i+1;
                    break;
                }
            }
        }
    } 

    if (min(resp1, resp2) == INF) {
        cout << -1 << endl;
    } else {
        cout << min(resp1, resp2) << endl;
    }
}