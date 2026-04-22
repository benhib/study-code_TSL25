#include <iostream>
#include <string>
#include <limits>
#include <cstdint>
#include <iomanip>
#include "report_utils.hpp"


int getAndCheckInput (std::string message) {
    bool is_entered = false;
    uint_least16_t value = 0;

    while(!is_entered) {
        std::cout << message;

        if(!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "You did not enter a number.\n";
            continue;
        }

        if(value < 0 || value > 100) {
            std::cout << "The value is out of the point range.\n";
            continue;
        }
        is_entered = true;
    }
    return value;
}

void readStudentData(std::string& name, uint_least16_t& homework, uint_least16_t& midterm, uint_least16_t& finalExam) {
    std::cout << "Student name: ";
    std::getline(std::cin >> std::ws, name);

    homework = getAndCheckInput("Homework score: ");
    midterm = getAndCheckInput("Miterm score: ");
    finalExam = getAndCheckInput("Final exam score: ");
}

void calculateGrade(const uint_least16_t& homework, const uint_least16_t& midterm, const uint_least16_t& finalExam, 
                    double& finalGrade, std::string& letterGrade) {
    finalGrade = static_cast <double> (0.4 * homework + 0.25 * midterm + 0.35 * finalExam); //calculates the final grade based on the given weight

    if (finalGrade >= 90) {
        letterGrade = "A";
    } else if (finalGrade >= 80) {
        letterGrade = "B";
    } else if (finalGrade >= 70) {
        letterGrade = "C";
    } else if (finalGrade >= 60) {
        letterGrade = "D";
    } else if (finalGrade >= 50) {
        letterGrade = "E";
    } else {
        letterGrade = "F";
    }
}

void const printReport (const std::string& name,const uint_least16_t& homework, const uint_least16_t& midterm, const uint_least16_t& finalExam, 
                   const double& finalGrade, const std::string& letterGrade) {
    std::string status = " ";

    if (letterGrade == "F") {
        status = "FAIL";
    } else if (letterGrade == "D" || letterGrade == "E") {
        status = "CONDITIONAL PASS";
    } else {
        status = "PASS";
    }

    std::cout << "-----------------------------------\n";
    std::cout << "Student Report\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "\n";
    std::cout << "Scores\n";
    std::cout << "-----------------------------------\n";
    std::cout << "Homework: " << homework  << std::endl;
    std::cout << "Mitderm: " << midterm  << std::endl;
    std::cout << "Final Exam: " << finalExam << std::endl << std::endl;
    std::cout << "Final Grade: " << finalGrade  << std::endl;
    std::cout << "Letter Grade: " << letterGrade  << std::endl;
    std::cout << "Status: " << status  << std::endl;
    std::cout << "-----------------------------------\n";
}