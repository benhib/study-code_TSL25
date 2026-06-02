#ifndef TEST_HPP
#define TEST_HPP

#include <string>
#include <iostream>
#include <cstdint>

constexpr int SIZE = 10;

class Vector2D {
    private:
        double x;
        double y;


    public:

        Vector2D(double x, double y) : x(x), y(y){};

        Vector2D(double x, double y, double scale);

        Vector2D(): x(0), y(0) {};

        void print();

        void set(double x) {
            this->x = x;
        }

        void set(double x, double y) {
            this->x = x;
            this->y = y;
        }

        double getX() const{
            return this->x;
        }

        double getY() const{
            return this->y;
        }
        

};




#endif