//第二次提交版本
#include<iostream>
#include<string>
using namespace std;

class IN
{
private:
    string a;
public:
    void input();
    void output();
    // 友元函数，重载加法运算符
    friend IN operator +(const IN&, const IN&);
    // 赋值运算符重载，设为公有
    IN& operator =(const IN& b)
    {
        if (this != &b) {
            a = b.a;
        }
        return *this; 
    }
};

// 重载加法运算符，实现大整数加法
IN operator +(const IN& a, const IN& b)
{
    int carry = 0;
    int sum = 0;
    IN result;
    string num1 = a.a;
    string num2 = b.a;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    // 从字符串末尾开始逐位相加
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) {
            sum += num1[i--] - '0';
        }
        if (j >= 0) {
            sum += num2[j--] - '0';
        }
        carry = sum / 10;
        sum = sum % 10;
        // 将当前位的结果添加到结果字符串前面
        result.a = static_cast<char>(sum + '0') + result.a;
    }

    return result; 
}

// 输入函数，读取字符串
void IN::input()
{
    cin >> a;
    cin.ignore();
}

// 输出函数，打印字符串
void IN::output()
{
    cout << a << endl;
}

int main()
{
    IN a, b;
    // 输入
    a.input();
    b.input();

    // 调用加法运算符重载函数
    IN result;
    result = a + b;
    
    // 输出
    result.output();


    bool flag = true;
    while(flag)
    {
        cin >> flag;
    }
    return 0;
}
