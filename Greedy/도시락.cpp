#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;

using namespace std;

int C, N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> C;
    while (C--) {
        cin >> N;

        vector<int> M, E;
        priority_queue <pair<int, int>> Food;

        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            M.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            E.push_back(tmp);
        }
        for (int i = 0; i < N; i++) {
            Food.push({ E[i], M[i] });
        }

        int ret = 0, beginEat = 0;
        while (!Food.empty()) {
            beginEat += Food.top().second;
            ret = max(ret, beginEat + Food.top().first);
            Food.pop();
        }

        cout << ret << "\n";
    }
}
