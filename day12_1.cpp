#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second

using namespace std;

int s1, s2, sol, i, j, k;
pair <int, pair <int, int> > a[5], b[5];

int main(){
    a[1] = {9, {13, -8}};
    a[2] = {-3, {16, -17}};
    a[3] = {-4, {11, -10}};
    a[4] = {0, {-2, -2}};
    for(i=1; i<=1000; i++){
        for(j=1; j<=4; j++){
            for(k=1; k<=4; k++){
                if(j == k)
                    continue;
                if(a[j].x < a[k].x){
                    b[j].x++;
                }
                else if(a[j].x > a[k].x){
                    b[j].x--;
                }
                if(a[j].y < a[k].y){
                    b[j].y++;
                }
                else if(a[j].y > a[k].y){
                    b[j].y--;
                }
                if(a[j].z < a[k].z){
                    b[j].z++;
                }
                else if(a[j].z > a[k].z){
                    b[j].z--;
                }
            }
        }
        for(j=1; j<=4; j++){
            a[j].x += b[j].x;
            a[j].y += b[j].y;
            a[j].z += b[j].z;
        }
    }
    for(j=1; j<=4; j++){
        s1 = abs (a[j].x) + abs (a[j].y) + abs (a[j].z);
        s2 = abs (b[j].x) + abs (b[j].y) + abs (b[j].z);
        sol += s1*s2;
    }
    cout << sol;
    return 0;
}
