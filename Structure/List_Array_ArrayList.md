### Array vs List vs ArrayList
---
- List : `ADT` (Abstract Data Type), 인터페이스
- ArrayList : 클래스, 동적(가변성 있는 사이즈)
- Array : 동적으로 생성된 오브젝트, 정적 (고정된 사이즈), 자료구조

💡 Array를 List로 구현한게 ArrayList

💡 Java 알고리즘 테스트에서는 주로 ArrayList를 많이 사용한다. 
Array를 쓰기에는 얼마나 많은 아이템이 저장되어야 할지 모르기 때문에, 동적인 자료 구조를 쓰는 편이 낫다.


### ArrayList의 사용법
---
##### 기본 생성법
``` java
ArrayList<Integer> integers1 = new ArrayList<Integer>();                      // 타입 지정
ArrayList<Integer> integers2 = new ArrayList<>();                             // 타입 생략 가능
ArrayList<Integer> integers3 = new ArrayList<>(10);                           // 초기 용량(Capacity) 설정
ArrayList<Integer> integers4 = new ArrayList<>(integers1);                    // 다른 Collection값으로 초기화
ArrayList<Integer> integers5 = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5)); // Arrays.asList()
```

##### 사용법
```java
ArrayList<String> colors = new ArrayList<>();
colors.add("White”);                                // 삽입
colors.add(0, "Green”);                             // 삽입 (1칸씩 밀림)
colors.set(0, "Black");                             // 수정
colors.add("Red”)
colors.add("Yello”);
colors.remove("White");                             // 제거 (아이템을 직접 입력)
colors.remove(0);                                   // 제거 (위치 입력)
colors.clear();                                     // 전체 제거

boolean contains = colors.contains("Black");        // 값이 존재하면 true, 없으면 false 반환
int index = colors.indexOf("Blue");                 // 값이 존재하면 index 반환, 없으면 -1 반환
```
