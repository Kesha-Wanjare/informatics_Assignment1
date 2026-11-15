#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;
 
int main(){
    int n;
    cin >> n;
    ll x;
    cin >> x;
    if(n <= 2){
        cout << "IMPOSSIBLE" << '\n';
    }else{
        vll v(n);
        vll help(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }help = v;
        bool there = false;
        sort(v.begin(), v.end());
        int index;
        int start;
        int finish;
        for(int j = 2; j < n; j++){
            if(there){
                break;
            }else{
                ll temp = x - v[j];
                int begi = 0, en = j-1;
                while(begi != en){
                    if(v[en] + v[begi] == temp){
                        index = j;
                        there = true;
                        start = begi;
                        finish = en;
                        break;
                    }else if(v[en] + v[begi] > temp){
                        en -= 1;
                    }else{
                        begi += 1;
                    }
                }
            }
        }if(there){
            int no_back;
            int no_mid;
            for(int a = 0; a < n; a++){
                if (help[a] == v[start]){
                    cout << a + 1 << " ";
                    no_back = a;
                    break;
                }
            }for(int b = 0; b < n; b++){
                if(help[b] == v[finish] && b != no_back){
                    no_mid = b;
                    cout << b + 1 << " ";
                    break;
                }
            }for(int c = 0; c < n; c++){
                if(help[c] == v[index] && c != no_back && c != no_mid){
                    cout << c + 1 << " ";
                    break;
                }
            }
        }else{
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    
}
