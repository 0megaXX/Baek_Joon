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

using namespace std;
#define MAXX 99999999





int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

    int n; 
    cin >> n;
    string str = "";

    char arr[50];

    cin >> str;

    for (int a = 0; a < str.length(); a++)  
        arr[a] = str[a];

    for (int a = 1; a < n; a++) 
    {
        cin >> str;
        for (int b = 0; b < str.length(); b++) 
            if (arr[b] != str[b]) 
                arr[b] = '?';
        
    }
    for (int a = 0; a < str.length(); a++)
        cout << arr[a];
    return 0;

}
