#include <iostream>

using namespace std;

int a, n, i, noun, m, verb;
int v[1005], bck[1005];

char c;

int main(){
    while (cin >> a >> c){
        v[n++] = a;
        bck[m++] = a;
    }
    for (noun=0; noun<99; noun++){
        for (verb=0; verb<99; verb++){
            v[1] = noun, v[2] = verb;
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
            if (v[0] == 19690720){
                cout << 100*noun + verb;
                return 0;
            }
            for (i=0; i<n; i++){
                v[i] = bck[i];
            }
        }
    }
    return 0;
}

