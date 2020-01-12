#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day5.in");
ofstream fout ("day5.out");

int n, i, nr, semn;
int v[100005];

string s[100005];

int *parameter[50];

bitset <100005> pmode;

char c;

inline int solve (string a, int poz){
    int opcode, x, y, z, t, p, n = 0, l;
    l = a.size() - 1;
    if (a.size() >= 2)
        opcode = a[l] - '0' + (a[l-1] - '0')*10;
    else
        opcode = a[0] - '0';
    if (opcode == 0){
        opcode = 5;
    }
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
        *parameter[1] = 5;
        i += 2;
    }
    else if (opcode == 4){
        fout << *parameter[1] << " ";
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
    for (i=0; i<=n;){
        if (v[i] == 99){
            break;
        }
        else{
            if (solve (s[i], i) == -1)
                return 0;
        }
    }
    return 0;
}

