//alencryenfo
// 本代码实现了稀疏矩阵的转置，采用三元组顺序表存储方式。解决问题：给定一个稀疏矩阵，计算并输出其转置矩阵。
#include <iostream>
#include <cstdlib>
#define MAXSIZE 20000
#define OK 1
#define ERROR 0

// 定义三元组结构体，用于存储非零元素的位置和数值
typedef struct {
    int i, j;       // 行号和列号
    int elem;       // 元素值
} Triple;

// 定义稀疏矩阵结构体，使用三元组数组存储
typedef struct {
    Triple data[MAXSIZE];  // 存储非零元素的数组
    int mu, nu, tu;        // 行数、列数、非零元素个数
} TSMatrix;

// 稀疏矩阵转置函数，参数M为原矩阵，T为转置后的矩阵指针
int TransposeSMatrix(TSMatrix M, TSMatrix *T) {
    int p, q, col;
    // 转置矩阵的行数和列数互换，非零元素个数保持不变
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if (T->tu) {  // 如果矩阵中存在非零元素
        q = 0;  // q为转置矩阵中当前写入的下标
        // 按原矩阵的列序扫描，将每个非零元素转置后按行存入T中
        for (col = 0; col < M.nu; ++col) {
            for (p = 0; p < M.tu; ++p) {
                if (M.data[p].j == col) {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].elem = M.data[p].elem;
                    ++q;
                }
            }
        }
    }
    return OK;
}

// 测试主函数
int main() {
    // 初始化一个3x3稀疏矩阵，包含4个非零元素
    TSMatrix M = {{{0, 0, 5}, {0, 2, 8}, {1, 1, 3}, {2, 0, 6}}, 3, 3, 4};
    TSMatrix T;

    // 调用转置函数
    TransposeSMatrix(M, &T);

    std::cout << "转置后的矩阵非零元素列表:\n";
    for (int i = 0; i < T.tu; i++)
        std::cout << "(" << T.data[i].i << ", " << T.data[i].j << ", " << T.data[i].elem << ")\n";

    return 0;
}
