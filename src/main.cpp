#include <iostream>
#include <string>

double calculateRectangleArea(double width, double height)
{
    double area = width * height;
    return area;
}


int main()
{
  std::cout << "Rectangle area is: " << calculateRectangleArea(10, 20) << " cm^2" << std::endl;

    return 0;
}
