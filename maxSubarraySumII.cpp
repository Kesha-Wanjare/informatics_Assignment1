#include <bits/stdc++.h>
using namespace std;
 
using vll = vector<long long>;
using qll = queue<long long>;
 
int main() {
    int n, minLength, maxLength;
    cin >> n >> minLength >> maxLength;
 
    vector<long long> arrayValues(n + 1);
    for (int index = 1; index <= n; index++) {
        cin >> arrayValues[index];
    }
 
    vector<long long> prefixSums(n + 1, 0);
    for (int index = 1; index <= n; index++) {
        prefixSums[index] = prefixSums[index - 1] + arrayValues[index];
    }
 
    deque<int> window;
 
    long long bestSum = prefixSums[minLength];
 
    for (int endIndex = minLength; endIndex <= n; endIndex++) {
 
        int newIndex = endIndex - minLength;
 
        while (!window.empty() && prefixSums[window.back()] >= prefixSums[newIndex]) {
            window.pop_back();
        }
        window.push_back(newIndex);
 
        int oldestAllowed = endIndex - maxLength;
        while (!window.empty() && window.front() < oldestAllowed) {
            window.pop_front();
        }
 
        long long currentBest = prefixSums[endIndex] - prefixSums[window.front()];
        bestSum = max(bestSum, currentBest);
    }
 
    cout << bestSum << "\n";
    return 0;
}
   
