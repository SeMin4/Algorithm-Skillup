#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct Node{
    int idx, x, y;
    Node* left;
    Node* right;
};
Node* head;

Node* createNode(int idx, int x, int y);
void insertNode(Node* node);
bool comp(const vector<int>&a, const vector<int>&b);
void preorder(Node* ptr, vector<int> &tmp);
void postorder(Node* ptr, vector<int> &tmp);


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i = 0; i < nodeinfo.size(); ++i)
        nodeinfo[i].push_back(i+1);
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    for(int i = 0; i < nodeinfo.size(); ++i){
        insertNode(createNode(nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]));
    }
    vector<int> tmp;
    preorder(head,tmp);
    answer.push_back(tmp);
    tmp.clear();
    postorder(head,tmp);
    answer.push_back(tmp);
    return answer;
}
void insertNode(Node* node){
    if (head == nullptr){
        head = node;
    }else{
        Node* compNode = head;
        while(true) {
            if (node->x > compNode->x) {
                if (compNode->right == nullptr) {
                    compNode->right = node;
                    break;
                } else {
                    compNode = compNode->right;
                }
            } else {
                if (compNode->left == nullptr) {
                    compNode->left = node;
                    break;
                } else {
                    compNode = compNode->left;
                }
            }
        }
    }
}
Node* createNode(int idx, int x, int y){
    Node* tmp;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->idx = idx;
    tmp->x = x;
    tmp->y = y;
    tmp->left = nullptr;
    tmp->right = nullptr;
    return tmp;
}
bool comp(const vector<int>&a, const vector<int>&b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1]>b[1];
}
void preorder(Node* ptr, vector<int> &tmp){
    if(ptr != nullptr){
        tmp.push_back(ptr->idx);
        preorder(ptr->left, tmp);
        preorder(ptr->right, tmp);
    }
}
void postorder(Node* ptr, vector<int> &tmp){
    if(ptr != nullptr){
        postorder(ptr->left, tmp);
        postorder(ptr->right, tmp);
        tmp.push_back(ptr->idx);
}
}