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

string dp[10001]{ "0","1" };




string convine(string a, string b)
{

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len;
    if (a.length() > b.length())
        len = a.length();
    else
        len = b.length();

    int sub = 0;

    string rs;

    for (int c = 0; c < len; c++)
    {


        int num_a = (c < a.length()) ? (a[c] - '0') : 0;
        int num_b = (c < b.length()) ? (b[c] - '0') : 0;
        int num = num_a + num_b + sub;


        if (num < 0)
        {
            num += '0';

        }





        if (num > 9)
        {
            sub = 1;
            num -= 10;
        }
        else
            sub = 0;

        char z = num + '0';

        rs.push_back(z);

    }



    if (sub == 1)
        rs.push_back('1');

    reverse(rs.begin(), rs.end());

    return rs;

}









int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int ct;
    cin >> ct;

    for (int a = 2; a <= ct; a++)
    {

        dp[a] = convine(dp[a - 1], dp[a - 2]);

    }
   
    cout << dp[ct];



}