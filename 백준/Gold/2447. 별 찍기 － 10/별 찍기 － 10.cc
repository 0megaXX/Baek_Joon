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

using namespace std;
#define MAXX 99999999


void star(int a, int b, int num)
{
    if( (a / num) % 3 == 1 && (b / num) % 3 == 1) // 가운데는 공백으로
        cout << ' ';
    
    else
    {
        if(num / 3 == 0)
            cout <<'*';
        else
            star(a,b,num/3);
    }
}


int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int num;
    cin >> num;
    
    for(int a = 0; a < num; a++)
    {
        for(int b = 0; b < num; b++)
            star(a,b,num);
        
        cout << '\n';
    }
}