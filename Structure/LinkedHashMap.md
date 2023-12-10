# 개요
1. LinkedHashMap이란
2. 사용법
3. 코테 예시

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

### 3. 코테 예시
``` java
class LRUCache {

    int total;
    LinkedHashMap<Integer, Integer> map;
    
    public LRUCache(int capacity) {
        total = capacity;
        map = new LinkedHashMap<>(capacity, 0.75f);
    }
    
    public int get(int key) {
        return map.getOrDefault(key, -1);
    }
    
    public void put(int key, int value) {
        map.remove(key);
        map.put(key, value);
        if(map.size() > total) {
            map.remove(map.entrySet().iterator().next().getKey());
        }
    }
}
```
- capacity : initial capacity
- 0.75f : Load factor. It will resize when it's 75% full
- true : The map will be ordered based on the order in which entries were accessed
