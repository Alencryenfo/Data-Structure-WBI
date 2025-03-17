//alencryenfo
// 本代码实现了稀疏矩阵的乘法，采用行逻辑链接表存储方式。解决问题：给定两个稀疏矩阵，计算它们的乘积，并将结果存储在新的稀疏矩阵中。
#include <iostream>
#include <cstdlib>
#define MAXSIZE 20000
#define OK 1
#define ERROR 0

// 定义三元组结构体，存储非零元素的行、列和数值
typedef struct {
    int i, j;
    int elem;
} Triple;

// 定义行逻辑链接稀疏矩阵结构体
typedef struct {
    Triple data[MAXSIZE];  // 存储非零元素数组
    int mu, nu, tu;        // 行数、列数、非零元素个数
    int rpos[MAXSIZE];     // 每行第一个非零元素在data中的位置，rpos[mu]为总数
} RLSMatrix;

// 稀疏矩阵乘法函数，计算 C = A * B
int MultiSMatrix(RLSMatrix A, RLSMatrix B, RLSMatrix *C) {
    // 检查矩阵维数是否匹配（A的列数必须等于B的行数）
    if (A.nu != B.mu) return ERROR;

    C->mu = A.mu;
    C->nu = B.nu;
    C->tu = 0;

    // 对A矩阵的每一行进行处理
    for (int arow = 0; arow < A.mu; ++arow) {
        int ctemp[MAXSIZE] = {0};  // 临时数组，用于存储当前行的乘积结果（按列累加）

        // 遍历A矩阵当前行中的所有非零元素
        for (int p = A.rpos[arow]; p < A.rpos[arow + 1]; ++p) {
            int brow = A.data[p].j;  // A中当前元素所在的列号，对应B的行号
            // 遍历B矩阵中brow行的所有非零元素
            for (int q = B.rpos[brow]; q < B.rpos[brow + 1]; ++q) {
                // 累加乘积到ctemp数组对应的列位置
                ctemp[B.data[q].j] += A.data[p].elem * B.data[q].elem;
            }
        }
        // 将当前行中非零的乘积结果存入C矩阵
        for (int ccol = 0; ccol < C->nu; ++ccol) {
            if (ctemp[ccol] != 0) {
                C->data[C->tu].i = arow;
                C->data[C->tu].j = ccol;
                C->data[C->tu].elem = ctemp[ccol];
                ++C->tu;
            }
        }
    }
    return OK;
}

// 测试主函数
int main() {
    RLSMatrix A, B, C;
    // 假设矩阵A为3x3，矩阵B为3x2，手动初始化rpos数组和data数组
    A.mu = 3; A.nu = 3;
    B.mu = 3; B.nu = 2;

    // 初始化矩阵A
    A.tu = 4;
    A.rpos[0] = 0; A.rpos[1] = 2; A.rpos[2] = 3; A.rpos[3] = 4;
    A.data[0] = {0, 0, 2};
    A.data[1] = {0, 2, 3};
    A.data[2] = {1, 1, 4};
    A.data[3] = {2, 0, 5};

    // 初始化矩阵B
    B.tu = 4;
    B.rpos[0] = 0; B.rpos[1] = 1; B.rpos[2] = 3; B.rpos[3] = 4;
    B.data[0] = {0, 0, 1};
    B.data[1] = {0, 1, 2};
    B.data[2] = {1, 0, 3};
    B.data[3] = {2, 1, 4};

    // 调用乘法函数
    if (MultiSMatrix(A, B, &C) == ERROR) {
        std::cout << "矩阵维数不匹配，无法相乘！" << std::endl;
        return 0;
    }

    // 输出结果矩阵C的非零元素
    std::cout << "矩阵乘法结果C的非零元素列表:" << std::endl;
    for (int i = 0; i < C.tu; i++) {
        std::cout << "(" << C.data[i].i << ", " << C.data[i].j << ", " << C.data[i].elem << ")\n";
    }
    return 0;
}
