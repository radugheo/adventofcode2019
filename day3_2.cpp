#include <bits/stdc++.h>

using namespace std;

int x, y, ax, ay, bx, by, b, n, m, i, j, dx, dy, a, sol;

char sa[5005], sb[5005];

pair <int, int> dira[500005], dirb[500005];

int main(){
    cin.getline(sa, 5000);
    x = 5000, y = 5000;
    a = 1;
    dira[1] = {x, y};
    for (i=0; i<strlen(sa); i++){
        if (sa[i] == 'L'){
            dx = 0, dy = -1;
        }
        if (sa[i] == 'R'){
            dx = 0, dy = 1;
        }
        if (sa[i] == 'U'){
            dx = -1, dy = 0;
        }
        if (sa[i] == 'D'){
            dx = 1, dy = 0;
        }
        if (sa[i] >= '0' && sa[i] <= '9'){
            n = 0;
            while (sa[i] >= '0' && sa[i] <= '9'){
                n = n*10 + sa[i] - '0';
                i++;
            }
            ax = dira[a].first, ay = dira[a].second;
            for (j=1; j<=n; j++){
                dira[++a] = {ax + dx*j, ay + dy*j};
            }
        }
    }
    cin.getline(sb, 5000);
    x = 5000, y = 5000;
    b = 1;
    dirb[1] = {x, y};
    for (i=0; i<strlen(sb); i++){
        if (sb[i] == 'L'){
            dx = 0, dy = -1;
        }
        if (sb[i] == 'R'){
            dx = 0, dy = 1;
        }
        if (sb[i] == 'U'){
            dx = -1, dy = 0;
        }
        if (sb[i] == 'D'){
            dx = 1, dy = 0;
        }
        if (sb[i] >= '0' && sb[i] <= '9'){
            n = 0;
            while (sb[i] >= '0' && sb[i] <= '9'){
                n = n*10 + sb[i] - '0';
                i++;
            }
            bx = dirb[b].first, by = dirb[b].second;
            for (j=1; j<=n; j++){
                dirb[++b] = {bx + dx*j, by + dy*j};
            }
        }
    }
    sol = INT_MAX;
    for (i=2; i<=a; i++){
        for (j=2; j<=b; j++){
            if (dira[i].first == dirb[j].first && dira[i].second == dirb[j].second){
                sol = min (sol, i + j - 2);
            }
        }
    }
    cout << sol;
    return 0;
}

