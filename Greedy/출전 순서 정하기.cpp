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

        vector <int> korea, russia;

        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            russia.push_back(tmp);
        }

        for (int i = 0; i < N; i++) {
            int tmp; cin >> tmp;
            korea.push_back(tmp);
        }

        sort(russia.begin(), russia.end());
        sort(korea.begin(), korea.end());

        int cnt = 0;
        int i = 0, j = 0;
        while (j < N) {
            if (russia[i] <= korea[j]) {
                i++; j++; cnt++;
            }
            else
                j++;
        }
        
        cout << cnt << "\n";
    }
}
