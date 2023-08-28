#include<iostream>
using namespace std;

class Operation;

class Complex
{
    private:
        int real;
        int imaginary;
    public:
        Complex();
        Complex(int,int);
        void setreal(int real);
        int getreal();
        void setimg(int img);
        int getimg();
        void display();
};

class Operation
{
    public:
            static Complex add(Complex c1, Complex c2);
            static Complex sub(Complex c1, Complex c2);
};

Complex::Complex(int r,int i)
{
    real = r;
    imaginary = i;
}
void Complex::setreal(int real)
{
    this->real = real;
}
int Complex::getreal()
{
    return this->real;
}
void Complex::setimg(int img)
{
    imaginary = img;
}
int Complex::getimg()
{
    return imaginary;
}
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}
void Complex::display()
{
    cout<<"Your answer is: "<<real<<" + "<<imaginary<<"i"<<endl;
}

Complex Operation::add(Complex c1, Complex c2)
{
    int real = c1.real + c2.real;
    int img = c1.imaginary + c2.imaginary;
    Complex result(real,img);
    return result;
}
Complex Operation::sub(Complex c1, Complex c2)
{
    int real = c1.real + c2.real;
    int img = c1.imaginary + c2.imaginary;
    Complex result(real,img);
    return result;
}

int main()
{
    Complex c1,c2;
    int real,img;

    cout<<"C1 Real value: ";
    cin>>real;
    cout<<"C1 Img value: ";
    cin>>img;
    c1.setreal(real);
    c1.setimg(img);

    cout<<endl;

    cout<<"C2 Real value: ";
    cin>>real;
    cout<<"C2 Img value: ";
    cin>>img;
    cout<<endl;
    c2.setreal(real);
    c2.setimg(img);

    Complex sum = Operation::add(c1,c2);
    Complex diff = Operation::sub(c1,c2);

    sum.display();
    diff.display();

    return 0;
}
