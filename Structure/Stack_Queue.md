### Stack
- LIFO (Last In First Out)
- Adding = O(1)
- Removing = O(1)
- Searching = O(n)

##### Stack의 메서드

``` java
Stack<Integer> stack = new Stack<>();   // int형 stack 선언
stack.push(1);                          // stack에 값 1 추가
stack.push(2);                          // stack에 값 2 추가
stack.pop();                            // stack의 최상단 값(= 마지막으로 들어온 값)을 반환하고 제거
stack.peek();                           // stack의 최상단 값 (= 마지막으로 들어온 값) 반환
stack.size();                           // stack의 사이즈 반환
stack.empty();                          // stack이 비어있는지 확인 (비어있으면 true)
stack.contains(1);                      // stack에 1이 이는지 확인 (있다면 true)
stack.clear()                           // stack 초기화
```

### Queue
- FIFO (First In First Out)
- Adding = O(1)
- Removing = O(1)
- Searching = O(n)

##### Queue의 메서드

``` java
Queue<Integer> queue = new LinkedList<>();  // int형 queue 선언 
queue.offer(1);                             // queue에 값 1 추가
queue.offer(2);                             // queue에 값 2 추가
queue.peek();                               // queue의 첫 번째 값 (= 가장 먼저 들어온 값) 출력
queue.remove();                             // queue의 첫 번째 값 제거
queue.poll();                               // queue의 첫 번째 값 반환하고 제거. 비어있다면 null
queue.isEmpty();                            // queue가 비어있는지 확인 (비어있으면 true)
queue.size();                               // queue 사이즈 반환
queue.contains(2);                          // queue에 특정 값이 있는지 확인
queue.remove(2);                            // queue에서 특정 값을 제거
queue.clear();                              // queue 초기화
```
