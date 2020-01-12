#include <iostream>

using namespace std;

int a, n, i;
int v[1005];

char c;

int main(){
    while (cin >> a >> c){
        v[n++] = a;
    }
    v[1] = 12, v[2] = 2;
    i = 0;
    while (1){
        if (v[i] == 1){
            v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
        }
        else if (v[i] == 2){
            v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
        }
        else if (v[i] == 99){
            break;
        }
        i += 4;
    }
    cout << v[0];
    return 0;
}
