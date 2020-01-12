#include <bits/stdc++.h>
#define x first
#define y second.first
#define z second.second

using namespace std;

long long s1, s2, sol, i, j, k, cnt;

pair <long long, pair <long long, long long> > a[5], b[5], a2[5];

map <pair <long long, pair <long long, long long> >, int> mep[5];

int main(){
    a[1] = {9, {13, -8}};
    a[2] = {-3, {16, -17}};
    a[3] = {-4, {11, -10}};
    a[4] = {0, {-2, -2}};
    mep[1][{a[1].x, {a[1].y, a[1].z}}] = 1;
    mep[2][{a[2].x, {a[2].y, a[2].z}}] = 1;
    mep[3][{a[3].x, {a[3].y, a[3].z}}] = 1;
    mep[4][{a[4].x, {a[4].y, a[4].z}}] = 1;
    for(i=1; ;i++){
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
        cnt = 0;
        for (j=1; j<=4; j++){
            if (mep[j][{a[i].x, {a[i].y, a[i].z}}] == 1){
                cnt++;
            }
        }
        if (cnt == 4){
            cout << i;
            return 0;
        }
        else{
            for (j=1; j<=4; j++){
                mep[j][{a[i].x, {a[i].y, a[i].z}}] == 1;
            }
        }
    }
    return 0;
}

