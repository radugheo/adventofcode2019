#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day6.in");
ofstream fout ("day6.out");

int n, i, sol;
int s[5005];

char ch[5005];

string a, b;

bitset <100005> f;

map <string, int> mep;

vector <int> L[100005];

void dfs (int nod, int tata){
    int vecin, i;
    s[nod] = s[tata] + 1;
    sol += s[nod];
    for (i=0; i<L[nod].size(); i++){
        vecin = L[nod][i];
        if (vecin != tata){
            dfs (vecin, nod);
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
        f[mep[b]] = 1;
    }
    s[0] = -1;
    for (i=1; i<=n; i++){
        if (f[i] == 0){
            dfs (i, 0);
        }
    }
    fout << sol;
    return 0;
}
//merci Mircea pentru map
