#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    void input()
    {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }
    Complex add(const Complex &other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    void display() const
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    Complex num1, num2, result;

    cout << "Enter first complex number:" << endl;
    num1.input();
    cout << "Enter second complex number:" << endl;
    num2.input();
    result = num1.add(num2);
    cout << "The sum of the two complex numbers is: ";
    result.display();

    return 0;
}