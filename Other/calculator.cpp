#include<iostream>
using namespace std;
class calculator {
    double x;
    double y;
public:
    calculator () {
        
    }
    void setter(double &x, double &y) {
        this->x=x;
        this->y=y;
    }
    void sum();
    void multiply ();
    void divide();
    void subtraction ();
    void result (const string &s);

};
void calculator::sum() {

    result ("sum");
}
void calculator::multiply () {

    result ("multiply");
}
void calculator::divide() {

    result ("divide");
}
void calculator::subtraction() {

    result ("subtraction");
}
void calculator::result (const string &s) {
    if(s=="sum") {
        cout<<this->x+this->y<<endl;
    }
    else if(s=="multiply") {
        cout<<this->x*this->y<<endl;
    }
    else if(s=="divide") {
        cout<<this->x/this->y<<endl;
    }
    else {
        cout<<this->x-this->y<<endl;
    }
}
int main()
{
    char a='y';
    while(a=='y') {
        double x;
        double y;
        


        char option;
        cout<<"press '+' for sum, '*' for multiply"<<endl;
        cout<<"press '/' for divide, '-' for subtraction"<<endl;
        cin>>option;

        calculator* v1=new calculator();

        if(option=='+')
        {
            cout<<"enter first number : ";
            cin>>x;
            cout<<"enter second number : ";
            cin>>y;
            //   calculator* v1=new calculator(x, y);
            v1->setter(x,y);

            v1->sum();
        }
        else if(option=='*')
        {
            cout<<"enter first number : ";
            cin>>x;
            cout<<"enter second number : ";
            cin>>y;
            v1->setter(x,y);
            v1->multiply();
        }
        else if(option=='-') {
            cout<<"enter first number : ";
            cin>>x;
            cout<<"enter second number : ";
            cin>>y;
            v1->setter(x,y);
            v1->subtraction();
        }
        else if(option=='/') {
            cout<<"enter first number : ";
            cin>>x;
            cout<<"enter second number : ";
            cin>>y;
            v1->setter(x,y);
            v1->divide();
        }
        else {
            cout<<"invalid choice "<<endl;
          //  break;
        }
        delete v1;
        cout<<"continue or not : (y/n)"<<endl;

        cin>>a;


    }
    return 0;
}