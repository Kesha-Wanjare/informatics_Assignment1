#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    int n, k;
    cin >> n >> k;
 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    map<int, int> counts; 
    int left = 0;
    int best_left = 0, best_right = 0;
    int max_len = 0;
 
    for (int right = 0; right < n; right++) {
        counts[v[right]] += 1;
 
        while (counts.size() > k) {
            counts[v[left]] -= 1;
            if (counts[v[left]] == 0) {
                counts.erase(v[left]);
            }
            left++;
        }
 
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
            best_left = left;
            best_right = right;
        }
    }
 
    cout << best_left + 1 << " " << best_right + 1 << "\n";
 
    return 0;
}
