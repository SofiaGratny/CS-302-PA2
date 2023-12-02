// written by sofia gratny
// september 27, 2022
// task object


#ifndef TASK_H
#define TASK_H


#include <iostream>

class Task {
    
    private:

        std::string desc;
        bool completed;
        bool linkSet;
        Task *link;

    public:

        Task();
        ~Task() = default;

        void setDesc(const std::string&);
        void setCompleted(bool);
        void setLink(Task*);

        bool isCompleted() const;
        std::string getDesc() const;
        bool hasLink() const;
        Task* getLink() const;
};


#endif // TASK_H