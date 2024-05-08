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
#include <stack>


using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;
    while (cass--)
    {
        int araay_count;
        int array_half;
        cin >> araay_count;
        array_half = ceil((float)araay_count / 2);
        vector<int>arr;
        for (int a = 0; a < araay_count; a++)
        {
            int b;
            cin >> b;
            arr.push_back(b);
        }
        cout << array_half << endl;
       
        for (int a = 0; a < arr.size(); a++)
        {
           
            
            if (a % 2 == 0)
            {
                
                priority_queue<int, vector<int>, greater<int>> pq;

                for (int b = 0; b <= a; b++)
                {
                    pq.push(arr[b]);
                   
                }
                for (int b = 0; b < (a / 2); b++)
                {
                    
                    pq.pop();
                }
                cout <<pq.top()<< " ";
            }
        }
        
        cout << endl;
    }
    


    return 0;
}