#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int C, H, W;

//L을 90도씩 돌려서 4개의 블록을 만들 수 있다.
const int converType[4][3][2] = {
    {{0,0}, {1,0}, {0,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {1,0}, {1,-1}}
};

//Board에 L 블록으로 만들 수 있는 모양을 대입한 뒤, 경계를 벗어나거나 블록이 겹쳐지는 부분이 있는지 판단
bool covered(int board[][20], int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        const int dy = y + converType[type][i][0];
        const int dx = x + converType[type][i][1];

        if (dy < 0 || dx < 0 || H <= dy || W <= dx) 
            ok = false;
        else if ((board[dy][dx] += delta) > 1)
            ok = false;
    }
    return ok;
}

int cover(int board[][20]) {
    int y = -1, x = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0) {
                y = i; x = j;
                break;
            }
        }
        if (y != -1) break;
    }

    if (y == -1) return 1;

    //재귀 함수를 이용해 L 블록을 돌려서 놓을 수 있는 경우를 찾음
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        if (covered(board, y, x, type, 1))
            ret += cover(board);
        covered(board, y, x, type, -1);
    }
    return ret;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> C;
    while (C--) {
        cin >> H >> W;

        string boards[20];
        for (int i = 0; i < H; i++) {
            cin >> boards[i];
        }

        int board[20][20];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (boards[i][j] == '#') board[i][j] = 1;
                else board[i][j] = 0;
            }
        }

        cout << cover(board) << "\n";
    }
}
