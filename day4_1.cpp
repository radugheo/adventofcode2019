#include <iostream>

using namespace std;

int sol;

bool checkCrescendo (int a){
    int cif[7] = {0, 0, 0, 0, 0, 0, 0}, nr = 0;
    while (a){
        cif[++nr] = a%10;
        a /= 10;
    }
    for (int i=1; i<nr; i++){
        if (cif[i] < cif[i+1]){
            return false;
        }
    }
    return true;
}

bool checkDouble (int a){
    int cif[7] = {0, 0, 0, 0, 0, 0, 0}, nr = 0, cnt = 0;
    while (a){
        cif[++nr] = a%10;
        a /= 10;
    }
    for (int i=1; i<nr; i++){
        if (cif[i] != cif[i+1]){
            cnt++;
        }
    }
    if (cnt == nr - 1){
        return false;
    }
    return true;
}

int main(){
    for (int i=359282; i<=820401; i++){
        if (checkDouble(i) && checkCrescendo(i)){
            sol++;
        }
    }
    cout << sol;
    return 0;
}
