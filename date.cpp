//
// Created by idons on 16.06.2020.
//

#include "date.h"

using namespace std;

// конструктор выбрасывает исключение, если его аргументы некорректны
Date::Date(int new_year, int new_month, int new_day) {
    year = new_year;
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    }
    month = new_month;
    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
    }
    day = new_day;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
           vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &stream, const Date &date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
           "-" << setw(2) << setfill('0') << date.GetMonth() <<
           "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

bool Date::operator==(const Date &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

Date ParseDate(istream& is) {
    string date=" " ;
    bool ok = true;

    int year;
    ok = ok && (is >> year);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int month;
    ok = ok && (is >> month);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int day;
    ok = ok && (is >> day);
    if(!is){
        ok= false;
    }

    if (!ok) {
        getline(is,date);
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}
