### 문자열
---
#### Char to String
1번 : toString()
``` java
char c = 'a';
String str = c.toString(); // str = "a"
```
<br>

2번 : "" 더해주기

``` java
char c = 'a';
String str = ch + "";
```

<br>

### 문자열을 숫자로 변환

``` java
String str = new String("1234");
int num = Integer.parseInt(str);
```

### 문자를 숫자로 변환
``` java
char c1 = '9';
int i = c1 - '0'; // 57 - 48 = 9;
```

#### 특정 위치 문자열 가져오기
``` java
String input = "안녕하세요"
char c = input.charAt(0); // c = "안"
```

### 문자열 비교
---
``` java

// 1. 문자열의 비교

String str = "abcd"; // 1) 비교대상에 문자열이 포함되어있을 경우 -> 문자열 길이의 차이값을 리턴
System.out.println( str.compareTo("abcd") ); // 0 (같은 경우는 숫자나 문자나 0을 리턴) 
System.out.println( str.compareTo("ab") ); // 2
System.out.println( str.compareTo("a") ); // 3 
System.out.println( str.compareTo("c") ); // -2 // 첫 번째 위치에서 비교에 실패했으므로, "a"와 "c"의 아스키코드 차이 반환
System.out.println( "".compareTo(str) ); // -4 

// 2) 비교대상과 전혀 다른 문자열인 경우 
System.out.println( str.compareTo("zefd") ); // -25 
System.out.println( str.compareTo("zEFd") ); // -25 
System.out.println( str.compareTo("ABCD") ); // 32


// 2. 숫자의 비교

Integer x = 3; 
Integer y = 4; 
Double z = 1.0; 

System.out.println( x.compareTo(y) ); // -1 기준값이 비교대상보다 작음
System.out.println( x.compareTo(3) ); // 0 기준값이 비교대상과 동일함
System.out.println( x.compareTo(2) ); // 1 기준값이 비교대상보다 큼
System.out.println( z.compareTo(2.7) ); // -1
```

### 문자열 자르기
``` java
//예제
String str = "ABCDEFG"; //대상 문자열
/*A=0 B=1 C=2 D=3 E=4 F=5 G=6의 index를 가진다.*/
		
str.substring(3); 
/*substring(시작위치) 결과값 = DEFG*/
 
str.substring(3, 6); 
/*substring(시작위치,끝위치) 결과값 = DEF*/
```

### 문자열을 잘라서 배열에 저장

``` java
String str = "a.b.c";
String str2 = "010-1111-1111";

String[] strArr = str.split("\\."); // '.'을 기준으로 자르려면 이렇게 해야함
String[] strArr2 = str2.split("-");    
```

### 문자열 변환 
``` java
inputString.replaceAll("[!?'.,;]", ""); // [] 내부에있는 특수기호는 모두 제거
inputString,replace("!?',;\\.", "") // !?',;.를 하나의 문자열로 인식헤서 제거
```

### 문자열의 대소문자 변환
``` java
String str = "Abc";
str.toUpperCase(); // 대문자
str.toLowerCase(); // 소문자
```


#### 문자열을 거꾸로 더해주기
``` java
StringBuilder str = new StringBuilder("DM");
str.insert(0, "Hi!");
System.out.println(str); // Hi! DM
```
단, 코테에서 문자열 반환시 toString() 필요

+ 문자열 참고 자료 : https://java119.tistory.com/106
+ String과 StringBuilder 관련 메서드 : https://codevang.tistory.com/121

### 문자열의  공백 제거
``` java
String str = " 문자열에 공백이 있습니다. ";
System.out.println(str); // " 문자열에 공백이 있습니다. "

str = str.trim();
System.out.println(str); // "문자열에 공백이 있습니다."
``` 
- 맨 왼쪽, 맨 오른쪽 공백을 제거해줌
- 문자열 사이에있는 공백은 replace를 통해 따로 진행해줘야함

### 문자열을 char[]로  변환
---
``` java
char[] chars = s.toCharArray();

// chars를 문자열로 변환
String temp = String.valueOf(chars);

```

### 문자열 정렬
---
``` java
char[] arr = s.toCharArray();
Arrays.sort(arr);
String res = new String(arr);

// [AS-IS] "BAC" -> [TO-BE] "ABC"

```

### 문자열에 특정 문자열의 존재 여부 
---
``` java
String str = "my java test"; 
System.out.println( str.contains("java") ); // true 
System.out.println( str.contains(" my") ); // false
```

- 시간복잡도 : `O(n)`
- 공간복잡도 : `O(1)``

### Char값이 문자인지 판단
---
``` java
System.out.println(Character.isLetter('a')); // true
System.out.println(Character.isLetter('7')); // false
```

### 문자열에서 특정 문자열이 존재할 경우, 해당 문자열의 인덱스 반환
---
``` java
String str = "sadbutsad";
System.out.println( str.indexOf("sad") ); // 0 반환
// 해당 문자열이 존재하지 않을 경우, -1 반
```

- 시간복잡도 : `O(n)`
- 공간복잡도 : `O(1)`

### 배열
---
복사
- 깉은 복사 (메모리 공간을 서로 확보) : 복사된 배열이나 원본 배열이 변경될 때 서로 영향 X
- 얕은 복사 : 복사된 배열이나 원본 배열이 변경될 때 서로 영향 O
``` java
// 얕은 복사
int[] b = a;
// 깊은 복사
int[] c = a.clone();
```


### 정렬
---
#### 역정렬 (내림차순)
``` java
Arrays.sort(arr, Collections.reverseOrder());
```

### 2차원 배열 정렬
``` java
// 첫 번째 원소 기준, 오름차순 정렬
Arrays.sort(intervals, (o1, o2) -> {
return o1[0]-o2[0];
});

// 첫 번째 원소 기준, 내림차순 정렬
Arrays.sort(intervals, (o1, o2) -> {
return o2[0]-o1[0];
});

// 두 번째 원소 기준, 오름차순 정렬
Arrays.sort(intervals, (o1, o2) -> {
return o1[1]-o2[1];
});
```

### 숫자
---
#### 절대값 구하기
``` java
int temp = Math.abs(originNumber);
```

#### 정수의 최대값, 최소값
``` java
static int Integer.MAX_VALUE;
static int Integer.MIN_VALUE;
```

### int To integer
``` java
Integer.valueOf(intValue);
```
