#include "Student.h"

using namespace std ;

Student :: Student(string Name ,  string ID , float Gpa ) : name(Name) , id(ID) , gpa(Gpa){}
Student ::Student() : name(""),id("") , gpa(0.0){}
string Student  :: getName() const {
    return name;
}
string Student ::  getID() const {
    return id;
}
float Student ::  getGPA() const {
    return gpa;
}

//bool Student :: operator<(const Student& other) const {
//    return name < other.name;
//}
//bool Student :: operator<=(const Student& other) const {
//    return name <= other.name;
//}
//
//bool Student :: operator>(const Student& other) const {
//    return name > other.name;
//}
//bool Student :: operator>=(const Student& other) const {
//    return name >= other.name;
//}

void Student ::operator=(const Student& other) {
    name = other.name;
    id = other.id;
    gpa = other.gpa;
}

