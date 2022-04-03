#include <bits/stdc++.h>
#include <iterator>

using namespace std;

vector<int> pizzas;
vector <vector<bool>> DP;
int n;
int T;

int pizza()
{
    for (int i = 0; i <= n; i++)
    {
        DP[i].push_back(true);
    }

    for (int j = 1; j <= T; j++)
    {
        DP[0].push_back(false);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            
            if (pizzas[i - 1] > j) DP[i].push_back(DP[i-1][j]); 
            else DP[i].push_back(DP[i - 1][j] || DP[i - 1][j - pizzas[i - 1]]);
            //if(DP[i][j]) cout  << j << endl;
        }
    }

    for (int j = T; j >= 0; j--)
    {
        //cout << "j: " << j << endl;
        if (DP[n][j] == true)
            return j;
    }

    return -1;
}

int main()
{


    while (cin >> n)
        {
            int time;
            T = 0;
            pizzas = vector<int>();
            DP = vector<vector<bool>>(n+1);

            for (int i = 0; i < n; i++)
            {
                cin >> time;
                pizzas.push_back(time);
                T += time;
            }

            int sum_T = T;
            T = T / 2;
            //cout << "T: " << T << endl;
            //cout << "Sum_t " << sum_T << endl;
            int best = pizza();
            int diff = abs(best - (sum_T - best));
            cout << diff << endl;
        }
}