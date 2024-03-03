# LinkedList
1. `LinkedList` vs `ArrayList`
2. `LinkedList`의 구조
3. `LinkedList`의 시간복잡도
4. `LinkedList` 메서드

<br>

## 1. LinkedList vs ArrayList
- `ArrayList` : 사이즈가 가변 (동적으로 값을 삽입하고 삭제)
  - 각 데이터의 `index`를 가지고 있음
  - 데이터의 삽입과 삭제시 `ArrayList`는 그만큼 위치를 맞춰야 함 (데이터 5개가 있을때 앞의 2개를 삭제했다면 뒤의 3개를 앞으로 한칸씩 이동)
  - 때문에 삭제와 삽입이 많다면 ArrayList는 비효율적
- `LinkedList` : 사이즈가 가변
  - 인덱스가 존재는 하나, 선형구조이기 때문에 100번째 노드를 확인하려면 첫 번째 노트부터 백 번째 노드까지 일일이 움직임
  - 배열의 단점을 보완하기 위해 `LinkedList`가 나옴
  - 내부적으로 양방향의 연결리스트로 구성되어 있어 참조하려는 원소에 따라 정방향, 또는 역순으로 순회 가능
  - 데이터를 추가, 삭제시 가리키고 있는 주소값만 변경하면 되기 때문에 `ArrayList`에 비해 상당히 효율적 (2번째 값을 삭제했을 경우, 1번째 노드가 3번째 노드를 가리키게 하면 됨)

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
