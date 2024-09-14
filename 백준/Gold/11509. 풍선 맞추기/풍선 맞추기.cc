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

    vector<int> arrows(1000001, 0); // 각 높이에서 사용할 화살의 개수

    int shots = 0; // 필요한 화살의 개수

    for (int a = 0; a < cass; a++)
    {
        int height;
        cin >> height;

        if (arrows[height] > 0) // 현재 높이에 맞출 화살이 있다면
        {           
            arrows[height]--;
            arrows[height - 1]++; // 한 단계 낮은 높이에 맞출 화살을 추가
        }
        else // 현재 높이에 맞출 화살이 없다면
        {
            shots++;
            arrows[height - 1]++; // 한 단계 낮은 높이에 맞출 화살을 추가
        }
    }

    cout << shots << '\n';

}