# 1. nodeinfo를 정렬 y가 큰순, x가 작은순으로
# 2. 트리 생성
# 3. 전위 순회
# 4. 후위 순회

import sys
sys.setrecursionlimit(10**6)

preorderList= []
postorderList = []

# x,y좌표 data를 가지는 클래스
class Tree :
    def __init__(self,data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


#전위 순회 루트 왼쪽 오른쪽
def preorder(root, nodeinfo):
    preorderList.append(nodeinfo.index(root.data) + 1)
    
    if root.left:
        preorder(root.left, nodeinfo)
    if root.right:
        preorder(root.right,nodeinfo)

#후위 순회 왼쪽 오른쪽 루트
def postorder(root, nodeinfo):
    if root.left:
        postorder(root.left, nodeinfo)
    if root.right:
        postorder(root.right, nodeinfo)
    postorderList.append(nodeinfo.index(root.data) + 1)
    
def solution(nodeinfo):
    answer = []

    #1 정렬 y가 높은 순대로, x가 작은 순대로
    sortedNodeInfo = sorted(nodeinfo, key = lambda x : (-x[1],x[0]))

    #2 정렬순대로 트리 생성
    root = Tree(sortedNodeInfo[0])

    for i in range(1,len(sortedNodeInfo)):
        node = sortedNodeInfo[i]
        current = root
        while True :
            if node[0] < current.data[0]: #왼쪽 자식
                #왼쪽 자식이 이미 있다면 재귀적으로 들어간다.
                if current.left :
                    current = current.left
                    continue
                #왼쪽 자식이 없다면 왼쪽자식에 집어넣는다.
                else :
                    current.left = Tree(node)
                    break
            else :
                if current.right:
                    current = current.right
                    continue
                else:
                    current.right = Tree(node)
                    break
            break
                        
    #2.전위순회
    preorder(root, nodeinfo)
    #3.후위순회
    postorder(root, nodeinfo)
    
    answer.append((preorderList))
    answer.append((postorderList))
    return answer