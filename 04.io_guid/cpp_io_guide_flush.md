# C++ 算法竞赛 IO 速查（防 TLE 版）

## 1. 起手模板（直接复制）

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ...
    return 0;
}
```

**加了这两句后，禁止混用 `scanf/printf`。**

---

## 2. 输出：`'\n'` vs `endl` vs `flush`

### 2.1 快递发货比喻

`cout` 不是直接把字打到屏幕上，而是先放在一个**暂存柜（缓冲区）**里：

```cpp
cout << "hello";
cout << " world";
cout << '\n';
```

上面三句话只是把包裹放进暂存柜，快递员还没来。真正发货靠三种方式：

| 方式 | 效果 | 速度 |
|---|---|---|
| `'\n'` | 换行符扔进暂存柜，**不叫快递** | 快 |
| `endl` | 换行符扔进暂存柜，**立刻叫一次快递** | 慢 |
| `flush()` | 暂存柜里所有包裹一次性发走 | 按需叫 |

**endl 为什么慢？** 循环 10 万次输出，用 `endl` 就叫了 10 万次快递；用 `'\n'` 只叫 1 次（程序结束时自动发）。

### 2.2 什么时候手动 flush

一般不需要。程序 `return 0;` 时操作系统会自动把暂存柜清空。

但如果你需要**立刻看到输出**（比如交互题、调试时），就手动 `flush`：

```cpp
cout << "请输入一个数字: ";
cout.flush();           // 立刻把这行刷到屏幕，让用户看到提示

cin >> n;               // 用户此时才能看到提示并输入
```

### 2.3 完整代码例子

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 批量输出：用 '\n' 攒在缓冲区里
    for (int i = 1; i <= 5; i++) {
        cout << i << " " << i * i << '\n';   // 只放包裹，不叫快递
    }

    // 到这里缓冲区里有 5 行内容
    // 手动 flush：一次性全部发到屏幕
    cout.flush();

    // 或者程序结束时自动 flush
    return 0;
}
```

输出：
```
1 1
2 4
3 9
4 16
5 25
```

**对比反面教材（慢版）：**

```cpp
for (int i = 1; i <= 100000; i++) {
    cout << i << endl;   // 每轮都叫一次快递，10万次系统调用
}
```

---

## 3. getline：按行读取（白话版）

### 3.1 getline 是干嘛的

`cin >>` 像一个**只抓数字、见空白就停**的机器人。你输入 `hello world`，它只能抓到 `hello`，`world` 还在缓冲区里。

`getline` 像一个**整行端走**的机器人，不管里面有什么，一整行全端走：

```cpp
string line;
getline(cin, line);     // 输入 "hello world 123"
                        // line 里就是完整的 "hello world 123"
```

### 3.2 getline 和 cin >> 混用的坑

**场景**：先读一个数字，再读一行文字。

```cpp
int n;
cin >> n;               // 你输入 "5" 然后按回车
                        // cin >> 抓到 5，但缓冲区里还残留一个 \n（回车符）

string s;
getline(cin, s);        // getline 一上来就碰到那个残留的 \n
                        // 以为这是一行空内容，s 变成了 ""（空串）
```

**修复**：在 getline 之前，把那个残留的换行吃掉。

```cpp
int n;
cin >> n;
cin.ignore();           // 吃掉缓冲区里残留的换行符

string s;
getline(cin, s);        // 现在正常读到下一行
```

### 3.3 安全做法

要么全程 `cin >>`，要么全程 `getline`，不要混着来。如果必须混，记住口诀：**`cin >>` 后面跟 `getline`，中间必须插 `cin.ignore()`**。

### 3.4 从一行里拆出多个数字

```cpp
string line;
getline(cin, line);              // 端走一整行，比如 "3 5 7 9"
stringstream ss(line);           // 把这行塞进一个"小输入流"

int x;
while (ss >> x) {                // 像用 cin 一样逐个掏数字
    cout << x << " ";            // 输出 3 5 7 9
}
```

**性能提醒**：`getline` + `stringstream` 比纯 `cin >>` 慢，因为多了一道"先当字符串存再拆开"的工序。如果只是读纯数字，直接用 `cin >>`；格式复杂（数字个数不定、混着字符串）时才用 `getline`。

---

## 4. 极限快读（数据量 10^6+ 时用）

### 4.1 fread：批量把输入读进内存

```cpp
#include <cstdio>

static const int BUFSIZE = 1 << 20;   // 1MB 缓冲区
char buf[BUFSIZE];

// 从 stdin 批量读入 buf，返回实际读到的字节数
int len = fread(buf, 1, BUFSIZE, stdin);
// buf[0..len-1] 就是所有输入字符
```

### 4.2 手写解析：从字符数组里抠数字

```cpp
char buf[1 << 20];
int idx = 0, len = 0;

// 读下一个字符
inline char read() {
    if (idx >= len) {
        len = fread(buf, 1, sizeof(buf), stdin);
        idx = 0;
        if (!len) return EOF;
    }
    return buf[idx++];
}

// 从字符流里手抠一个 long long
long long readLong() {
    long long num = 0;
    char c;
    bool neg = false;
    while ((c = read()) != EOF && !((c >= '0' && c <= '9') || c == '-'));
    if (c == '-') { neg = true; c = read(); }
    for (; c >= '0' && c <= '9'; c = read())
        num = num * 10 + (c - '0');
    return neg ? -num : num;
}
```

### 4.3 fwrite：批量输出

```cpp
char outbuf[1 << 13];
int ptr = 0;

// 塞一个字符进输出缓冲区
inline void writeChar(char c) {
    outbuf[ptr++] = c;
    if (ptr >= sizeof(outbuf)) flushOut();
}

// 塞一个整数
inline void writeLong(long long x) {
    if (ptr + 21 >= sizeof(outbuf)) flushOut();
    if (x < 0) { outbuf[ptr++] = '-'; x = -x; }
    char tmp[21]; int n = 0;
    do { tmp[n++] = '0' + x % 10; x /= 10; } while (x);
    for (int i = n - 1; i >= 0; i--) outbuf[ptr++] = tmp[i];
}

// 把缓冲区内容一次性写到屏幕
inline void flushOut() {
    fwrite(outbuf, 1, ptr, stdout);
    ptr = 0;
}
```

### 4.4 使用门槛

| 数据量 | 推荐方案 |
|---|---|
| ≤ 10^5 | `cin` + 关同步（够用） |
| 10^5 ~ 10^6 | 先 `cin` 试试，TLE 再换 |
| ≥ 10^6 | 直接上 `fread`/`fwrite` |

---

## 5. 常见 TLE 坑速查

| 坑 | 后果 | 修复 |
|---|---|---|
| 忘写 `ios::sync_with_stdio(false)` | `cin` 慢 10 倍+ | 加上 |
| 循环里用 `endl` | 频繁 flush，系统调用爆炸 | 用 `'\n'` |
| `cin >>` 后直接 `getline` | 读到空行，逻辑错乱 | 中间插 `cin.ignore()` |
| 每轮 `new`/`delete` | 动态分配开销巨大 | 全局静态数组复用 |
| `vector` 频繁 `push_back` 扩容 | 反复搬家 | 一次性 `reserve(n)` |
| 关同步后混用 `scanf/printf` | 行为未定义 | 只用一套 |
