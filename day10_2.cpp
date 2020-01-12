#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define DIM 36

using namespace std;

ifstream fin  ("day10.in");
ofstream fout ("day10.out");

char ch;

double p;

int a[50][50], x, y, t, di, dj, ii, jj, ii2, jj2, g, maxim, xx, yy;
int b[2505][50][50];

pair <double, pair <int, int> > v[5005];

set <pair <int, int > > s, aux;

bool cmp (pair <double, pair <int, int> > &a, pair <double, pair <int, int> > &b){
    return a.first > b.first;
}

int main(){
    for (int i=1; i<=DIM; i++){
        for (int j=1; j<=DIM; j++){
            fin >> ch;
            if (ch == '.') a[i][j] = 0;
            else{
                a[i][j] = 1;
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
                while (!s.empty()){
                    aux.insert ({s.begin()->first, s.begin()->second});
                    s.erase (s.begin());
                }
            }
        }
    }
    while (!aux.empty()){
        xx = aux.begin()->first, yy = aux.begin()->second;
        p = atan2 (xx*1.0, yy*1.0);
        if (p > M_PI_2){
            p -= 2*M_PI;
        }
        v[++t] = {p, {xx, yy}};
        aux.erase (aux.begin());
    }
    sort (v + 1, v + t + 1, cmp);
    ii = x - v[200].second.first;
    jj = x + v[200].second.second;
    while (a[ii][jj] != 1){
        ii -= v[200].second.first;
        jj += v[200].second.second;
    }
    fout << maxim << " " << x << " " << y << "\n";
    fout << jj*100 + ii;
    return 0;
}

