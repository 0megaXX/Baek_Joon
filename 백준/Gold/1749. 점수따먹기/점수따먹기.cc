#include <iostream>
#include <algorithm>
using namespace std;

#define MAXX 99999999

int arr[201][201];
int row, col;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;

    // 입력 받기
    for (int a = 1; a <= row; a++) 
        for (int b = 1; b <= col; b++) 
            cin >> arr[a][b];
        
    

    int maxSum = -MAXX;  // 최대 부분합 초기화

    // Kadane's Algorithm
    
    for (int left = 1; left <= col; left++)  // 왼쪽 열을 고정
    {  
        int tmp[201] {0};  // 각 열에 대해 부분합을 저장할 배열
        
        for (int right = left; right <= col; right++)  // 오른쪽 열을 고정 
        {  
            // 각 열에 대해 부분합을 구하고 그 값을 tmp 배열에 저장
            for (int a = 1; a <= row; a++) 
                tmp[a] += arr[a][right];
            

           
            int currentMax = tmp[1];
            int currentSum = tmp[1];
            
            for (int a = 2; a <= row; a++) 
            {
                currentSum = max(tmp[a], currentSum + tmp[a]);
                currentMax = max(currentMax, currentSum);
            }

            // 최대값 갱신
            maxSum = max(maxSum, currentMax);
        }
    }

    cout << maxSum;  

    return 0;
}
