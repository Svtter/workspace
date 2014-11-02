PS:
===

配置
---
- 直接安装gcc即可，任何编译器基本都有openmp的支持

要点
---
- gcc不要使用`#pragma omp parallel` + `for`这种形式，会造成并行失败。
- 使用`#pragma omp parallel schedule(static, 1)`这种形式分配for任务。
- 使用`[gcc | g++] -fopenmp sourse.[c|cpp]`进行编译，否则也不会得到并行。
- 使用`omp_get_wtime()`进行计时，否则Linux下CPU时间会计算出错。
 
