## 목차
1. `HashTable`
2. `HashTable`의 시간 복잡도
2. `HashTable` vs `HashMap`
2. `HashTable` 구현
3. `HashTable` 실제 사용법
4. `HashTable` 기술 인터뷰 사례

<br/><br/>

### HashTable이란
- Key, Value가 1:1로 쌍을 이루어 Table에 저장됨
- 여기서 Key는 값을 식별하기 위한 고유한 키, Value는 키가 가진 값을 의미

![HashTable](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/HashTable2.png?raw=true)

### HashTable의 시간 복잡도
- Insert : O(1)
- Lookup By Key : O(1)
- Lookup By Value : O(n)

### HashTable vs HashMap

|항목|HashTable|HashMap|
|------|:---:|:---:|
|Null값 허용|X|O|
|Thread-safe|O|X|
|Syncronization|O|X|
- HashMap은 멀티스레드 제공이 반면, HashTable은 한 번에 하나의 스레드만 허용돼서 thread-safe
- HashMap은 보조 해시를 사용하기 때문에 보조 해시 함수를 사용하지 않는 HashTable에 비해 해시 충돌 (Hash Collision)이 덜 발생할 수 있어 상대적으로 성능상 이점이 있음
- HashTable은 Legacy, HashMap은 현재까지도 지속적으로 개선되고 있음

### HashTable 구현
``` java
package datastructures.hashtable;

import java.util.ArrayList;

public class HashTable {
    private int size = 7;
    private Node[] dataMap;

    class Node {
        String key;
        int value;
        Node next;

        Node(String key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public HashTable() {
        dataMap = new Node[size];
    }

    public void set(String key, int value) {
        int index = hash(key);
        Node newNode = new Node(key, value);
        if (dataMap[index] == null) {
            dataMap[index] = newNode;
        } else {
            Node temp = dataMap[index];
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
    }

    public int get(String key) {
        int index = hash(key);
        Node temp = dataMap[index];
        while (temp != null) {
            if (temp.key == key) return temp.value;
            temp = temp.next;
        }
        return 0;
    }

    public ArrayList keys() {
        ArrayList<String> allKeys = new ArrayList<>();
        for (int i=0; i< dataMap.length; i++) {
            Node temp = dataMap[i];
            while (temp != null) {
                allKeys.add(temp.key);
                temp = temp.next;
            }
        }
        return allKeys;
    }

    private int hash(String key){
        int hash = 0;
        char[] keyChars = key.toCharArray();
        for (int i=0; i<keyChars.length; i++) {
            int asciiValue = keyChars[i];
            hash = (hash + asciiValue * 23) % dataMap.length;
        }
        return hash;
    }

    public void printTable() {
        for(int i=0; i< dataMap.length; i++) {
            System.out.println(i + ":");
            Node temp = dataMap[i];
            while (temp != null) {
                System.out.println(" {" + temp.key + "= " + temp.value + "}");
                temp = temp.next;
            }
        }
    }
}

```
`set` 메서드가 이해 안된다면 아래 그림을 확인하기
![HashTable2](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/HashTable.png?raw=true)

### HashTable 실제 사용법
``` java
import java.util.Hashtable;

public class HashTableDemo {
	public static void main(String[] args)  {
		Hashtable<String, String> ht = new Hashtable<String, String>(); // Hashtable 선언

		// 값 추가
		ht.put("1", "Hello1");
		ht.put("2", "World2");
		ht.put("3", "World3");
        
		if(ht.get("4") == null) ht.put("4", "World4");

		// Key값으로 값 제거
		ht.remove("2");

		// HashTable의 크기
		ht.size();

        	// for문을 사용하여 HashTable의 값 출력 
		for(Map.Entry<String, String> e : ht.entrySet())
			System.out.println("Key : " + e.getKey() + ", Value : " + e.getValue());

        	//  전부 제거
		ht.clear();
		System.out.println(ht); // 결과출력
	}
}
```

### HashTable 기술 인터뷰 사례
- 두 배열에서 같은 숫자를 찾는다면, 정성적으로 아래와 같은 2중 for문을 구현할 것이다.
![2중for문](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/HashTable-Interview1.png?raw=true)
- 만약 5를 찾는다면 11번이나 for문을 돌아야하는데, 이는 굉장히 비효율적이다.
- 만약 HashTable로 구현했다면 시간복잡도는 보다 단순해진다.
![해시테이블로 구현](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/HashTable-Interview2.png?raw=true)
- O(1)이 모여서 O(n)이 되는데, 이는 2중 for문을 배회하는 것보다 훨씬 빠르다.
- 실제로 코드로 구현한다면 아래와 같을 것이다.
![해시테이블 코드](https://github.com/Astrid-DM/Algorithms/blob/master/Structure/images/HashTable-Interview3.png?raw=true)
