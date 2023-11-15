#include <iostream>

using namespace std;

class Complex{
    private:
        int real;
        int img;
    public:
        void setReal(int _r){
            real=_r;
        }
        Complex(int x=0, int y=0){
            real=x;
            img=y;
        }
        //overload_operator "+"
        Complex operator + (Complex const&obj){
            Complex res;
            res.real = real + obj.real;
            res.img = img + obj.img;
            return res;
        }
        //overload_operator "-"
        Complex operator - (Complex const&obj){
            Complex res;
            res.real = real - obj.real;
            res.img = img - obj.img;
            return res;
        }
        //overload_operator "+="
        void operator += (Complex const&obj){
            real = real + obj.real;
            img = img + obj.img;
        }
        //overload_operator "++" prefix
        void operator ++ (void){
            real = real + 1;
            img = img + 1;
        }
        //overload_operator "++" postfix
        Complex operator ++ (int){
            Complex obj = *this;
            real = real + 1;
            img = img + 1;
            return obj;
        }
        //overload conversion operator(float)
        operator float()const{
            return (float)real;
        }
        void print(void){
            cout<<real<<"+"<<img<<"j"<<endl;
        }
        //overloaded (<<) operator
        friend ostream &operator <<(ostream &out, Complex &c);
        //overloaded (>>) operator
        friend istream &operator >>(istream &in, Complex &c);
        //overload ([ ])
        int operator [](string index){
          if("real"==index){
            return real;
          }
          else{
            return img;
          }
        }
};//end class

//overloaded (<<) operator
ostream &operator <<(ostream &out, Complex &c){
    out<<c.real<<"+"<<c.img<<"j"<<endl;
    return out;
}
//overloaded (>>) operator
istream &operator >>(istream &in, Complex &c){
    cout<<"Enter the real number"<<endl;
    in>>c.real;
    cout<<"Enter the img number"<<endl;
    in>>c.img;
    return in;
}
int main()
{
    //"+" operator
    cout<<"result after using(+):"<<endl;
    cout<<endl;
    Complex c(5,6);
    Complex c1(2,3);
    Complex result(0,0);
    result = c+c1;
    result.print();
    cout<<endl;
    //"-" operator
    cout<<"result after using(-):"<<endl;
    cout<<endl;
    Complex result1(0,0);
    result1 = c-c1;
    result1.print();
    cout<<endl;
    //"+=" operator
    cout<<"result after using(+=):"<<endl;
    cout<<endl;
    c +=c1;
    c.print();
    cout<<endl;
    //"++" operator prefix
    cout<<"result after using(++) prefix:"<<endl;
    cout<<endl;
    ++c;
    c.print();
    cout<<endl;
    //"++" operator postfix
    cout<<"result after using(++) postfix:"<<endl;
    cout<<endl;
    c1=c++;
    c1.print();
    cout<<endl;
    //"float" operator
    cout<<"result after using(float):"<<endl;
    cout<<endl;
    float x= (float) c1/3;
    cout<<x<<endl;
    cout<<endl;
    //(<<) operator
    cout<<"result after using(<<):"<<endl;
    cout<<endl;
    cout<<c;
    cout<<endl;
    //(>>) operator
    cout<<"result after using(>>):"<<endl;
    cout<<endl;
    //cin>>c;
    c.print();
    cout<<endl;
    //([ ]) operator
    cout<<"result after using([ ]):"<<endl;
    cout<<endl;
    Complex arr(10,20);
    cout<<arr["real"]<<" "<<arr["img"]<<endl;
    cout<<endl;
    return 0;
}
