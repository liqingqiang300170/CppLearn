#include <iostream>
using namespace std;

class Box
{
    public:
        double length;   // 长度
        double breadth;  // 宽度
        double height;   // 高度
        // 成员函数声明
        double get(void);
        void set( double len, double bre, double hei );
    protected:
        double volume;
        double calculateVolume();
        double s;
    

};
// 成员函数定义
double Box::calculateVolume()
{
    double vol = length * breadth * height;
    return vol;
}
double Box::get(void)
{
    volume = calculateVolume();
    return volume;
}
void Box::set( double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}
int main( )
{
   Box Box1;        // 声明 Box1，类型为 Box
   Box Box2;        // 声明 Box2，类型为 Box
   Box Box3;        // 声明 Box3，类型为 Box
   double volume = 0.0;     // 用于存储体积
    
    // box 1 详述
    Box1.height = 5.0; 
    Box1.length = 6.0; 
    Box1.breadth = 7.0;
    
    // box 2 详述
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;
    
    // box 1 的体积
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "aaa" << volume <<endl;
    
    // box 2 的体积
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "bbb" << volume <<endl;
    
    
    // box 3 详述
    Box3.set(16.0, 8.0, 12.0); 
    volume = Box3.get(); 
    cout << "ccc" << volume <<endl;

    Box box4;
    box4.set(3.0, 4.0, 5.0);
    // double vol = box4.calculateVolume();
    // cout << box4.s << endl;
    
    return 0;
    }