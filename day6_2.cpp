#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day6.in");
ofstream fout ("day6.out");

int n, i, sol, st, fn;
int s[5005];

char ch[5005];

string a, b;

bitset <100005> f;

map <string, int> mep;

vector <int> L[100005];

void dfs (int nod){
    int vecin, i;
    f[nod] = 1;
    for (i=0; i<L[nod].size(); i++){
        vecin = L[nod][i];
        if (f[vecin] == 0){
            s[vecin] = s[nod] + 1;
            if (vecin == fn){
                sol = s[vecin];
                return ;
            }
            dfs (vecin);
        }
    }
}

int main(){
    while (fin >> ch){
        a.clear();
        b.clear();
        a += ch[0], a += ch[1], a += ch[2];
        b += ch[4], b += ch[5], b += ch[6];
        if (mep[a] == 0) mep[a] = ++n;
        if (mep[b] == 0) mep[b] = ++n;
        L[mep[a]].push_back (mep[b]);
        L[mep[b]].push_back (mep[a]);
        if (b[0] == 'Y' && b[1] == 'O' && b[2] == 'U'){
            st = mep[b];
        }
        if (b[0] == 'S' && b[1] == 'A' && b[2] == 'N'){
            fn = mep[a];
        }
    }
    s[0] = -1;
    dfs (st);
    fout << sol - 1;
    return 0;
}

