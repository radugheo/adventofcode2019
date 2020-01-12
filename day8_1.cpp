#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day8.in");
ofstream fout ("day8.out");

char s[20005];

int l, sol, unu, doi, zero, minim;

int main(){
    fin >> s+1;
    l = strlen(s+1);
    minim = INT_MAX;
    for (int i=1; i<=l; i++){
        if (i%150 == 1){
            zero = unu = doi = 0;
        }
        if (s[i] == '0') zero++;
        if (s[i] == '1') unu++;
        if (s[i] == '2') doi++;
        if (i%150 == 0){
            if (zero < minim){
                minim = zero;
                sol = unu*doi;
            }
        }
    }
    cout << sol;
    return 0;
}
