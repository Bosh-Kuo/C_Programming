# **C Programs執行階段** 
``` mermaid
graph LR
    id1(Edit) --> id2(Preprocess) 
    id2 --> id3(Compile) 
    id3 --> id4(Link)
    id4 --> id5(Load)
    id5 --> id6(Execute)
```
* *1. Edit*: 編輯程式碼，即Coding
* *2. Preprocess*: C preprocessor在編譯前會先執行一些特殊指令一些特殊指令，包含包裹其他檔案已進行文本交換。  
  ex: `#include <stdio.h>`
* *3. Compile*: 編譯器將C語言程式碼編譯成機器語言程式碼。
* *4. Link*: 程式碼通常參考在其他地方的function，如standard libaries, etc. `Compiler` 編譯的objet code包含許多“missing part”，linker會連接objet code與missing functions，生成`executable image`。在Linux中compiler+link指令為`gcc`。
* *5. Loading*: `loader`將`executable image`從磁碟轉移到記憶體上。
* *6. Execution*: 最後電腦在CPU控制之下運行程式。

---

# **GCC 編譯器基本使用**
`GCC(GNU Compiler Collection)` 是開放原始碼 (open source) 的跨平台編譯器 (compiler) ，支援編譯 C 、 C++ 、 Objective-C 、 Fortran 、 Ada 及 Go 等程式語言

## **編譯與連結 C 程式**
假設編寫C程式時將程式碼存於`test.c`檔案中，若要將C的原始碼編譯成執行檔，可以執行 gcc 並指定 C 語言的原始碼檔案：
```
# 編譯 C 程式
# cd 當前目錄

gcc test.c
```

GCC 預設會執行編譯與連結，直接產生一個可以執行的程式，輸出至 `a.out` 這個檔案
```
# 執行編譯好的程式
./a.out
```

若要指定輸出的執行檔名稱，可以加上 `-o` 參數，並指定輸出的檔案名稱：
```
gcc test.c -o test
```
or
```
gcc -o test test.c
```

---

## **編譯與連結 C++ 程式**
假設編寫C程式時將程式碼存於`test.cpp`檔案中，若要編譯 C++ 的程式，可以使用 g++ 這個編譯程式，並指定 C++ 的原始碼檔案：
```
# 編譯 C++ 程式
# cd 當前目錄

g++ test.cpp
```
後續與C程式相同，差別只在編譯C++程式時，通常用g++指令編譯。

---
## **gcc 和 g++ 的聯絡和區別**
對於 C 語言或者 C++ 程式，可以通過執行 `gcc` 或者 `g++` 指令來呼叫 `GCC 編譯器`，實際使用中我們更習慣使用 `gcc` 指令編譯 `C` 語言程式，用 `g++` 指令編譯 `C++` 程式碼。  
但這並不是 gcc 和 g++ 的區別，gcc 指令也可以用來編譯 C++ 程式，同樣 g++ 指令也可以用於編譯 C 語言程式。

實際上，只要是 `GCC` 支援編譯的程式程式碼，都可以使用 `gcc` 命令完成編譯，`gcc` 指令可以自行判斷出當前程式所用程式語言的類別。但如果使用 `g++` 指令，則無論目標檔案的字尾名是什麼，該指令都一律按照編譯 `C++` 程式碼的方式編譯該檔案

- 對於 **`.c`** 檔案來說，`gcc` 指令以 C語言程式碼對待，`g++` 指令會以 C++ 程式碼對待
- 但對於 **`.cpp`** 檔案來說，`gcc` 和 `g++` 都會以 C++ 程式碼的方式編譯。

*使用 gcc 和 g++ 也是有區別的。* 很多 C++ 程式都會呼叫某些標準庫中現有的函式或者類物件，而單純的 gcc 命令是無法自動連結這些標準庫檔案的。  

**舉例: 如果使用 gcc 指令編譯此C++程式會報錯** 
```C++
//test.cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str ="hello,world";
    cout << str << endl;
    return 0;
}
```
根本原因就在於，該程式中使用了標準庫 `<iostream>` 和 `<string>` 提供的類物件，而 `gcc` 預設是無法找到它們的。
如果想使用 `gcc` 指令來編譯執行 C++ 程式，需要在使用 `gcc` 指令時，手動為其新增 **`-lstdc++`** 選項，表示 `gcc` 在編譯 C++ 程式時可以連結必要的 C++ 標準庫。
```
gcc test.cpp -lstdc++ 
```
---

# **GCC 常用指令**
## **開啟除錯與警告訊息**

`-g`可以在編譯出來的程式中加上除錯相關的資訊，
`-Wall`會開啟許多有用的警告，
```
gcc -Wall -g -o test test.c
```

---

## **只編譯不連結**
若想讓編譯器只進行編譯、不要連結，可加上 `-c` 參數，這樣就會建立一個 `object 檔`
```
# 僅編譯、不連結，建立 obj 檔案
gcc -c test.c
```

執行這行之後，就會產生一個 hello.o 檔案，後續若要進行連結
```
# 連結產生執行檔
gcc -o test test.o
```

---

## **標頭檔與函式庫路徑**
在編譯程式時，編譯器需要許多`標頭檔(\*.h 檔案)`來編譯原始碼，而連結的時候則會需要一些`函式庫(\*.a、\*.so 等)`才能進行連結，但是編譯器只會自動引入一些系統預設的檔案，在大型專案中開發者會需要指定許多額外的標頭檔與函式庫位置，這樣才能讓編譯器順利編譯與連結。

編譯器會在 include 路徑中，搜尋 C 程式碼中以 #include 所引入的標頭檔，如果需要指定額外的搜尋路徑，可以使用` -I `參數增加搜尋路徑，假設我們有一些標頭檔放在 /home/Bosh/include 目錄下，而要新增這個路徑就可以這樣寫：

```
# 新增標頭檔搜尋路徑
gcc -I/home/Bosh/include -o test test.c
```
>由於標頭檔的名稱都寫在 C 程式碼中，所以檔名都是已知的，只需要告訴編譯器路徑即可進行編譯

在連結時期所需要函式庫名稱與路徑，可以透過 GCC 的 `-l` 與 `-L` 參數來指定。在 Linux 中假設有一個 libsum.a 函式庫放在 /home/Bosh/lib 目錄下，若要將其納入連結，則可以這樣寫：

```
# 納入指定的函式庫
gcc -lsum -L/home/Bosh/lib -o test test.c
```

---

# 參考
[GCC 編譯器基本使用教學與範例-G. T. Wang](https://blog.gtwang.org/programming/gcc-comipler-basic-tutorial-examples/)  
[如何在終端機中使用 GCC (或 Clang)](https://opensourcedoc.com/c-programming/compile-c-with-gcc-or-clang/)




