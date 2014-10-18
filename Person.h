/*
 * Person.h
 *
 *  Created on: 2014年9月29日
 *      Author: qmwx
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <iostream>

class Person{
public:
	Person(std::string nm, int a):name(nm), age(a){

	}

	virtual std::string getName()const{
		return name;
	}
	virtual int getAge()const{
		return age;
	}
	virtual void setAge(int a){
		age = a;
	}
	friend std::ostream& operator<<(std::ostream& os, Person & s){
		os << "Ordinary person:Name, Age = " << "[" << s.name << "," << s.age << "]" << std::endl;
		return os;
	}

	virtual ~Person(){

	}
private:
	std::string name;
	int age;
};




#endif /* PERSON_H_ */
