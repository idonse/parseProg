//
// Created by idons on 16.06.2020.
//
#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <string>
#include <vector>


using namespace std;

class Date {
public:
    // конструктор выбрасывает исключение, если его аргументы некорректны
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const ;

    bool operator==(const Date &rhs) const;

    bool operator!=(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;

private:
    int year;
    int month;
    int day;
};

// определить сравнение для дат необходимо для использования их в качестве ключей словаря
bool operator<(const Date& lhs, const Date& rhs);

// даты будут по умолчанию выводиться в нужном формате
ostream& operator<<(ostream& stream, const Date& date);

Date ParseDate(istream & is);