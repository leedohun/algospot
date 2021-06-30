#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int C;

string reverse(string::iterator& it) {
    char head = *it;
    ++it;

    if (head == 'b' || head == 'w')
        return string(1, head); //char to string

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> C;
    while (C--) {
        string S; cin >> S;

        string::iterator iter = S.begin();
        cout << reverse(iter) << "\n";
    }
}
