#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[2];

struct Btree_node {
    int value, x;
    Btree_node* left, * right;

    Btree_node(int x, int value)
    {
        this->x = x;
        this->value = value;
        left = right = nullptr;
    }

    void insert(int x, int value)
    {
        Btree_node* node = this;
        Btree_node* parent = nullptr;
        while (node != nullptr)
        {
            parent = node;
            if (node->x > x)
                node = node->left;
            else
                node = node->right;
        }
        node = new Btree_node(x, value);
        if (parent->x > node->x)
            parent->left = node;
        else
            parent->right = node;
    }

    ~Btree_node()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void preorder(Btree_node* node)
{
    if (node) 
    {
        v[0].push_back(node->value);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(Btree_node* node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        v[1].push_back(node->value);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<pair<int, int>, int>> nodes;

    for (int i = 1; i <= (int)nodeinfo.size(); i++)
        nodes.push_back({ {nodeinfo[i - 1][1], nodeinfo[i - 1][0]}, i });       // ((y, x), 노드 번호) 형태로 저장
    sort(nodes.begin(), nodes.end());                                           // y 기준으로 오름차순 정렬

    Btree_node* head = new Btree_node(nodes.back().first.second, nodes.back().second);
    nodes.pop_back();

    while (!nodes.empty())
    {
        head->insert(nodes.back().first.second, nodes.back().second);           // y 좌표가 큰 노드부터 차례로 이진 트리에 저장
        nodes.pop_back();
    }
    preorder(head);
    postorder(head);

    answer.push_back(v[0]);
    answer.push_back(v[1]);

    delete head;
    return answer;
}