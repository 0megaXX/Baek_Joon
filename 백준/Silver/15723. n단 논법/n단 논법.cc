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
#include <chrono>
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647

bool AisB[26][26];

void floyd() // 플로이드 워셜
{
    for (int a = 0; a < 26; a++)
        for (int b = 0; b < 26; b++)
            for (int c = 0; c < 26; c++)
            {
                if (AisB[b][c]) // 이미 된다면 continue
                    continue;
                AisB[b][c] = AisB[b][a] & AisB[a][c];
            }


    return ;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char a, b;
    string is; // string형만 담아둘 변수
    int n;
    
    cin >> n;
    while (n--)
    {
        cin >> a >> is >> b;
        AisB[a - 'a'][b - 'a'] = true; // a와 b는 true
    }

    floyd();
    
    cin >> n;
    while (n--)
    {
        cin >> a >> is >> b;
        cout << (AisB[a - 'a'][b - 'a'] ? 'T' : 'F') << "\n";
    }
    
	

   
    return 0;
}

