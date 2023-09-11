## 목차
1. Hash란?
2. HashMap 이란
3. HashMap과 관련된 코드

<br>

### Hash란?
---
- [HashTable](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/HashTable.md) 설명 참고
<br>

### HashMap 이란
---
- Map 인터페이스를 구현한 컬렉션
- Map 인터페이스는 Key 값과 Value 값을 묶어서 하나의 entry(한 쌍)로 저장
- Key값을 기반으로 데이터를 저장하고 접근하기 때문에 Key값은 Unique 해야함
	- 중복된 Key 값 저장 X
	- null로 key값 저장 X
	- value는 null로 저장 O
- 저장 순서와 출력 순서를 보장하지 않는 데이터 구조
- Multi Thread를 지원하며, 따라서 동시에 HashMap을 건드릴 경우 Key - value에서 문제가 발생할 수 있음
	- 따라서 Thread safe를 지원하고 싶으면 HashTable 사용

<br>

### HashMap과 관련된 코드
---
``` java

// 1. HashMap 선언
// Generic Class인 HashMap에 Primitive Type은 선언 불가 (ex : int)
HashMap<String, Integer> map = new HashMap<>();

// 2. HashMap에 값 넣기
map.put("ABC", 1);

System.out.println(map.get("ABC")); // 1 출력

// 3. HashMap에 특정 Key가 존재하는지 확인
if(map.containsKey("ABC")) System.out.println("ABC exists"); // 출력 

// 4. HashMap에 기존에 존재하던 Key값을 업데이트 하는 경우
map.put("DEF", map.getOrDefault("DEF", 0) + 1); // "DEF"가 존재하면 "DEF"의 value+1을 저장, 아닐경우 1을 저장

// 5. HashMap으로 for문 돌리기
for(String key : map.keySet()) {
	System.out.println("key : " + key + " value : " + map.get(key));
}

// 6. key값 제거
map.remove("ABC");

// 7. 전체 제거
map.clear();

```
