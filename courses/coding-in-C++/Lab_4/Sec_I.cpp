#include <iostream>
#include <cmath>

class Vector2D {
    private:
        double x, y;
    
    public:
        Vector2D(double x, double y) : x(x), y(y) {}

        Vector2D() : x(0), y(0) {}

        double getX() const{
            return this->x;
        }

        double getY() const{
            return this->y;
        }

        void print() const{
            using namespace std;
            cout << "X: " << x << endl;
            cout << "Y: " << y << endl;
        }

        double getLength() const{
            double value = sqrt( x*x + y*y); //Pythagorean theorem
            return value;
        }

        double getLength(int precision) const{
            double factor = std::pow(10.0, precision);
            double value = this->getLength();
            return std::round(value * factor) / factor;
        }

        void operator+= (Vector2D& vec) {
            this->x = this->x + vec.x;
            this->y = this->y + vec.y;
        }

        
};

    Vector2D operator+ (const Vector2D& vec1, const Vector2D& vec2) {
            return Vector2D(vec1.getX() + vec2.getX(), vec1.getY() + vec2.getY());
        }

    Vector2D operator* (const double skal,const  Vector2D& vec) {
        return Vector2D(skal * vec.getX(), skal * vec.getY()) ;
    }

    Vector2D operator* (const Vector2D& vec, const double skal){
        return skal * vec;
    }


int main() {
    Vector2D vec1 = Vector2D(1.5, 2.5);
    Vector2D vec2 = Vector2D(3.4, 4.3);

    Vector2D vecadd = vec1 + vec2;
    vecadd.print();

    Vector2D vecmult = 2.0 * vec2;
    vecmult.print();

    vec1 += vec2;

    vec1.print();

}