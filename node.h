//
// Created by idons on 16.06.2020.
//
#pragma once

#include <string>
#include <memory>

#include "date.h"

enum class Comparison{
    Less, LessOrEqual, Greater, GreaterOrEqual, Equal, NotEqual
};

enum class LogicalOperation{
    Or, And
};

struct Node {
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};


struct EmptyNode : public Node{
    bool Evaluate(const Date &date, const string &event)const override;
};

struct DateComparisonNode: public Node{
    DateComparisonNode(Comparison cmp, const Date &date);

    bool Evaluate(const Date &date, const string &event)const override;

private:
    Comparison cmp_;
    Date date_;
};

struct EventComparisonNode: public Node{
    EventComparisonNode(Comparison cmp, const string &value);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    Comparison cmp_;
    string value_;
};

struct LogicalOperationNode: public Node{
    LogicalOperationNode(const LogicalOperation& lOp, const shared_ptr<Node> &left, const shared_ptr<Node> &right);

    bool Evaluate(const Date &date, const string &event) const override;

private:
    LogicalOperation l_op_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};