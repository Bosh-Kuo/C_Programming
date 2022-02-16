[array.c](file:/Users/bosh/Desktop/C:C++/C/Array/array.c):基本陣列知識  
[bubble_sort.c](file:/Users/bosh/Desktop/C:C++/C/Array/bubble_sort.c):bubble sort實作  
[multi_dimension_address.c](file:/Users/bosh/Desktop/C:C++/C/Array/multi_dimension_address.c): 多維陣列

### **sizeof()運算子**
sizeof() 運算子用於任何資料型別，如 int、float、char 等基元，也用於 array、struct，它返回分配給該資料型別的記憶體。
``` C
#include <stdio.h> 
int main(void) 
{ 
    printf("Size of char data type: %u\n",sizeof(char)); 
    printf("Size of int data type: %u\n",sizeof(int)); 
    printf("Size of float data type: %u\n",sizeof(float)); 
    printf("Size of double data type: %u\n",sizeof(double)); 
    
    return 0; 
}
```

```
Size of char data type: 1
Size of int data type: 4
Size of float data type: 4
Size of double data type: 8
```

---
### **記憶體位置(一維陣列)**
用`&i`印出變數i的記憶體位置  
`%p`對應的資料型別為pointer，即為`十六進位的記憶體位置`    
`int array[5]`中，`array`為陣列的起始位址，型別為pointer，等同於`&array[0]`

---
### **記憶體位置(多維陣列)**
```C
#include<stdio.h>
int main()
{
    int multi_array[2][3][4];
    printf("sizeof multi_array[0][0][0]: %d\n", sizeof(multi_array[0][0][0]));
    printf("sizeof multi_array[0][0]: %d\n", sizeof(multi_array[0][0]));
    printf("sizeof multi_array[0]: %d\n", sizeof(multi_array[0]));
    printf("sizeof multi_array: %d\n", sizeof(multi_array));

    return 0;
}
```

```
sizeof multi_array[0][0][0]: 4
sizeof multi_array[0][0]: 16
sizeof multi_array[0]: 48
sizeof multi_array: 96
```
同一維陣列概念：  
`multi_array`為三維陣列的起始位置，等同於`&multi_array[0][0][0]`  
`multi_array[i]`為三維陣列的起始位置，等同於`&multi_array[i][0][0]`  
`multi_array[i][j]`為三維陣列的起始位置，等同於`&multi_array[i][j][0]`  