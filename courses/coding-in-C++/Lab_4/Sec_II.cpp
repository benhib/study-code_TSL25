#include <string>
#include <iostream>

constexpr double PI = 3.1415;

class Shape{
    public:
        virtual double area() const =0;

        virtual ~Shape() {

        }
};

/*
this function should be virtual, as there will be derived classes that will have a different way to calculate
their area, but will use the same method name.

As it is now an abstract class a virtual deconstructor would make sense, because you may use a pointer and 
otherwise there will be memory leaks if there is allocated data

override makes sense, as it checks during compilation if the function is actually overriden, or just a new one

*/

class Circle : public Shape {
    private:
        double radius;

    public:
        double area() const override {
            return PI * radius*radius;
        }

        Circle(double radius) : radius(radius) {};
};

class Rectangle : public Shape {
    private:
        double length;
        double width;
    
    public:
        double area() const override {
            return length * width;
        }

        Rectangle(double length, double width) : length(length), width(width) {};
};


int main() {

    Rectangle rect = Rectangle(5.0, 2.5);
    Circle circ = Circle(10.0);

    std::cout << "Area of Cirle: " << circ.area() << std::endl;
    std::cout << "Area of Rectangle: " << rect.area() << std::endl;


    Shape* shapes[4];

    shapes[0] = new Rectangle(1.0, 2.0);
    shapes[1] = new Circle(3.0);
    shapes[2] = new Rectangle(3.0, 2.0);
    shapes[3] = new Circle(1.0);

    for (int i = 0; i < 4; i++) {
        std::cout << "Area: " << shapes[i]->area() << std::endl;
    }
    

    // cleanup
    for (int i = 0; i < 4; i++) {
        delete shapes[i];
    }
    
    return 0;
}

/*
the method area() automatically calls the correct method/calculation for the meant object

this is because a base class pointer and the virtual keyword is used

making Shape abstract by removing the default return value of area and putting "=0;" at the end

now Shape is abstract and every derived class must override it in order to create an object of that class
the code still runs fine, as Circle and Rectangle override the area() function

1. virtual makes the function call decide on runtime which function to use.
    it decides this based of the object it is called from

2. overriding replaces the function for this class
    overloading adds mutiple functions with the same name but different parameters

3. a purely virtual function is like a blueprint and makes a class abstract.
    you cannot instance a class with a purely virual function.
    is makes shure every derived class has this function 

4. if you have classes with the same parent class, that have the same function name, but the implementation
    is different.
*/