#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day7.in");
ofstream fout ("day7.out");

int n, i, nr, semn, tot, outant, out, all, sol;
int v[100005], cnt[100005], bt[100005], w[100005];
int mat[25][100005];

string s[100005];

deque <int> d[505], o[505];

int *parameter[50];

bitset <100005> pmode;

char c;

inline void copiere (int a[], int b[]){
    int i;
    for (i=0; i<=n; i++){
        a[i] = b[i];
    }
}

int solve (string s, int poz);

int solutie(){
    tot = 0;
    outant = 0;
    out = 0;
    for(all=1; all<=5; all++){
        cnt[all]=0;
        d[all].clear();
        o[all].clear();
        d[all].push_back (bt[all]);
        copiere (mat[all], w);
    }
    d[1].push_back(0);
    bool ok = 0;
    while (!ok){
        for(all=1; all<=5; all++){
            copiere (v, mat[all]);
            for(i=cnt[all]; i<=n;){
                int val = solve (s[i], i);
                if (val == -1){
                    ok = 1;
                    break;
                }
                else if (val == -2){
                   break;
                }
            }
            cnt[all]=i;
            copiere(mat[all],v);
        }
    }
    tot = d[1].front();
    cout << all << endl;
    return tot;
}

void bkt(int pas){
    if(pas > 5){
        int x = solutie();
        sol = max (sol, x);
        return ;
    }
    for(int i=5; i<=9; i++){
        bool ok = 1;
        for(int j=1; j<pas; j++)
            if(bt[j] == i){
                ok = 0;
                break;
            }
        if(ok == 1){
            bt[pas] = i;
            bkt (pas+1);
        }
    }
}

inline int solve (string a, int poz){
    int opcode, x, y, z, t, p, n = 0, l;
    l = a.size() - 1;
    if (a.size() >= 2)
        opcode = a[l] - '0' + (a[l-1] - '0')*10;
    else
        opcode = a[0] - '0';
    pmode.reset();
    l -= 2;
    while (l >= 0){
        pmode[++n] = a[l] - '0';
        l--;
    }
    for (int i=1; i<=4; i++){
        if (pmode[i] == 0){
            parameter[i] = &v[v[poz+i]];
        }
        else{
            parameter[i] = &v[poz+i];
        }
    }
    if (opcode == 99){
        return -1;
    }
    if (opcode == 1){
        *parameter[3] = *parameter[1] + *parameter[2];
        i += 4;
    }
    else if (opcode == 2){
        *parameter[3] = *parameter[1] * *parameter[2];
        i += 4;
    }
    else if (opcode == 3){
        if (d[all].empty()){
            return -2;
        }
        *parameter[1] = d[all].front();
        d[all].pop_front();
        i += 2;
    }
    else if (opcode == 4){
        int next = all + 1;
        if (next == 6) next = 1;
        d[next].push_back(*parameter[1]);
        i += 2;
    }
    else if (opcode == 5){
        if (*parameter[1] == 0){
            i += 3;
        }
        else{
            i = *parameter[2];
        }
    }
    else if (opcode == 6){
        if (*parameter[1] != 0){
            i += 3;
        }
        else{
            i = *parameter[2];
        }
    }
    else if (opcode == 7){
        if (*parameter[1] < *parameter[2]){
            *parameter[3] = 1;
        }
        else{
            *parameter[3] = 0;
        }
        i += 4;
    }
    else if (opcode == 8){
        if (*parameter[1] == *parameter[2]){
            *parameter[3] = 1;
        }
        else{
            *parameter[3] = 0;
        }
        i += 4;
    }
}

int main(){
    n = -1;
    int semn = 1;
    while (fin >> c){
        if (c == ','){
            v[++n] = nr*semn;
            semn = 1;
            nr = 0;
        }
        else if (c >= '0' && c <= '9'){
            s[n+1] += c;
            nr *= 10;
            nr += c - '0';
        }
        else if (c == '-'){
            semn = -1;
        }
    }
    v[++n] = nr;
    copiere (w, v);
    bkt(1);
    fout << sol;
    return 0;
}

