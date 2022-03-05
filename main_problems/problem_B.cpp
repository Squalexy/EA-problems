#include <bits/stdc++.h>

using namespace std;

int board [401][401];

int chess (int x, int y, int m){
    int v = 0;
    if (board [x+200][y+200] == 0){
        board[x+200][y+200] = 1;
        v = 1;
    }
    
    if (m>0){
        v = v + chess(x+2, y+1, m-1) + chess(x+1, y+2, m-1) + chess(x-1, y+2, m-1) + chess(x-2, y+1, m-1)
        + chess(x-1, y-2, m-1) + chess(x-2, y-1, m-1) + chess(x+1, y-2, m-1) + chess(x+2, y-1, m-1);
    }

    return v;
}

int main(){
    int n, x, y, m;
    cin >> n;
    int n_moves = 0;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> m;
        n_moves += chess(x, y, m);
    }
    cout << n_moves << endl;
}