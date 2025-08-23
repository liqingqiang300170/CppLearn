#include<iostream>
#define Pi 3
using namespace std;
class Circle
{   
    public:
        double R;

        double getS();
        double getC();
    
    private:
        double S = -1.0;
};
double Circle::getS()
{
    if (S != -1.0)
    {
        return S;
    }
    else 
    {
        S = Pi * R * R;
        return S;
    }
} 

double Circle::getC()
{
    double a = Pi * R * 2;
    return a;
}

int main()
{
    Circle circle1;
    circle1.R = 2.0;
    double b = circle1.getS();
    cout<< b << endl;

    system("pause");

    return 0;
}