#pragma once

#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <utility>
#include <algorithm>

#include "date.h"
#include "node.h"

using namespace std;

ostream &operator<<(ostream &os, const pair<Date, string> &entry);

class Database {
public:
    void Add(const Date& date, const string& event);

//    template<typename T>
//    int RemoveIf(const T& predicate);
//    int RemoveIf(const function<bool(Date, string)>& predicate);

//    template<typename T>
//    vector<pair<Date, string>> FindIf(const T& predicate) const ;
//    vector<pair<Date, string>> FindIf(const function<bool(Date, string)>& predicate) const ;

    template<typename T>
    int RemoveIf(const T& predicate) {
        auto temp = storage;
        int counter=0;
        for (const auto& p: temp) {
            size_t size = p.second.size();
            size_t const_size = p.second.size();
            for (size_t i=0;i<const_size;i++) {
                if (predicate(p.first, p.second[i])){
                    if(size>1){
                        storage[p.first].erase(storage[p.first].begin()+i-(const_size-size));
                        storage_t[p.first].erase(p.second[i]);
                        --size;
                    }else{
                        storage.erase(p.first);
                        storage_t.erase(p.first);
                    }
                    counter++;
                }
            }
        }
        return counter;
    }

    template<typename T>
    vector<pair<Date, string>> FindIf(const T& predicate) const {
        vector<pair<Date, string>> v_pair;
        for (const auto& p: storage) {
            for (const auto &i:p.second) {
                if (predicate(p.first, i)){
                    v_pair.push_back({p.first, i});
                }
            }
        }
        return v_pair;
    }

    pair<Date, string> Last(const Date& date) const ;

    void Print(ostream& os) const ;

private:
    map<Date, vector<string>> storage;
    map<Date, set<string>> storage_t;
};

