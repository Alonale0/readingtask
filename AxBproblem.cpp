#include<iostream>
#include<string>
using namespace std;

class intn
{
private:
	string vu;
    public:
    void input();
    void output();
    friend intn singalprod(char,string);
    friend intn operator*(const intn&, const intn&);
    friend intn operator+(const intn&, const intn&);
    intn& operator=(const intn& b)
    {
        if (this != &b) {
            vu = b.vu;
        }
        return *this;	
    }
};

intn singalprod(char a,string b);

intn operator+(const intn& a, const intn& b)
{
    int carry = 0;
    int sum = 0;
    intn result;
    string num1 = a.vu;
    string num2 = b.vu;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }	
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;	
        }
        carry = sum / 10;
        sum = sum % 10;
        result.vu = to_string(sum) + result.vu;
    }
return result;
}

intn operator*(const intn& a, const intn& b)
{
    int prod = 0;
    intn result1;
    intn result2;
    string num1 = a.vu;
    string num2 = b.vu;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int digit=0;
    	while(j>=0)
        { 
            result1.vu="0";
            result1=singalprod(num2[j],num1);
            if(digit>0)
            {
               for(int i=0;i<digit;i++)
            {
                result1.vu=result1.vu+'0';
            } 
            }
            result2=result1+result2;
            digit++;
            j--;
        }
        while (result2.vu.size() > 1 && result2.vu[0] == '0') {
            result2.vu.erase(0, 1);
        }
        return result2;
}


int main()
{
	intn a, b, c;

	//输入
    a.input();
	b.input();

    //计算
    c=a*b;

    //输出
    c.output();

    //结束
    bool flag=true;
    while(flag)
    {
       cin>>flag;
    }
    return 0;
}

void intn::input()
{
    cin>>vu;
    cin.ignore();
    //cout<<vu.size()<<endl;
}

void intn::output()
{
    cout<<vu<<endl;
}

intn singalprod(char a,string b)
{
    int x=a-'0';
    int carry=0;
    int prod=0;
    intn result;
    int i=b.size()-1;
    while(i>=0||carry)
    {
        prod=(i >= 0 ? (b[i] - '0') : 0)*x+carry;
        carry=prod/10;
        prod=prod%10;
        result.vu=to_string(prod)+result.vu;
        i--;
    }
    return result;
}