#include<iostream>
#include<string>
using namespace std;

class intn
{
private:
	string vu;
public:
  intn(string);
    void input();
    void output();
    friend void gense(int,intn[]);
    friend void genout(int,intn[]);
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

intn::intn(string a="0")
{
  vu=a;
}

intn singalprod(char a,string b);

intn operator+(const intn& a, const intn& b)
{
    int carry = 0;
    int sum = 0;
    intn result("");
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
    // 去除前导零
    while (result.vu.size() > 1 && result.vu[0] == '0') {
        result.vu.erase(0, 1);
    }
    return result;
}

intn operator*(const intn& a, const intn& b)
{
    int prod = 0;
    intn result1;
    intn result2("0");
    string num1 = a.vu;
    string num2 = b.vu;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int digit=0;
    	while(j>=0)
        { 
            result1.vu="";
            result1=singalprod(num2[j],num1);
            if(digit>0)
            {
                result1.vu+=string(digit, '0');
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
	  int n=0;
    cin>>n;
    intn gen[52];
    gense(n,gen);
    intn result1("1");
    intn result2("0");
    intn q("1");
    int j=0;
    for(int i=1;i<=n;i++)
    {
      for(j=1;j<=i;j++)
        {
        result1 = result1*gen[j];
        }
      result2=result2+result1;
      result1=q;
    }
        
    result2.output();
    
    // 结束
    bool flag=true;
    while(flag)
    {
        cin>>flag;
    }
    return 0;
}
void gense(int n,intn a[52])
{
  int i=0;
  for(i=1;i<=n;i++)
   {
   a[i].vu=to_string(i);
   }
}

void genout(int n,intn a[52])
{
  int i=0;
  for(i=1;i<=n;i++)
  {
    cout<<a[i].vu<<endl;
  }
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
    intn result("");
    int i=b.size()-1;
    while(i>=0||carry)
    {
        prod=(i >= 0 ? (b[i] - '0') : 0)*x+carry;
        carry=prod/10;
        prod=prod%10;
        result.vu=to_string(prod)+result.vu;
        i--;
    }
    // 去除前导零
    while (result.vu.size() > 1 && result.vu[0] == '0') {
        result.vu.erase(0, 1);
    }
    return result;
}