#ifndef ASSIGNMENT2_PERSON_H
#define ASSIGNMENT2_PERSON_H
#include <cstring>

using namespace std;

class Person {
public:
    Person();
    Person(string n, int a, int l);
    string getName();
    int getAge();
    int getLuck();
    void setName(string n);
    void setAge(int a);
    void setLuck(int l);
private:
    string name;
    int age;
    int luck;
};


#endif //ASSIGNMENT2_PERSON_H
