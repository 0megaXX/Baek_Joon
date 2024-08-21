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

vector<int>v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    int cass;
    cin >> cass;
    while (cass--)
    {

        
        int sizz, target;
        cin >> sizz >> target;
        v.resize(sizz);
        for (int a = 0; a < sizz; a++)
        {
            cin >>v[a];

        }


        sort(v.begin(), v.end());

        int l = 0, r = sizz - 1;
        int diff = MAXX;
        int ans = 0;

        while (l<r)
        {
            int le = v[l];
            int ri = v[r];

            if (le + ri == target) //  두개의 합이 원하는 값이라면
            {
                l++;
                r--;
            }

            else if (le + ri > target) // 두개의 합이 원하는 값보다 크다면
                r--;
 

            else
                l++;


            if (abs(target - (le + ri)) < diff) // 현재 두개의 차이가 최소 차이라면 
            {
                diff = abs(target - (le + ri));
                ans = 1; // 값 초기화
            }

            else if (abs(target - (le + ri)) == diff) // 기존의 최소 차이와 동일하다면
                ans++;


        }

        cout << ans << '\n';


    }
}
