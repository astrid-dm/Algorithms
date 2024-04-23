## 목차
1. Hash란?
2. HashMap 이란
3. HashMap과 관련된 코드
4. HashMap의 정렬 - key
5. HashMap의 정렬 - value

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
	- `key` 값에 따른 저장 순서를 보장하고 싶은 경우, `LinkedHashMap` 사용 
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

// 4. HashMap에 특정 Value가 존재하는지 확인
if(map.containsValue(1)) System.out.println("1 exists"); // 출력

// 5. HashMap에 기존에 존재하던 Key값을 업데이트 하는 경우
map.put("DEF", map.getOrDefault("DEF", 0) + 1); // "DEF"가 존재하면 "DEF"의 value+1을 저장, 아닐경우 1을 저장

// 6. HashMap으로 for문 돌리기
for(String key : map.keySet()) {
	System.out.println("key : " + key + " value : " + map.get(key));
}

// 7. key값 제거
map.remove("ABC");

// 8. key만 가져오기 : keySet()
for(String key : map.keySet()){
	System.out.println("키 : " + key);
}

// 9. value만 가져오기
ArrayList<Integer> temp = List.of(map.values());

// 10. 전체 제거
map.clear();

```

---
### 4. HashMap의 정렬 - key
``` java
        Map<String, Integer> map = new HashMap<>();

        map.put("A", 10);
        map.put("D", 30);
        map.put("C", 20);
        map.put("B", 40);


        List<String> keySet = new ArrayList<>(map.keySet());

        // 키 값으로 오름차순 정렬
        Collections.sort(keySet);

        for (String key : keySet) {
            System.out.print("Key : " + key);
            System.out.println(", Val : " + map.get(key));
        }
       
        /*  결과
            Key : A, Val : 10
            Key : B, Val : 40
            Key : C, Val : 20
            Key : D, Val : 30
         */
        
        

        // 키 값으로 내림차순 정렬
        Collections.reverse(keySet);

        for (String key : keySet) {
            System.out.print("Key : " + key);
            System.out.println(", Val : " + map.get(key));
        }
        
        /*  결과
            Key : D, Val : 30
            Key : C, Val : 20
            Key : B, Val : 40
            Key : A, Val : 10
        */
```

---
### 5. HashMap의 정렬 - value
``` java
        Map<String, Integer> map = new HashMap<>();

        map.put("A", 10);
        map.put("D", 30);
        map.put("C", 20);
        map.put("B", 40);


        List<String> keySet = new ArrayList<>(map.keySet());

        // Value 값으로 오름차순 정렬
        keySet.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return map.get(o1).compareTo(map.get(o2));
            }
        });

        for (String key : keySet) {
            System.out.print("Key : " + key);
            System.out.println(", Val : " + map.get(key));
        }

        /*
            결과
            Key : A, Val : 10
            Key : C, Val : 20
            Key : D, Val : 30
            Key : B, Val : 40
         */

        // Value 값으로 내림차순 정렬
        // 위 comparator 람다 표현식으로
        keySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));

        for (String key : keySet) {
            System.out.print("Key : " + key);
            System.out.println(", Val : " + map.get(key));
        }

        /* 결과
            Key : B, Val : 40
            Key : D, Val : 30
            Key : C, Val : 20
            Key : A, Val : 10
         */
```
