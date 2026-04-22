#include <cstdint>
#include <string>
#include "report_utils.hpp"


int main() {

    std::string name = "";
    double fgrade = 0;
    std::string lgrade = "";
    uint_least16_t homework = 0;
    uint_least16_t midterm = 0;
    uint_least16_t finalExam = 0;

    readStudentData(name, homework, midterm, finalExam);
    calculateGrade(homework, midterm, finalExam, fgrade, lgrade);

    printReport(name, homework, midterm, finalExam, fgrade, lgrade);
}