## 목차
1. `BubbleSort`
2. `InsertionSort`
3. `SelectionSort`
4. 시간복잡도와 공간복잡도
5. `Arrays.sort`

<br> 

### BubbleSort
``` java
public class BubbleSort {  

    public static void bubbleSort(int[] array) {  
        for(int i = array.length - 1; i > 0; i--) {  
            for(int j = 0; j < i; j++) {  
                if(array[j] > array[j+1]) {  
                    int temp = array[j];  
                    array[j] = array[j+1];  
                    array[j+1] = temp;  
                }  
            }  
        }  
    }  
  
    public static void main(String[] args) {  
        int[] myArray = {4,2,6,5,1,3};  
        bubbleSort(myArray);  
        System.out.println(Arrays.toString(myArray));  
    }  
    
}
```

<br>

### InsertionSort
``` java
public class InsertionSort {  
    public static void insertionSort(int[] array) { 
     
        for(int i=1; i<array.length; i++) {  
            int temp = array[i];  
            int j = i-1;  
            while(j > -1 && temp < array[j]) {  
                array[j+1] = array[j];  
                array[j] = temp;  
                j--;  
            }  
        }  
    }  
  
    public static void main(String[] args) {  
        int[] myArray = {4,2,6,5,1,3};  
        insertionSort(myArray);  
        System.out.println(Arrays.toString(myArray));  
    }  
  
}
```

<br>

### SelectionSort
``` java
public class SelectionSort {  
  
    public static void selectionSort(int[] array) {  
        for (int i=0; i< array.length; i++) {  
            int minIndex = 1;  
            for(int j=i+1; j<array.length; j++) {  
                if(array[j] < array[minIndex]) {  
                    minIndex = j;  
                }  
            }  
            int temp = array[i];  
            array[i] = array[minIndex];  
            array[minIndex] = temp;  
        }  
    }  
  
    public static void main(String[] args) {  
        int[] myArray = {4,2,6,5,1,3};  
        selectionSort(myArray);  
        System.out.println(Arrays.toString(myArray));  
    }  
  
}
```

<br>

### 공간복잡도와 시간복잡도
- 세 알고리즘 모두 (최악의 시나리오를 고려했을때) 시간 복잡도는 O(n^2)  
- 공간 복잡도는 O(1)  
	- 세 정렬 모두 추가적인 공간 생산없이 정렬이 이루어짐

<br>

### Array.sort()
- `DualPivotQuickSort` 사용
- 퀵소트보다 일반적으로 더 개선된 성능 제공
	- 일반적으로 퀵소트가 제일 빠르지만, 퀵소트보다 개선된 기능이니 코딩 테스트에서 사용해도 무방함

```
Best Cases : O(nlog(n))
Average Cases : O(nlog(n))
Worst Cases : O(n^2)
```
