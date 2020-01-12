#include <iostream>

using namespace std;

long long x, sum;

int main(){
    while (cin >> x){
        x /= 3;
        x -= 2;
        sum += x;
    }
    cout << sum;
    return 0;
}

