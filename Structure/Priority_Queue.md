## 개요
1. Priority Queue란
2. Priority Queue 특징
3. 메서드

---

### 1. Priority Queue란
- 우선순위 큐로, 일반적인 큐(FIFO)의 구조를 가지면서 데이터가 나가는 순서에 우선순위를 두어 우선순위가 높은 데이터가 먼저 나가는 구조
- Heap을 사용해서 구현하는게 일반적
- 최대 값이 우선순위인 큐 : 최대 힙
- 최소 값이 우선순위인 큐 : 최소 힙

---

### 2. Priority Queue 특징
- 높은 우선순위의 요소를 먼저 꺼내서 처리하는 구조
- 내부 요소는 힙으로 구성되어 있어 이진트리 구조로 이루어짐
- 내부 구조가 Heap으로 구성되어 있기에 삽입 / 삭제 시 시간복잡도는 O(log(n))

---

### 3. 메서드
``` java
//낮은 숫자가 우선 순위인 int 형 우선순위 큐 선언
PriorityQueue<Integer> priorityQueueLowest = new PriorityQueue<>();

//높은 숫자가 우선 순위인 int 형 우선순위 큐 선언
PriorityQueue<Integer> priorityQueueHighest = new PriorityQueue<>(Collections.reverseOrder());

// add(value) 메서드의 경우 만약 삽입에 성공하면 true를 반환, 
// 큐에 여유 공간이 없어 삽입에 실패하면 IllegalStateException을 발생
priorityQueueLowest.add(1);
priorityQueueLowest.add(10);
priorityQueueLowest.offer(100);

priorityQueueHighest.add(1);
priorityQueueHighest.add(10);
priorityQueueHighest.offer(100);

// 첫번째 값을 반환하고 제거 비어있다면 null
priorityQueueLowest.poll();

// 첫번째 값 제거 비어있다면 예외 발생
priorityQueueLowest.remove(); 

// 첫번째 값을 반환만 하고 제거 하지는 않는다.
// 큐가 비어있다면 null을 반환
priorityQueueLowest.peek();

// 첫번째 값을 반환만 하고 제거 하지는 않는다.
// 큐가 비어있다면 예외 발생
priorityQueueLowest.element();

// 초기화
priorityQueueLowest.clear();
```
