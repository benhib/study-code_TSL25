#include <string>
#include <iostream>

class User {
    protected:
        std::string name;
        int id;
    public:
        User(std::string name, int id) : name(name), id(id) {};
    

        void printInfo() {
            std::cout << "Name: " << name << std::endl;
            std::cout << "ID: " << id << std::endl;
        }
};

class Student : public User {
    private:
        float grade;

    public:
        Student(std::string name, int id) : User(name, id) {grade = 0;};

        void setGrade(float grade) {
            this->grade = grade;
        }

        void printRole() {
            std::cout << "Role: Student\n";
            printInfo();
            std::cout << "Grade: " << grade << std::endl;
        }
        
};

class Instructor : public User {
    private:
        float rating;
    
    public:
        Instructor(std::string name, int id) : User(name, id) {rating = 0;};

        void setRating(float rating) {
            this->rating = rating;
        }

        void printRole() {
            std::cout << "Role: Instructor\n";
            printInfo();
            std::cout << "Rating: " << rating << std::endl;
        }
};

int main() {
    Student student =  Student("Student", 0);
    Instructor in = Instructor("Dr. Instructor", 1);

    student.setGrade(3.1);

    in.setRating(7.3);

    std::cout << "printInfo(): \n";

    student.printInfo();
    in.printInfo();
    

    std::cout << "printRole(): \n";
    student.printRole();
    
    in.printRole(); 

    
}

