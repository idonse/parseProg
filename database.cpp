//
// Created by idons on 16.06.2020.
//

#include "database.h"

using namespace std;

ostream &operator<<(ostream &os, const pair<Date, string> &entry) {
    os << entry.first << " " << entry.second;
    return os;
}

void Database::Add(const Date &date, const string &event) {
    if(storage[date].empty()){
        storage[date].push_back(event);
        storage_t[date].insert(event);
    } else{
        auto it = storage_t[date].find(event);
        if (it==storage_t[date].end()){
            storage[date].push_back(event);
            storage_t[date].insert(event);
        }
    }
}

void Database::Print(ostream& os) const {
    for (const auto &item : storage) {
        for (const string &event : item.second) {
            os << item.first << " " << event << endl;
        }
    }
}


pair<Date, string> Database::Last(const Date &date) const {
    if (storage.empty()){
        throw invalid_argument("");
    }
    auto it = storage.lower_bound(date);

    if(it!=storage.end()){
        if (it->first == date){
            return {it->first, it->second.back()};
        } else if(it==storage.begin()){
            throw invalid_argument("");
        }
    }
    return {(--it)->first, (it)->second.back()};
}

