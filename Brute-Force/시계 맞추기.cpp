#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int INF = 987654321;

int C;

const string clockSwitch[10] = { //어떤 스위치가 시계랑 연결되었는지 표현
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

//모두 12시 인지 판단
bool areAligned(int clocks[]) {
    bool ok = true;
    for (int i = 0; i < 16; i++) {
        if (clocks[i] != 12)
            ok = false;
    }
    return ok;
}

//switch push
void push(int clocks[], int swtch) {
    for (int clock = 0; clock < 16; clock++) {
        if (clockSwitch[swtch][clock] == 'x') {
            clocks[clock] += 3;
            if (clocks[clock] == 15)
                clocks[clock] = 3;
        }
    }
}

int solved(int clocks[], int swtch) {
    if (swtch == 10)
        return areAligned(clocks) ? 0 : INF;

    int ret = INF;
    for (int cnt = 0; cnt < 4; cnt++) {
        ret = min(ret, cnt + solved(clocks, swtch + 1));
        push(clocks, swtch);
    }
    return ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> C;
    while (C--) {
        int clocks[16] = { 0, };

        for (int i = 0; i < 16; i++) {
            cin >> clocks[i];
        }

        int ret = solved(clocks, 0);
        if (ret < 10000)
            cout << ret << "\n";
        else
            cout << -1 << "\n";
    }
}
