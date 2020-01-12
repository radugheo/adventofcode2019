#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day8.in");
ofstream fout ("day8.out");

char s[20005], layer[20005];

int l, sol, cnt, zero, minim;

int main(){
    fin >> s+1;
    l = strlen(s+1);
    minim = INT_MAX;
    for (int i=1; i<=150; i++){
        layer[i] = '2'; //transparent tot
    }
    for (int i=1; i<=l; i++){
        cnt++;
        if (i%150 == 1){
            cnt = 1;
        }
        if (s[i] == '0' && layer[cnt] == '2') layer[cnt] = '0';
        if (s[i] == '1' && layer[cnt] == '2') layer[cnt] = '1';
    }
    for (int i=1; i<=150; i++){
        if (layer[i] == '0'){
            cout << ".";
        }
        if (layer[i] == '1'){
            cout << "|";
        }
        if (i%25 == 0)
            cout << "\n";
    }
    return 0;
}

