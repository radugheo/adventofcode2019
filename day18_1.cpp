#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day18.in");

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m, starti, startj, i, j;

map <int, int> dist[1005][1005];

pair <int, int> sol;

vector <string> mat;

string s;

queue <pair <pair <int, int>, int> > q;

int befese (int x, int y) {
    int i2, j2, st2, dir, k;
    q.push ({{x, y}, 0});
    dist[x][y][0] = 0;
    while(!q.empty()) {
        int i = q.front().first.first, j = q.front().first.second, st = q.front().second;
        q.pop();
        for(dir=0; dir<4; dir++) {
            i2 = i + di[dir];
            j2 = j + dj[dir];
            if ((i2 >= n || i2 < 0 || j2 >= m || j2 < 0) || (mat[i2][j2] == '#'))
                continue;
            k = mat[i2][j2] - 'A';
            if(k >= 0 && k <= 26) {
                if ((st & (1 << k)) == 0){
                    continue;
                }
            }
            st2 = st;
            k = mat[i2][j2] - 'a';
            if(k >= 0 && k <= 26)
                st2 |= (1 << k);
            if (dist[i2][j2].count(st2))
                continue;
            dist[i2][j2][st2] = dist[i][j][st] + 1;
            sol = min (sol, make_pair(-st2, dist[i2][j2][st2]));
            q.push(make_pair(make_pair(i2, j2), st2));
        }
    }
    return sol.second;
}

int main() {
    while (getline(fin, s)) {
        mat.push_back(s);
    }
    n = mat.size();
    m = mat[0].size();
    for(i=0; i<n; i++){
        for(j=0; j<m; j++) {
            if(mat[i][j] == '@'){
                starti = i, startj = j;
                cout << befese(starti, startj);
                return 0;
            }
        }
    }
}
