//alencryenfo
// 本代码实现了汉诺塔问题的递归解决方案，解决问题：将n个不同大小的圆盘从一个塔移动到另一个塔，满足每次只能移动一个盘且大盘不能压小盘的规则。
#include <iostream>
using namespace std;

// 移动圆盘的函数
void move(char x, int n, char y) {
    cout << "Move disk " << n << " from " << x << " to " << y << endl;
}

// 汉诺塔递归函数：将n个圆盘从塔x移动到塔z，借助塔y
void Hanoi(int n, char x, char y, char z) {
    if (n == 1)
        move(x, 1, z);
    else {
        Hanoi(n - 1, x, z, y);
        move(x, n, z);
        Hanoi(n - 1, y, x, z);
    }
}

// 测试主函数
int main() {
    int n = 3;  // 圆盘数
    Hanoi(n, 'A', 'B', 'C');
    return 0;
}
