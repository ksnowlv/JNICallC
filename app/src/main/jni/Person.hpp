//
// Created by ksnowlv on 2019/4/9.
//

#ifndef HELLOJNIFORJAVA_PERSON_H
#define HELLOJNIFORJAVA_PERSON_H

#include <stdio.h>


class Person {
public:
    Person();
    ~Person();

    void setName(const char* pName);
    const char* name();

    void setAge(const int age);
    const int age() const;

private:
    char *m_pName;
    int m_age;
};

#endif //HELLOJNIFORJAVA_PERSON_H
