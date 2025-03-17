//alencryenfo
// 本代码实现了稀疏矩阵的加法，采用行逻辑链接表存储方式。解决问题：给定两个维数相同的稀疏矩阵，计算它们的和，并存入新的稀疏矩阵中。
#include <iostream>
#include <cstdlib>
#define MAXSIZE 20000
#define OK 1
#define ERROR 0

// 定义三元组结构体，存储非零元素的行号、列号和数值
typedef struct {
    int i, j;
    int elem;
} Triple;

// 定义行逻辑链接稀疏矩阵结构体
typedef struct {
    Triple data[MAXSIZE];  // 存储非零元素的数组
    int mu, nu, tu;        // 行数、列数、非零元素个数
    int rpos[MAXSIZE];     // rpos[i]存储第i行第一个非零元素在data数组中的位置，rpos[mu]为总数
} RLSMatrix;

// 稀疏矩阵加法函数，计算 C = A + B
int AddSMatrix(RLSMatrix A, RLSMatrix B, RLSMatrix *C) {
    // 检查两个矩阵的维数是否相同
    if (A.mu != B.mu || A.nu != B.nu) return ERROR;

    C->mu = A.mu;
    C->nu = A.nu;
    C->tu = 0;
    C->rpos[0] = 0;  // 初始化第一行起始位置

    // 对每一行分别进行加法操作
    for (int row = 0; row < A.mu; ++row) {
        int a = A.rpos[row];         // A矩阵当前行第一个非零元素位置
        int b = B.rpos[row];         // B矩阵当前行第一个非零元素位置
        int index = C->tu;           // 当前行在C->data中写入的起始下标

        // 假设每行的结束位置由rpos[row+1]给出
        while (a < A.rpos[row + 1] && b < B.rpos[row + 1]) {
            if (A.data[a].j < B.data[b].j) {
                C->data[index++] = A.data[a++];
            } else if (A.data[a].j > B.data[b].j) {
                C->data[index++] = B.data[b++];
            } else {  // 同一位置，元素相加
                C->data[index] = A.data[a];
                C->data[index].elem += B.data[b].elem;
                index++;
                a++;
                b++;
            }
        }
        // 将当前行剩余的非零元素直接复制
        while (a < A.rpos[row + 1]) {
            C->data[index++] = A.data[a++];
        }
        while (b < B.rpos[row + 1]) {
            C->data[index++] = B.data[b++];
        }
        C->tu = index;              // 更新总非零元素个数
        C->rpos[row + 1] = C->tu;     // 记录下一行的起始位置
    }

    return OK;
}

// 测试主函数
int main() {
    RLSMatrix A, B, C;
    // 假设矩阵A和B均为3x3矩阵，手动初始化rpos数组和data数组
    A.mu = B.mu = 3;
    A.nu = B.nu = 3;

    // 初始化矩阵A
    A.tu = 3;
    A.rpos[0] = 0; A.rpos[1] = 1; A.rpos[2] = 2; A.rpos[3] = 3;
    A.data[0] = {0, 0, 5};
    A.data[1] = {1, 1, 3};
    A.data[2] = {2, 2, 7};

    // 初始化矩阵B
    B.tu = 3;
    B.rpos[0] = 0; B.rpos[1] = 1; B.rpos[2] = 2; B.rpos[3] = 3;
    B.data[0] = {0, 1, 2};
    B.data[1] = {1, 1, 4};
    B.data[2] = {2, 0, 6};

    // 调用加法函数
    if (AddSMatrix(A, B, &C) == ERROR) {
        std::cout << "矩阵维数不匹配，无法相加！" << std::endl;
        return 0;
    }

    // 输出结果矩阵C的非零元素
    std::cout << "矩阵加法结果C的非零元素列表:" << std::endl;
    for (int i = 0; i < C.tu; i++) {
        std::cout << "(" << C.data[i].i << ", " << C.data[i].j << ", " << C.data[i].elem << ")\n";
    }
    return 0;
}
