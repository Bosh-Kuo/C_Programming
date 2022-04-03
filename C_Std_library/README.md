## **qsort**

函式原型：

```C
void qsort(void *base, int num, int size, int(*compare)(const void*, const void*))
```

`qsort` 是 standard library 提供的排序函式  
`qsort` 能快速排序給定的`陣列`，也能排序使用者自定的資料類別

- `base`: 想要排序的陣列啟示位址
- `num`: 想要排序的陣列元素數目
- `size`: 想要排序的列元素大小（以位元組計算大小）
- `compare`: 比較函數的指標

我們必須告訴 `qsort` 要如何比較兩筆資料間的大小，因此要寫一個 `compare` 函式，將這個函式用`函式指標`的方式傳給 `qsort`作為第四個參數。

compare(const void*, const void*)的兩個參分別指向要比較的兩個資料，因為事前不知道要比較的資料型態，因此用 `void*`，函式回傳值代表比較結果。如果第一個回傳值比較小就回傳負數；如果兩資料一樣大就回傳0；如果第一個回傳值比較大就回傳正數。

> 由於 void 無資料型別，因此在 compare 函式中必須將指標轉型(cast)為整數指標才能取值（和處理 malloc的回傳值情形相同）