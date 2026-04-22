#ifndef REPORT_UTILS_HPP
#define REPORT_UTILS_HPP

#include <cstdint>

int getAndCheckInput(std::string message);

void readStudentData(std::string& name, uint_least16_t& homework, uint_least16_t& midterm, uint_least16_t& finalExam);

void calculateGrade(uint_least16_t& homework, uint_least16_t& midterm, uint_least16_t& finalExam, 
                    double& finalGrade, std::string& letterGrade);


void const printReport (const std::string& name,const uint_least16_t& homework, const uint_least16_t& midterm, const uint_least16_t& finalExam, 
                   const double& finalGrade, const std::string& letterGrade);

#endif