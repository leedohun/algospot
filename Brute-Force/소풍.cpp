#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int C, n, m;
bool areFriend[10][10] = { false, };

int countPairings(bool taken[10]) {
    //번호가 빠른 순서대로 친구를 매핑 시켜줍니다.
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;

    int ret = 0;

    //firstFree와 짝을 지어줄 친구를 firstFree보다 뒷번호에서 찾아줍니다.(중복으로 세는 문제를 피함.)
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        if (!taken[pairWith] && areFriend[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> C;
    while (C--) {
        //변수 초기화
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                areFriend[i][j] = false;
            }
        }

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            areFriend[a][b] = 1; areFriend[b][a] = 1;
        }

        bool taken[10] = { false, };
        cout << countPairings(taken) << "\n";
    }
}
