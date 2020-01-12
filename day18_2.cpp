#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day18.in");

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m, starti, startj, i, j, k;
int cheie[16];

map <int, int> dist[1005][1005];

int sol;

vector <string> mat;

string s;

queue <pair <pair <int, int>, int> > q;

bitset <30> f;

int befese () {
    int i2, j2, st2, dir, k;
    while(!q.empty()) {
        int i = q.front().first.first, j = q.front().first.second, st = q.front().second;
        q.pop();
        for(dir=0; dir<4; dir++) {
            i2 = i + di[dir];
            j2 = j + dj[dir];
            if ((i2 >= n || i2 < 0 || j2 >= m || j2 < 0) || (mat[i2][j2] == '#'))
                continue;
            if (mat[i2][j2] >= 'A' && mat[i2][j2] <= 'Z'){
                k = mat[i2][j2] - 'A';
                if ((st & (1 << k))){
                    if (dist[i2][j2].find(st) == dist[i2][j2].end()){
                        dist[i2][j2][st] = dist[i][j][st] + 1;
                        q.push (make_pair(make_pair(i2, i2), st));
                    }
                }
            }
            if (mat[i2][j2] >= 'a' && mat[i2][j2] <= 'z'){
                k = mat[i2][j2] - 'a';
                st2 = (st | (1 << k));
                if ((st & (1 << k))){
                    if (dist[i2][j2].find(st2) == dist[i2][j2].end()){
                        dist[i2][j2][st2] = dist[i][j][st] + 1;
                        q.push (make_pair(make_pair(i2, i2), st2));
                    }
                }
            }
            if (mat[i2][j2] == '.' || mat[i2][j2] == '@'){
                if (dist[i2][j2].find(st) == dist[i2][j2].end()){
                    dist[i2][j2][st] = dist[i][j][st] + 1;
                    q.push (make_pair(make_pair(i2, i2), st));
                }
            }
        }
    }
    sol = INT_MAX;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (dist[i][j].find (cheie[k]) != dist[i][j].end()){
                sol = min (sol, dist[i][j][cheie[k]]);
            }
        }
    }
    return sol;
}

int main() {
    while (getline(fin, s)) {
        mat.push_back(s);
    }
    n = mat.size();
    m = mat[0].size();
    k = 1;
    for (i=1; i<=n/2; i++){
        for (j=1; j<=n/2; j++){
            if (mat[i][j] >= 'a' && mat[i][j] <= 'z'){
                int p = mat[i][j] - 'a';
                f[p] = 1;
                cheie[k] |= (1 << p);
            }
        }
    }
    for (i=1; i<=n/2; i++){
        for (j=1; j<=n/2; j++){
            if (mat[i][j] >= 'A' && mat[i][j] <= 'A'){
                int p = mat[i][j] - 'A';
                if (f[p] == 0){
                    mat[i][j] = '.';
                }
            }
        }
    }
    dist[40][40][0] = 0;
    q.push(make_pair (make_pair(40, 40), 0));
    sol += befese();
    k = 2, f.reset();
    for (i=1; i<=n/2; i++){
        for (j=n/2+1; j<=n; j++){
            if (mat[i][j] >= 'a' && mat[i][j] <= 'z'){
                int p = mat[i][j] - 'a';
                f[p] = 1;
                cheie[k] |= (1 << p);
            }
        }
    }
    for (i=1; i<=n/2; i++){
        for (j=n/2+1; j<=n; j++){
            if (mat[i][j] >= 'A' && mat[i][j] <= 'A'){
                int p = mat[i][j] - 'A';
                if (f[p] == 0){
                    mat[i][j] = '.';
                }
            }
        }
    }
    dist[40][42][0] = 0;
    q.push(make_pair (make_pair(40, 42), 0));
    sol += befese();
    k = 3, f.reset();
    for (i=n/2+1; i<=n; i++){
        for (j=1; j<=n/2; j++){
            if (mat[i][j] >= 'a' && mat[i][j] <= 'z'){
                int p = mat[i][j] - 'a';
                f[p] = 1;
                cheie[k] |= (1 << p);
            }
        }
    }
    for (i=n/2+1; i<=n; i++){
        for (j=1; j<=n/2; j++){
            if (mat[i][j] >= 'A' && mat[i][j] <= 'A'){
                int p = mat[i][j] - 'A';
                if (f[p] == 0){
                    mat[i][j] = '.';
                }
            }
        }
    }
    dist[42][40][0] = 0;
    q.push(make_pair (make_pair(42, 40), 0));
    sol += befese();
    k = 4, f.reset();
    for (i=n/2+1; i<=n; i++){
        for (j=n/2+1; j<=n; j++){
            if (mat[i][j] >= 'a' && mat[i][j] <= 'z'){
                int p = mat[i][j] - 'a';
                f[p] = 1;
                cheie[k] |= (1 << p);
            }
        }
    }
    for (i=n/2+1; i<=n; i++){
        for (j=n/2+1; j<=n; j++){
            if (mat[i][j] >= 'A' && mat[i][j] <= 'A'){
                int p = mat[i][j] - 'A';
                if (f[p] == 0){
                    mat[i][j] = '.';
                }
            }
        }
    }
    dist[42][42][0] = 0;
    q.push(make_pair (make_pair(42, 42), 0));
    sol += befese();
    cout << sol;
}
