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
    for (int a = 0; a < cass; a++)
    {
        int b;
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end());
    

    int start = 0;
    int eend = cass - 1;
    int rs = v[start] + v[eend]; // 초기값설정

    while (start<eend) // 투포인터
    {

        int tmp = v[start] + v[eend];
        
        if (abs(rs) > abs(tmp)) // 절대값이 더 작다면 갱신
            rs = tmp;

        if (tmp > 0) //0에 가깝게 수를 줄여야함
            eend--;
        else if (tmp < 0) //0에 가깝게 수를 키워야함
            start++;
        else if (tmp == 0) //0이면 정지
            break;


    }
    cout << rs;

}
