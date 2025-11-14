# 编译器压力测试说明

## 📋 测试文件

### 1. `stress_test_compatible.c` ✅ 完全兼容
使用当前编译器已支持的所有功能：
- ✅ 变量声明和赋值
- ✅ 比较运算符 (`>`, `<`)
- ✅ if-else 语句
- ✅ while 循环
- ✅ 数组操作
- ✅ 算术运算 (`+`, `-`)
- ✅ print 输出

**运行方法：**
```bash
./minicompiler stress_test_compatible.c stress_test_compatible.s
```

**测试内容：**
1. **比较测试**: `a > b` (a=1, b=5) → 应输出 0
2. **嵌套循环**: while + if 嵌套，测试多个变量比较
3. **数组排序**: 冒泡排序的简化版本

---

### 2. `stress_test_full.c` ✅ 功能增强版
包含更复杂的逻辑：
- 逻辑运算模拟（使用嵌套 if）
- 更复杂的控制流
- 字符输出模拟（ASCII 码）

**运行方法：**
```bash
./minicompiler stress_test_full.c stress_test_full.s
```

---

## 🔍 原始需求 vs 当前实现

### 原始代码中的功能：

#### ❌ **不支持的功能（需要添加）：**
```c
write(a > b);              // write() 函数 → 使用 print()
write('r');                // 字符字面量 → 使用 ASCII: print(114)
(a > b) * (c > d)          // 逻辑与运算 → 需要实现 && 运算符
writeln;                   // 换行函数 → 当前 print() 自动换行
swap(x, x+1);              // 函数调用 → 需要实现函数
num[x+1]                   // 数组下标表达式 → 需要临时变量
```

#### ✅ **已支持的功能：**
```c
int a;                     // ✅ 变量声明
a = 1;                     // ✅ 赋值
a > b                      // ✅ 比较运算符
while (condition) { }      // ✅ while 循环
if (condition) { }         // ✅ if 语句
num[x]                     // ✅ 数组访问（简单下标）
a = a - 1;                 // ✅ 算术运算
```

---

## 🎯 测试场景

### 场景 1: 比较运算测试
```c
a = 1;
b = 5;
if (a > b) {
    print(1);  // 不会执行
} else {
    print(0);  // 应该输出: 0
}
```

### 场景 2: 嵌套循环和条件
```c
a = 10;
b = 5;
c = 20;
d = 10;

while (a > b) {           // 循环 5 次
    if (c > d) {          // 每次都成立
        print(a);         // 输出: 10, 9, 8, 7, 6
        a = a - 1;
    }
}
```

### 场景 3: 数组操作（冒泡排序）
```c
int num[10];
num[0] = 5;
num[1] = 2;
num[2] = 8;
num[3] = 1;
num[4] = 9;

// 简化的排序逻辑
while (x < numLength) {
    if (num[x] < num[x+1]) {
        // 交换元素
        int temp = num[x];
        num[x] = num[x+1];
        num[x+1] = temp;
    }
    x = x + 1;
}

// 输出排序后的数组
print(num[0]);  // 应该是最大值
```

---

## 🔧 需要扩展的功能清单

如果要完全支持原始测试代码，需要添加：

1. **逻辑运算符**
   - `&&` (逻辑与)
   - `||` (逻辑或)
   - `!` (逻辑非) - 已部分实现

2. **字符字面量**
   - `'r'`, `'='` 等
   - 字符到 ASCII 的转换

3. **write() 和 writeln() 函数**
   - 可以作为 print() 的别名
   - writeln 输出换行

4. **函数定义和调用**
   - `swap(x, y)` 等自定义函数
   - 参数传递和返回值

5. **表达式下标**
   - `num[x+1]` 直接在下标中使用表达式
   - 当前需要：`int next = x + 1; num[next]`

---

## 📊 预期输出

### stress_test_compatible.c 预期输出：
```
0           # a=1 > b=5 的结果
10          # while 循环第1次: a
5           # b
20          # c
10          # d
9           # while 循环第2次: a
5           # b
20          # c
10          # d
... (继续输出直到 a=6)
9           # 排序后的数组
8
5
2
1
```

---

## 🚀 运行测试

```bash
# 1. 编译编译器
make clean && make

# 2. 运行兼容版测试
./minicompiler stress_test_compatible.c stress_test_compatible.s

# 3. 查看生成的 MIPS 代码
cat stress_test_compatible.s

# 4. (可选) 在 MIPS 模拟器中运行
# 使用 MARS 或 QtSPIM
```

---

## 💡 建议的测试顺序

1. **基础测试**: 先运行 `test.c` 确保数组功能正常
2. **算术测试**: 运行 `test_features.c` 测试所有运算符
3. **压力测试**: 运行 `stress_test_compatible.c` 测试复杂场景
4. **效率分析**: 查看编译器输出的效率报告

---

## 🐛 已知限制

1. **数组下标**: 不支持 `arr[i+1]`，需要临时变量
2. **逻辑运算**: `(a > b) * (c > d)` 不支持，用嵌套 if 代替
3. **字符**: 不支持 `'c'`，用 ASCII 码代替: `print(99)`
4. **函数**: 不支持自定义函数如 `swap()`
5. **复杂表达式**: 某些复杂的嵌套表达式可能需要拆分

---

**测试愉快！** 🎉
如有任何编译错误，请查看错误信息并调整代码。
