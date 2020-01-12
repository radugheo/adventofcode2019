#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day16.in");

const int d[] = {1, 0, -1, 0};

int n;
int v[10000005], a[10000005];

char s[10000005];

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
    char c;
    while (fin >> c){
        v[n++] = c - '0';
    }
    n--;
    long long ex = 0;
    for(int i=0; i<7; i++)
        ex = ex*10 + v[i];
    cout << ex << "\n";
    int lungime = n;
    for(int rep=1; rep<=9999; rep++)
    for(int i=0; i<=lungime; i++)
        v[++n] = v[i];
    for(int phase=1; phase<=100; phase++){
        int sum = 0;
        for(int i=n; i>=n/2-2; i--){
            sum += v[i];
            v[i] = sum%10;
        }
    }
    for(int i=5970807; i<=5970807+7; i++){
        cout<<v[i];
    }
    return 0;
}

