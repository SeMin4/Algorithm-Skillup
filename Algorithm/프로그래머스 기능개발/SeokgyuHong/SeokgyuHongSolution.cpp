#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> a;
    int* check;
    int cnt = 0;
    int n = speeds.size();
    check = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        check[i] = 0; //다 0으로 초기화 
    }
    for (int i = 0; i < n; i++)
    {
        check[i] = ceil((100 - progresses[i]) / (float)speeds[i]);
    }
    int pivot = check[0];
    cnt++;
    for (int i = 1; i < n; i++)
    {
        if (check[i] <= pivot)
            cnt++;
        else if (check[i] > pivot)
        {
            answer.push_back(cnt);
            cnt = 1;
            pivot = check[i];
        }
    }
    answer.push_back(cnt);

    return answer;
}