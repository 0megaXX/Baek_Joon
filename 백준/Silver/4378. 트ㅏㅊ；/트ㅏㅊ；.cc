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


// 자판배치와 같은 영역
char keyboard[4][13] =
{
	{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
	{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
	{'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
	{'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
	while (getline(cin, s)) // 공백까지 입력받기 위한 getline
	{
		string rs = "";
		for (char c : s)
		{
			if (c == ' ') // 스페이스바는 길어 옆칸은 안누름
			{
				rs += c;
				continue;
			}

			bool check = false;
			for (int a = 0 ; a < 4; a++)
			{
				for (int b = 0 ; b < 13; b++)
					if (c == keyboard[a][b])
					{
						rs += keyboard[a][b - 1];
						check = true;
						break;
					}
                
				if (check)
                    break;
			}
		}
        
		cout << rs <<'\n';
	}

    return 0;
}

