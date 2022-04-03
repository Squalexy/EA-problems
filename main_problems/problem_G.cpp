#include <bits/stdc++.h>

using namespace std;

int best, UB, n, m;
int neighbor_a;
int neighbor_b;
map<pair<int,int>,int> neighbors_connected;
vector<int> neighbors;

void MIS(int v, int size){

    if (size > best) best = size;

    if(v==n) return;

    UB = 0;
    for (int i = v + 1; i < n; i++){
        if (neighbors[i] == 0) UB++;
    }
    
    if (size + UB <= best) return;

    for (int i = v + 1; i < n; i++){
        if (neighbors[i] == 0) UB++;
    }

    for (int i = v + 1; i < n; i++){
        if(neighbors_connected[{i, v}] == 1) neighbors[i] ++;
    }

    for(int i=v+1; i<n; i++){
        if(neighbors[i]==0){
            MIS(i, size+1);
        }
    }

    for(int i=v+1; i<n; i++){
        if(neighbors_connected[{v,i}]==1){
            neighbors[i]--;
        }
    }
}

int main(){

    cin >> n >> m;
    neighbors = vector<int>(n, 0);
    for (int i = 0; i < m; i++){
        cin >> neighbor_a >> neighbor_b;
        neighbors_connected[{neighbor_a, neighbor_b}] = 1;
        neighbors_connected[{neighbor_b, neighbor_a}] = 1;
    }

    for (int i = 0; i < n; i++){
        MIS(i, 1);
    }
       
    cout << best << endl;
    return 0;

}