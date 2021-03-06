## **遞迴**

> 遞迴就是用自己來定義自己，比如：如果k是自然數，那k+1也是自然數，在回答k+1是否為自然數這個問題時我們並沒有正面回答，而是把問題轉為k是否為自然數這個問題。

會呼叫自己的函數式就稱為`遞迴函式`

- 終端條件：遞迴到某一成度必須停止遞迴下去的條件
- 遞迴公式：說明如何定義自己，如：如果k是自然數，那k+1也是自然數


---

## **最大公因數**

gcd(i,j) =   
1. `j`, if i mod j = 0
2. `gcd(j,i mod j)`, otherwise

--- 

## **河內塔**
一開始有A,B,C三個石柱子以及n個不同大小的石盤，一開始都串在A柱上，如何將所有石盤都從A柱移到C柱

- 終端條件：如果n是1，直接將1個石盤由A柱移至C柱
- 遞迴公式：
  - 利用C柱子做緩衝區將n-1個石盤由A柱移到B柱
  - 將1個石盤移到C柱
  - 利用A柱子做緩衝區將n-1個石盤由B柱移到C柱

---

## **八后問題**
如何將八個皇后放到西洋棋盤上使得任兩個皇后不在同一行或同一列或斜對角上。我們可以用`queen_pos[8]`來儲存吧齁問題的一個解，queen_pos[i]的值代表第i行皇后所在的列。

使用遞迴方法窮舉：  
先在第1行放一個皇后，在不與前一行衝突的情況於第2行放一個皇后，以此類推向下放，直到成功在不與前面衝突下在第8行放一個皇后漚找到一個解了。如果在第i行試了8個列都與前面衝突代表前面的行放錯了，那麼就退回i-1行將i-1行的皇后一到下一列，再回到i行尋找可能的位置。

- 終端條件：如果i為8表示皇后已經全部成功放完
- 遞迴公式：如果i小於8我們就嘗試第i行的8個列
  - 如果確定第i行的某一列可以放，，我們就設定queen_pos[i]，並以同樣遞迴方法在第i+1行放皇后
  - 如果i行的8個皇后都試過了就回到i-1行