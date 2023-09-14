# LinkedList
1. `LinkedList` vs `ArrayList`
2. `LinkedList`의 구조
3. `LinkedList`의 시간복잡도

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
