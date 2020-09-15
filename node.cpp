//
// Created by idons on 16.06.2020.
//

#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const string &event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    switch (cmp_) {
        case Comparison::Equal:{
            return date==date_;
        };
        case Comparison::LessOrEqual:{
            return date<=date_;
        };
        case Comparison::GreaterOrEqual:{
            return date>=date_;
        };
        case Comparison::Less:{
            return date<date_;
        };
        case Comparison::Greater:{
            return date>date_;
        };
        case Comparison::NotEqual:{
            return date!=date_;
        }
    }
}

bool EventComparisonNode::Evaluate(const Date &date, const string &event) const {
    switch (cmp_) {
        case Comparison::Equal:{
            return event==value_;
        };
        case Comparison::LessOrEqual:{
            return event<=value_;
        };
        case Comparison::GreaterOrEqual:{
            return event>=value_;
        };
        case Comparison::Less:{
            return event<value_;
        };
        case Comparison::Greater:{
            return event>value_;
        };
        case Comparison::NotEqual:{
            return event!=value_;
        };
    }
}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch (l_op_) {
        case LogicalOperation::Or:{
            return left_->Evaluate(date, event)||right_->Evaluate(date, event);
        };
        case LogicalOperation::And:{
            return left_->Evaluate(date, event)&&right_->Evaluate(date, event);
        };
        default: {}
    }
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date &date) : cmp_(cmp), date_(date) {}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string &value) : cmp_(cmp), value_(value) {}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& lOp, const shared_ptr<Node> &left,
                                           const shared_ptr<Node> &right) : l_op_(lOp), left_(left), right_(right) {}
