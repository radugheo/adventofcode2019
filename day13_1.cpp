#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("day13.in");
ofstream fout ("day13.out");

long long n, nr, i, semn, baza, viz, sol;
long long v[100000], pmode[50];
long long *parameter[10];

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

int xx, yy, dir, dir2;

map <pair<long long, long long>, long long> bl;

deque <int> in;

string s[100000];

char c;

long long solve(string a, long long poz){
    long long l, cod, n = 0;
    l = a.size() - 1;
    if(a.size() >= 2)
        cod = a[l] - '0' + (a[l-1] - '0')*10;
    else
        cod = a[0] - '0';
    if(cod == 0)
        cin >> cod;
    for(int i=0; i<=10; i++)
        pmode[i] = 0;
    l -= 2;
    while(l >= 0){
        pmode[++n] = a[l] - '0';
        l--;
    }
    for(long long i=1; i<=4; i++){
        if(pmode[i] == 0){
            parameter[i] = &v[v[poz+i]];
        }
        else if(pmode[i] == 1){
            parameter[i] = &v[poz+i];
        }
        else {
            parameter[i] = &v[v[poz+i]+baza];
        }
    }
    if(cod == 99){
        return -1;
    }
    if(cod == 1){
        *parameter[3] = *parameter[1] + *parameter[2];
        i += 4;
    }
    else if(cod == 2){
        *parameter[3] = *parameter[1] * *parameter[2];
        i += 4;
    }
    else if(cod == 3){
        cin >> *parameter[1];
        i += 2;
    }
    else if(cod == 4){
        in.push_back(*parameter[1]);
        i += 2;
        int x, y;
        if (in.size() % 3){
            return 0;
        }
        x = in.front();
        in.pop_front();
        y = in.front();
        in.pop_front();
        if (in.front() == 2){
            sol++;
        }
        else if (in.front() > 4){
            cout << in.front();
        }
        in.pop_front();
    }
    else if(cod == 5){
        if(*parameter[1] == 0){
           i += 3;
        }
        else{
            i = *parameter[2];
        }
    }
    else if(cod == 6){
        if(*parameter[1] != 0){
           i += 3;
        }
        else{
            i = *parameter[2];
        }
    }
    else if(cod == 7){
        if(*parameter[1] < *parameter[2]){
            *parameter[3] = 1;
        }
        else{
            *parameter[3] = 0;
        }
        i += 4;
    }
    else if(cod == 8){
        if(*parameter[1] == *parameter[2]){
            *parameter[3] = 1;
        }
        else{
            *parameter[3] = 0;
        }
        i += 4;
    }
    else if(cod == 9){
        baza += *parameter[1];
        i += 2;
    }
}
int main(){
    semn = 1;
    n = -1;
    while(fin >> c){
        if(c == ','){
            v[++n] = nr*semn;
            semn = 1;
            nr = 0;
        }
        else if(c >= '0' && c <= '9'){
            s[n+1] += c;
            nr *= 10LL;
            nr += c - '0';
        }
        else if(c == '-'){
            semn =- 1;
        }
    }
    v[++n] = nr;
    for(i=0; i<=n;){
        if(solve(s[i], i) == -1)
            break;
    }
    cout << sol;
}
