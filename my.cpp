#include <iostream>
using namespace std;
bool canbobwin(int BobX, int BobY, string path,int Nsec)
{
    int alicex = 0, alicey = 0;
 
    int length = path.length();
    for (int i = 0; i < length; i++)
    {
        if (path[i] == 'R'){
            ++alicex;
        }
        else if(path[i] == 'L'){
            --alicex;
        }
        else if(path[i] == 'U'){
            ++alicey;
        }
        else{
            --alicey;
        }
    }
    int sum=(BobX-alicex)+(BobY-alicey);
    if(sum==Nsec){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int bobx = 1, bobY = 1;
    int Nsec=3;
    string path = {"DUL"};

    if (canbobwin(bobx, bobY, path,Nsec))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}