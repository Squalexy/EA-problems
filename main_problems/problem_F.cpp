#include <bits/stdc++.h>

using namespace std;

int n_test_cases;
int N;
int M;
int position;
vector<int> guards;
vector<int> objects;



int guards_func(){
    int i = 0;
    guards.push_back(objects[0] + M);

    for (int j = 1; j <= N; j++){
        if (objects[j] > guards[i] + M){
            guards.push_back(objects[j] + M);
            i++;
        }
    }

    return guards.size();
}

int main(){

    cin >> n_test_cases;

    for (int j = 0; j < n_test_cases; j++){

        objects = vector<int>();
        guards = vector<int>();
        cin >> N >> M;

        for (int i = 0; i < N; i++){
            cin >> position;
            objects.push_back(position);
        }

        sort(objects.begin(), objects.end());
        cout << guards_func() << endl;
    }
}