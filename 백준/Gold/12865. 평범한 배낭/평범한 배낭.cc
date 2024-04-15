#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <numeric>

using namespace std;


int weight[101]{ 0 };
int value[101]{ 0 };
int dp[101][100001]{ 0 };









int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    int cass, max_weight;
    cin >> cass >> max_weight;

    for (int a = 1; a <= cass; a++)
    {
        int w, v;
        cin >> w >> v;
        value[a] = v;
        weight[a] = w;

    }







    for (int a = 1; a <= max_weight;a++)
    {

        for (int b = 1; b <= cass; b++)
        {

            if (weight[b] > a)//만약 b번째 물건의 무게가 a보다 크다면(가방에 담을수 없다면)
            {
                dp[b][a] = dp[b-1][a];//b번째 물건의 a까지 무게의 최대 가치는 b보다 가벼운 물건의 가치
            }

            else
            {
                dp[b][a] = max(dp[b-1][a - weight[b]] + value[b],dp[b-1][a]);

            }

        }


    }
    cout << dp[cass][max_weight];


}