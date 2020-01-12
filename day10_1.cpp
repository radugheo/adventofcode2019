#include <bits/stdc++.h>
#define DIM 36

using namespace std;

ifstream fin  ("day10.in");
ofstream fout ("day10.out");

char ch;

int a[50][50], x, y, t, di, dj, ii, jj, ii2, jj2, g, maxim;
int b[2505][50][50];

pair <int, int> v[2505];

int main(){
    for (int i=1; i<=DIM; i++){
        for (int j=1; j<=DIM; j++){
            fin >> ch;
            if (ch == '.') a[i][j] = 0;
            else{
                a[i][j] = 1;
                v[++t] = {i, j};
            }
        }
    }
    for (int i=1; i<=DIM; i++){
        for (int j=1; j<=DIM; j++){
            if (a[i][j] == 0){
                continue;
            }
            set <pair <int, int > > s;
            for (ii=1; ii<=DIM; ii++){
                for (jj=1; jj<=DIM; jj++){
                    if (a[ii][jj] == 1 && (ii != i || jj != j)){
                        di = ii - i, dj = jj - j;
                        g = __gcd(di, dj);
                        if (g < 0) g = g*(-1);
                        s.insert ({-di/g, dj/g});
                    }
                }
            }
            if (s.size() > maxim){
                maxim = s.size();
                x = i, y = j;
            }
        }
    }
    fout << maxim << " " << x << " " << y;
    return 0;
}
