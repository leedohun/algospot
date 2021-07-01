#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int C;
vector<int> h;

int solve(int left, int right) {
    if (left == right) return h[left];

    int mid = (left + right) / 2;
    
    int ret = max(solve(left, mid), solve(mid + 1, right));

    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);

    ret = max(ret, height * 2);

    while (left < lo || hi < right) {
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            hi++;
            height = min(height, h[hi]);
        }
        else {
            lo--;
            height = min(height, h[lo]);
        }
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> C;
    while (C--) {
        h.clear();

        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            int temp; cin >> temp;
            h.push_back(temp);
        }

        cout << solve(0, N - 1) << "\n";
    }
}
