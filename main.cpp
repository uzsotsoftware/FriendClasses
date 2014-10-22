/* 
 * File:   main.cpp
 * Author: Samuel Gwokuda
 *
 * Created on October 22, 2014, 11:03 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Student{
    string studentName;
    int assignmentMark[2];
    int testMark[2];
    int examMark;
    friend class Course;
    
public:
    Student(string name);
    ~Student();
    
    string getStudentName(){
        return studentName;
    }
    
        
    int getAssignmentMark(int index){
        return assignmentMark[index];
    }
    
    int getTestMark(int index){
        return testMark[index];
    }
    
    int getExamMark(){
        return examMark;
    }
    
    void printAllMarks(){
        cout << "\n\nNow Printing out the Marks\n\n";
        cout << "Student Name : " << studentName << endl;
            
        for (int i = 0;  i < 2; i++){
            cout << "Assignment " << i+1 << " : " << getAssignmentMark(i) << endl; 
        }
        
        for (int i = 0;  i < 2; i++){
            cout << "Test " << i+1 << " : " << getTestMark(i) << endl; 
        }
        cout <<"Exam Mark : " << getExamMark() << endl;
 
    }
    
};

Student::Student(string name){
   studentName = name;
}

Student::~Student(){
   //Dtor
}





class Course{
    string courseName;
public:
    Course(string thisCourseName);
    ~Course();
    Student recordMarks(Student studentObject);
    
};

Course::Course(string thisCourseName){
    courseName = thisCourseName;
}

Course::~Course(){
//dtor
}



Student Course::recordMarks(Student studentObject) {
    
    int enteredMark;
    cout << "Enter Mark for Assignment 1:  ";
    cin >> enteredMark;
    studentObject.assignmentMark[0] = enteredMark;
    cout << "Enter Mark for Assignment 2:  ";
    cin >> enteredMark;
    studentObject.assignmentMark[1] = enteredMark;
    cout << "Enter Mark for Test 1:  ";
    cin >> enteredMark;
    studentObject.testMark[0] = enteredMark;
    cout << "Enter Mark for Test 2:  ";
    cin >> enteredMark;
    studentObject.testMark[1] = enteredMark;
    cout << "Enter Exam Mark :  ";
    cin >> enteredMark;
    studentObject.examMark = enteredMark;

    return studentObject;
}


int main(int argc, char** argv) {
    string name;
    int enteredMark;
    cout << "Enter Student Name: ";
    cin >> name;    
    Student tempStudent(name);
    Course course1("eCommerce");
    Student Sam = course1.recordMarks(tempStudent);
    Sam.printAllMarks();
    return 0;
}

