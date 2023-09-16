# LinkedList
1. `LinkedList` vs `ArrayList`
2. `LinkedList`의 구조
3. `LinkedList`의 시간복잡도
4. `LinkedList` 메서드

<br>

## 1. LinkedList vs ArrayList
- `ArrayList` : 사이즈가 불가변 (고정)
  - [0], [1]과 같은 인덱스로 데이터 접근
- `LinkedList` : 사이즈가 가변
  - 가변적이기 때문에 인덱스가 별도로 존재하지 않음

<br>

## 2. LinkedList의 구조
- `head`(맨 앞의 데이터)와 `tail`(맨 뒤의 데이터)이 존재
  - `tail`다음은 null

<br>

## 3. LinkedList의 시간복잡도
- head 제거 : O(1)
- tail 제거 : O(n)
- tail, head가 아닌 특정 노드 제거 : O(n)
- tail 또는 head 추가 : O(1)
- tail, head가 아닌 특정 노드 추가 : O(n)
- 특정원소 찾기 : O(n)
  - `ArrayList`였으면 index로 접근해서 찾을경우 O(1)이라서 `LinkedList`보다 빠름
<img width="1430" alt="image" src="https://github.com/Astrid-DM/Algorithms/assets/65839810/b8c5395b-28da-4652-8621-a0ba7883dd44">

<br>

## 4. LinkedList의 메서드
``` java
package datastructures.linkedList;

public class LinkedList {

    private Node head;
    private Node tail;
    private int length;

    class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

    public LinkedList(int value) {
        Node newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    public Node get(int index) {
        if (length == 0 || index >= length) {
            return null;
        }
        Node temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp.next;
        }
        return temp;
    }

    public boolean set(int index, int value) {
        Node temp = get(index);
        if (temp != null) {
            temp.value = value;
            return true;
        }
        return false;
    }

    public boolean insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }

        Node newNode = new Node(value);
        Node temp = get(index - 1);
        newNode.next = temp.next;
        temp.next = newNode;
        length++;
        return true;
    }

    public Node remove(int index) {
        if ( index < 0 || index >= length || length == 0) return null;
        if ( index == 0 ) return removeFirst();
        if ( index == length-1 ) return removeLast();
        Node prev = get(index - 1);
        Node temp = prev.next;
        prev.next = temp.next;
        temp.next = null;
        length--;
        return temp;
    }

    public void append(int value) {
        Node newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        length++;
    }

    public void prepend(int value) {
        Node newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = head;
            head = newNode;
        }
        length++;

    }

    public Node removeFirst() {
        if (length == 0) return null;
        Node temp = head;
        head = head.next;
        temp.next = null;
        length--;
        if (length == 0) {
            tail = null;
        }
        return temp;
    }

    public Node removeLast() {
        if (length == 0) return null;
        Node temp = head;
        Node pre = head;
        while (temp.next != null) {
            pre = temp;
            temp = temp.next;
        }
        tail = pre;
        tail.next = null;
        length--;
        if (length == 0) {
            head = null;
            tail = null;
        }
        return temp;
    }

    public void reverse() {
        // exchange head and tail
        Node temp = head;
        head = tail;
        tail = temp;

        // temp = origin head
        Node after = temp.next;
        Node before = null;

        for (int i = 0; i < length; i++) {
            after = temp.next;
            temp.next = before;
            before = temp;
            temp = after;
        }
    }

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.value);
            temp = temp.next;
        }
    }

    public void getHead() {
        System.out.println("Head : " + head.value);
    }

    public void getTail() {
        System.out.println("Tail : " + tail.value);
    }

    public void getLength() {
        System.out.println("Length : " + length  );
    }

}
```
