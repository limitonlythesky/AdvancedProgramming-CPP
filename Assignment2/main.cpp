#include <bits/stdc++.h>
#include "Person.h"

using namespace std;

Person :: Person(){

}

Person :: Person(string n, int a, int l){
    this -> name = n;
    this -> age = a;
    this -> luck = l;
}

string Person::getName(){
    return name;
}

int Person::getAge(){
    return age;
}

int Person::getLuck(){
    return luck;
}

void Person::setName(string n){
    this -> name = n;
}

void Person::setAge(int a){
    this -> age = a;
}

void Person::setLuck(int l){
    this -> luck = l;
}

vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector <Person> persons;

int random(int i){
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    return v[i];
}

int getLuckiestPerson(){
    int mx = 0, ind = -1;
    for(int i = 0; i < persons.size(); i++){
        if(persons[i].getLuck() > mx){
            mx = persons[i].getLuck();
            ind = i;
        }
    }
    return ind;
}

void changeLuck(int first, int second) {
    int l = persons[first - 1].getLuck();
    persons[first - 1].setLuck(persons[second - 1].getLuck());
    persons[second - 1].setLuck(l);
}

int main(){
    Person p1 = Person("Jasmine", 19, random(0));
    Person p2 = Person("Alibek", 21, random(2));
    Person p3 = Person("Said", 25, random(3));
    Person p4 = Person("Bekmuhammed", 27, random(4));
    Person p5 = Person("Shokan", 30, random(5));
    persons = {p1, p2, p3, p4, p5};
    while(true) {
        cout << "PRESS [1] FOR FINDING THE LUCKIEST PERSON\n";
        cout << "PRESS [2] FOR SWITCH THE LUCK\n";
        cout << "PRESS [0] FOR EXIT\n";
        int choice;
        cin >> choice;
        if(choice == 1) {
            int id = getLuckiestPerson();
            cout << "The luckiest person is " << persons[id].getName() << " with " << persons[id].getLuck()
                 << " points of luck.\n\n";
        }else if(choice == 2){
            cout << "Choose two Persons by their index: \n";
            for(int i = 0; i < persons.size(); i++){
                cout << i + 1 << " " << persons[i].getName() << " " << persons[i].getAge() << " " << persons[i].getLuck() << endl;
            }
            int first, second;
            cin >> first >> second;
            changeLuck(first, second);
        }else{
            break;
        }
    }
}


