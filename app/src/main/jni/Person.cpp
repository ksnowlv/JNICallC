//
// Created by ksnowlv on 2019/4/9.
//

#include "Person.hpp"
#include <string.h>


Person::Person() {
    m_pName = nullptr;
    m_age = 0;
}

Person::~Person() {

    if (m_pName) {
        delete [] m_pName;
        m_pName = nullptr;
    }
}

void Person::setAge(const int age) {
    m_age = age;
}

const int Person::age()const {
    return m_age;
}

void Person::setName(const char *pName) {
    if (m_pName) {
        delete [] m_pName;
        m_pName = nullptr;
    }

    if (pName) {
        const size_t len = strlen(pName) + 1;
        m_pName = new char[len];
        memset(m_pName, 0, len);
        strcpy(m_pName, pName);
    }
}

const char* Person::name() {
    return m_pName;
}