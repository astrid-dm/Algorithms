### Hash란?
---
- [HashTable](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/HashTable.md) 설명 참고

<br>

### HashSet 이란
---
- Set 인터페이스에서 지원하는 구현 클래스
	- 비선형 구조이기 때문에 `순서`와 `인덱스`가 존재하지 않음
	- 때문에 값을 추가 / 삭제 하는 경우, Set 내부에 해당 값을 검색하여 해당 기능을 수행
	- 이로 인해 처리 속도가 List 구조에 비해 느림 
	- `HashSet` 내부를 보면 `HashMap`을 사용하여 구현
- 저장 순서와 출력 순서를 보장하지 않는 데이터 구조
	- 저장 순서를 유지해야한다면 JDK 1.4부터 제공하는 `LinkedHashSet`을 사용
- 중복은 허용하지 않음
	- HashMap과 달리 null도 허용

<br>

### HashSet 코드 예시
---

``` java

// 1. HashSet 생성
HashSet<String> set = new HashSet<>();

// 2. 요소 추가
set.add("ABC");

// 3. 특정 요소가 있는지 확인
if(set.contains("ABC")) System.out.println("ABC exists"); // 출력

// 4. for문 돌리기
for(String s : set) {
	System.out.println(s);
}

// 5. 요소 제거
set.remove("ABC");

```

<br>

### HashSet 시간복잡도
---
- add : O(1)
- contains : O(1)
- next : O(h / n) // h는 테이블 용량 

<br>

### 요약
---
- 객체들을 순서없이 저장하고 동일한 객체를 중복저장하지 않음
- 중복되지 않는 값들을 저장할 때 용이
- 순서없이 저장됨
- null을 허용
