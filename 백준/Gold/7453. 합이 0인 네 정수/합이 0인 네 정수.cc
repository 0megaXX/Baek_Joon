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
#include <stack>
#include <cstring> 
#include <deque>
#include <set>
#include <unordered_set>

#define MAXX 987654321
using namespace std;

vector<vector<int>>arr(4, vector<int>(4000));
vector<int>AB;
vector<int>CD;
  int cass;
  long long rs = 0;

void fn()
{
    for (int a = 0; a < cass; a++)
        for (int b = 0; b < cass; b++)
        {
            AB.push_back(arr[0][a] + arr[1][b]);
            CD.push_back(arr[2][a] + arr[3][b]);
        }

    

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int AB_idx = 0;
    int CD_idx = CD.size()-1;

    while (AB_idx < AB.size() && CD_idx>=0) // 한쪽의 탐색이 끝나면 종료
    {

        if (AB[AB_idx] + CD[CD_idx] == 0)//두 합이 0이라면
        {

            int ori = AB_idx;
            long long cur_AB_val = 0, cur_CD_val = 0;

            while (AB[AB_idx] + CD[CD_idx] == 0) // AB배열에서 현재 값과 같은값의 수 리턴
            {

                if (AB_idx >= AB.size()) // 아웃오브레인지 방지
                    break;

                cur_AB_val++;
                AB_idx++;

            }

            while (AB[ori] + CD[CD_idx] == 0) // CD배열에서 현재 값과 같은값의 수 리턴
            {

                if (CD_idx < 0) // 아웃오브레인지 방지
                    break;

                cur_CD_val++;
                CD_idx--;

            }

            rs = rs + (cur_AB_val * cur_CD_val);


        }
        else if (AB[AB_idx] + CD[CD_idx] > 0) // 합이 0보다 크다면 값을 낮춰야함
            CD_idx--;
        else // 합이 0 보다 작다면 값을 올려야함
            AB_idx++;



    }

    cout << rs;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    cin >> cass;

    for (int a = 0; a < cass; a++)
        for (int b = 0; b < 4; b++)
            cin >> arr[b][a];

    fn();
}
