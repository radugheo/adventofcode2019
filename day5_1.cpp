#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day5.in");
ofstream fout ("day5.out");

int a, n, i, x;
int v[100005];

int *parameter[50];

bitset <100005> pmode;

char c;

inline int solve (int a, int poz){
    int opcode, x, y, z, t, p, n = 0;
    opcode = a%100;
    if (opcode == 0){
        cin >> opcode;
    }
    a /= 100;
    pmode.reset();
    while (a){
        pmode[++n] = a%10;
        a /= 10;
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
        cin >> *parameter[1];
        i += 2;
    }
    else if (opcode == 4){
        cout << *parameter[1] << " ";
        i += 2;
    }
    else{
        cout << opcode << " ";
    }
}

int main(){
    n = 0;
    while (fin >> a >> c){
        v[n++] = a;
    }
    i = 0;
    while(1){
        if (v[i] == 1){
            v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
            i += 4;
        }
        else if (v[i] == 2){
            v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
            i += 4;
        }
        else if (v[i] == 3){
            cin >> v[v[i+1]];
            i += 2;
        }
        else if (v[i] == 4){
            cout << v[v[i+1]] << " ";
            i += 2;
        }
        else if (v[i] == 99){
            break;
        }
        else{
            if (solve (v[i], i) == -1)
                return 0;
        }
    }
    return 0;
}
