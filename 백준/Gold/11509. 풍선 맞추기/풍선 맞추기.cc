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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int cass;
    cin >> cass;

    vector<int> bal(1000001, 0); // 각 높이의 풍선의 개수

    int shots = 0; // 필요한 화살의 개수

    for (int a = 0; a < cass; a++)
    {
        int height;
        cin >> height;

        if (bal[height] > 0) // 현재 높이로 떨어질 화살이 있다면
        {           
            bal[height]--; // 현재 높이로 떨어질 화살 제거
            bal[height - 1]++; // 한 단계 낮은 높이로 화살 이동
        }

        else // 현재 높이에 떨어질 화살이 없다면
        {
            shots++; // 화살 발사
            bal[height - 1]++; // 한 단계 낮은 높이로 화살 이동
        }
    }

    cout << shots << '\n';

}