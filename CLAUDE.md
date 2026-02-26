# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

LeetCode C++ 算法题解集合，使用 clang 编译器和 C++14 标准。

## Build & Run

编译单个文件：
```bash
clang++ -std=c++14 -o <output> <file>.cpp
./<output>
```

部分文件包含 `main()` 函数和测试代码，可直接编译运行验证。

## Code Structure

代码按算法类型组织：
- `binary-search/` - 二分查找相关题目
- `depth-first-search/` - 深度优先搜索相关题目
- 根目录 - 其他算法题目（动态规划、数组等）

## Conventions

- 文件命名：`<name>_<problem_id>.cpp` 或 `<id>.<chinese_name>.cpp`
- 使用 LeetCode 标准 `Solution` 类模板
- 部分文件使用 LeetCode Code 插件的 `@lc` 注释格式
