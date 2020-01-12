#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day16.in");

const int d[] = {1, 0, -1, 0};

int n;
int v[10005], a[10005];

char s[10005];

int solve (int st, int l){
    int poz = 0, sum = 0;
    for (int i=st; i<=n; i+=l){
        for (int j=i; j<i+l; j++){
            sum += v[j]*d[poz%4];
        }
        poz++;
    }
    return abs(sum)%10;
}

int main(){
    fin >> s;
    for (int i=0; i<strlen(s); i++){
        v[n++] = s[i] - '0';
    }
    n--;
    for (int i=1; i<=100; i++){
        for (int j=0; j<=n; j++){
            a[j] = solve (j, j + 1);
        }
        for (int j=0; j<=n; j++){
            v[j] = a[j];
        }
    }
    for (int i=0; i<=7; i++){
        cout << v[i];
    }
    return 0;
}
