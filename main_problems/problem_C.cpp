#include <bits/stdc++.h>

using namespace std;

// n -> network nodes
// m -> number of feasible point-to-point links
// k -> maximum number of feasible point-to-point links
int n, m, k;
int best;
int n_ligacoes[12 + 1];
int cost[12 + 1][12 + 1];
bool visited[12 + 1];

void net(int v, int c){

    if (c >= best) return;

    if (v == n - 1){
        best = c;
        return;
    }

    // procurar nó que já esteja na rede
    for (int i = 0; i < n; i++){
        if (visited[i] == true)
        {
            for (int j = 0; j < n; j++)
            {
                // se tiver custo = 0 não há ligação possível entre os nós
                if (visited[j] == false && cost[i][j] > 0 && n_ligacoes[i] < k)
                {
                    // vou ligar os nós
                    n_ligacoes[i] += 1;
                    n_ligacoes[j] += 1;
                    visited[j] = true;
                    net(v + 1, c + cost[i][j]);
                    visited[j] = false;
                    n_ligacoes[i] -= 1;
                    n_ligacoes[j] -= 1;
                }
            }
        }
    }
}

int main(){
    while (cin >> n >> m >> k){
  
        // nº ligações para cada nó
        for (int i = 0; i < n; i++){
            n_ligacoes[i] = 0;
            visited[i] = 0;
        }

        // custo de CADA par de nós
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cost[i][j] = 0;
            }
        }
        
        /*
        vector <int> n_ligacoes(n, 0);
        vector <vector<int>> cost(n, vector<int>(n, 0));
        */

        int i, j, c;                    // i, j = par de nós; c = custo desse par de nós

        for (int a = 0; a < m; a++)
        {
            cin >> i >> j >> c;
            cost[i - 1][j - 1] = c;
            cost[j - 1][i - 1] = c;
        }
        
        best = 100000;                   // nº suficientemente grande
        visited[0] = true;
        net(0, 0);
        

        if (best == 100000) cout << "NO WAY!" << endl;
        else cout << best << endl;
    }
}