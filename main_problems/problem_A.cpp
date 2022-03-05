/* ----- DESCRIPTION 
To celebrate its success, a new company throws a really big party. Everyone who is someone in town is invited. To help people get to know each other, 
each guest is given a card with a number (a positive integer) upon arrival, and asked to find two other guests in the crowd to form a group of three such that:
there is at least one man and one woman in the group
the sum of the numbers held by the two women (or two men) in the group is equal to the number held by the man (or woman, respectively).
The first group to meet these conditions will win 60.000€, or so say the party organizers...
Since nobody could form such a group until the end of the party, some people demanded that all cards be collected to see whether the game was rigged 
so that the prize would not have to be paid. It is your job to find out whether, given the numbers handed out at the party, 
it was possible to win the game and claim the prize.
*/

/* ----- INPUT 
For each test case, the number of guests, n, is given in the first line, and each guest's number is given in the next n lines. 
To distinguish between men and women at the party, men's numbers were recorded as negative numbers, whereas women's numbers were recorded as positive. 
The end of the test case is indicated by a line containing "0". A new test case may then follow.
*/

/* ----- OUTPUT 
The output for each test case consists of a single line saying "Fair" if the game was fair and a winning group could indeed be found. 
Otherwise, the output must be "Rigged".
*/

#include <bits/stdc++.h>

using namespace std;

int three_sum(vector<int> S)
{
    sort(S.begin(), S.end());
    int sum, k, j;
    int n = S.size();
    for (int i = 1; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)0
        {
            sum = S[i] + S[j] + S[k];
            if (sum == 0){
                cout << "Fair\n";
                return 0;
            }
            else if (sum > 0)
                k = k - 1;
            else
                j = j + 1;
        }
    }
    cout << "Rigged\n";
    return 1;
}

int main()
{

    int n;
    vector<int> S;
    cin >> n;

    while (cin >> n)
    {
        
        if (n == 0)
        {
            cin >> n;
            three_sum(S);
            S = {};
            continue;
        }
        
        S.push_back(n);
    }
    return 0;
}