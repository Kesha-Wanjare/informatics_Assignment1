#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
using vll = vector<ll>;

void GenerateVal(vll& v, ll& m, ll&a, ll&b, ll&c){
    m = a*m;
    m += b;
    m = m%c;
    v.push_back(m);
}

int main(){
    ll n, k, x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    vll v = {x};
    for(ll i = 0; i < n; i++){
        GenerateVal(v, x, a, b, c);
    }ll sum = 0;
    vll results;
    for(ll y = 0; y < k; y++){
        sum += v[y];
    }results.push_back(sum);
    for (ll z = k; z < n; z++){
        sum += v[z] - v[z-k];
        results.push_back(sum);
    }
    ll um =  results[0];
    for (int g = 1; g < results.size(); g++){
        um ^=results[g];
    }cout << um << '\n';
}