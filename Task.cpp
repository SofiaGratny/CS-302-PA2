// written by Sofia Gratny
// september 27, 2022


#include "Task.h"

Task::Task() {

    desc = "";
    completed = false;
    linkSet = false;
}

void Task::setDesc(const std::string& _desc) {

    desc = _desc;
}

void Task::setCompleted(bool _completed) {

    completed = _completed;
}

void Task::setLink(Task *task) {

    link = task;
    linkSet = true;
}

bool Task::isCompleted() const {

    return completed;
}

std::string Task::getDesc() const {

    return desc;
}

bool Task::hasLink() const {

    return linkSet;
}

Task* Task::getLink() const {

    return link;
}