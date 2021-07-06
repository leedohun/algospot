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

        priority_queue <int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            pq.push(tmp);
        }

        int ret = 0;
        while (pq.size() != 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            ret += a + b;

            pq.push(a + b);
        }

        cout << ret << "\n";
    }
}
