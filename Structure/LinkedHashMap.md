# 개요
1. LinkedHashMap이란
2. 사용법

## 1. LinkedHashMap이란
- HashMap과 흡사
- 단, Map에 입력된 순서를 기억하는 구조에서 차이점이 존재

## 2. 사용법
``` java
LinkedHashMap<String, String> map = new LinkedHashMap<>();
map.put("Key1", "Value1");
map.put("Key2", "Value2");
map.put("Key3", "Value3");

for (Map.Entry<String, String> entry : map.entrySet()) {
  System.out.println(entry.getKey() + ":" + entry.getValue());
}

```
- 결과적으로 Value1 -> Value2 -> Value3 이라는 순서가 지켜져서 출력됨
