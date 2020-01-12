#include <iostream>

using namespace std;

long long x, sum, a;

int main(){
    while (cin >> x){
        a = x;
        while (x > 0){
            sum += x;
            x /= 3;
            x -= 2;
            //cout << x << "\n";
        }
        sum -= a;
    }
    cout << sum;
    return 0;
}
