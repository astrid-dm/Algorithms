## 목차
1. Tree란
2. The status of Tree
    - Perfect 예시
    - Complete 예시
3. Binary Search Tree (BST)
    - BST의 최악의 시나리오
4. Linked List와 비교했을때 빠름의 차이점
5. Tree 코드

<br/><hr/><br/>

### Tree란
- `LinkedList`는 `Tree`가 둘로 나뉘지 않은것과 동일하다
- `leaf` = 더 이상 자식을 가지고 있지 않은 최하단의 노드

### The status of Tree
- Full : 모든 노드들이 0, 또는 2개의 자식 노드를 가리킴
- Not Full : 최소한 한 개의 노드가 1개의 또 다른 노드를 가리킴
- Perfect : 모든 노드가 2개의 자식을 가지고 있고, 모든 `leaf`가 같은 레벨에 있음
- Complete : 마지막 level을 제외한 나머지 level에 node들이 가득 차있고, 마지막 level에서 node는 가장 왼쪽부터 채워짐

##### Perfect 예시
![Perfect 노드](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/perfect.png?raw=true)

##### Complete 예시
![Complete 노드](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/Tree_Complete.png?raw=true)

### Binary Search Tree (BST)
- 오른쪽에 있는 노드는 부모보다 크고, 왼쪽에 있는 노드는 부모보다 작음 (위 complete 예시의 트리가 BST)
- Big O는 O(log n). 참고로 로그 아래 지수는 2

#### BST의 최악의 시나리오
![Worst 케이스](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/worst.png?raw=true)
- 위와같은 최악의 시나리오를 가정하면 log(n)
- 이 경우에는 Linked List라고 볼 수 있음
- 이때의 시간 복잡도는 O(n)이지만, 이런 경우는 배제하여 BST의 Big O는 O(log n)이라고 함

### Linked List와 비교했을때 빠름의 차이점
![LinedList vs Tre](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/LinkedList_And_Tree.png?raw=true)

### Tree 코드
``` java
package datastructures.binaryserachtree;

public class BinarySearchTree {
    Node root;

    class Node {
        int value;
        Node left;
        Node right;

        private Node(int value) { // Constructor
            this.value = value;
        }
    }

    public boolean insert(int value) {
        Node newNode = new Node(value);

        if(root == null){
            root = newNode;
            return true;
        }

        Node temp = root;
        while(true) {
            if (newNode.value == temp.value) return false;
            // The situation where we're trying to insert a node with a value is already in the tree

            if (newNode.value < temp.value) {
                if (temp.left == null) {
                    temp.left = newNode;
                    return true;
                }
                temp = temp.left;
            } else {
                if (temp.right == null) {
                    temp.right = newNode;
                    return true;
                }
                temp = temp.right;
            }
        }
    }

    public boolean contains(int value) {
        if(root == null) return false;
        Node temp = root;

        while(temp != null) {
            if(value < temp.value) {
                temp = temp.left;
            } else if(value > temp.value) {
                temp = temp.right;
            } else return true;
        }
        return false;
    }
}
```
