#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;


class Student {
private:
    string name , id ;
    float gpa;

public:

    Student(string Name ,  string ID , float Gpa ) ;
    Student();
    string getName() const;
    string getID() const ;
    float getGPA() const ;

    friend bool operator< (const Student& A , const Student& B) ;
    friend bool operator<= (const Student& A , const Student& B) ;
    friend bool operator> (const Student& A , const Student& B) ;
    friend bool operator>= (const Student& A , const Student& B) ;

//    bool operator<(const Student& other) const ;
//    bool operator<=(const Student& other) const ;
//
//    bool operator>(const Student& other) const ;
//    bool operator>=(const Student& other) const ;
    void operator= (const Student& other) ;
};

#endif // STUDENT_H