/*
 * =====================================================================================
 *
 *       Filename:  person.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 18 April 2018 06:08:48  IST
 *       Revision:  1.0
 *       Compiler:  gcc
 *
 *         Author:  Er. Abhishek Sagar, Networking Developer (AS), sachinites@gmail.com
 *        Company:  Brocade Communications(Jul 2012- Mar 2016), Current : Juniper Networks(Apr 2017 - Present)
 *        
 *        This file is part of the XXX distribution (https://github.com/sachinites).
 *        Copyright (c) 2017 Abhishek Sagar.
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU General Public License as published by  
 *        the Free Software Foundation, version 3.
 *
 *        This program is distributed in the hope that it will be useful, but 
 *        WITHOUT ANY WARRANTY; without even the implied warranty of 
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 *        General Public License for more details.
 *
 *        You should have received a copy of the GNU General Public License 
 *        along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * =====================================================================================
 */

using namespace std;
#include <string>
#include <iostream>
#include "Clist.h"
#include "GenIt.h"

class Person{

    public:
        string name;
        int age;
        int weight;
        Person();
        ~Person();
}; 

Person::Person(){
    name = "unknown";
    age = 0;
    weight = 0;
}

Person::~Person(){
    delete this;
}

void 
print_person(Person *person){

    cout << "Person name = " <<  person->name << endl;
    cout << "age = "  << person->age << endl;
    cout << "weight = " <<  person->weight << endl;
}


int
main(int argc, char **argv){

    Clist<Person> *list = new Clist<Person>(print_person);
    Clistnode<Person> *node1 = new Clistnode<Person>();
    Clistnode<Person> *node2 = new Clistnode<Person>();

    Person *person1 = new Person();
    person1->name = "Abhishek";
    person1->age = 31;
    person1->weight = 81;

    Person *person2 = new Person();
    person2->name = "Shivani";
    person2->age = 30;
    person2->weight = 61;

    node1->data = person1;
    node1->next = NULL;
    list->add(node1);

    node2->data = person2;
    node2->next = NULL;
    list->add(node2);

    Clistnode<Person> node3;
    node3.data = person2;
    node3.next = 0;

    list->add(&node3);
    list->print_list();

    return 0;
}
