/*
 * Student.h
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <iostream>
#include "Person.h"

class Student : public Person{
public:
	Student(int id, std::string name, int age, int cName): Person(name, age), stuId(id), className(cName){

	}
	virtual int getStuId()const{
		return stuId;
	}
	virtual int getClass()const{
		return className;
	}
	friend std::ostream& operator<<(std::ostream& os, Student & s){
		os << "Student " << "[" << s.getName() << ","
				<< s.getAge() << ","
				<< s.getStuId() << ","
				<< s.getClass() << ","
				<< "]" << std::endl;
		return os;
	}
	virtual ~Student(){

	}
private:
	int stuId;
	int className;
};



#endif /* STUDENT_H_ */
