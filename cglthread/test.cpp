/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  Test program for CGLThread library
 *
 *        Version:  1.0
 *        Created:  Saturday 21 April 2018 03:37:49  IST
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

#include <iostream>
#include "cglthread.h"
#include <string>

using namespace std;

class Person{

    public:
        string name;
        unsigned int age;
        CGLThread<Person> cgl_thread;
        Person(string name, unsigned int age){
            this->name = name;
            this->age = age;
            cgl_thread.init_cglthread();
            cgl_thread.set_object(this);
        }
};

int
main(int argc, char **argv){

    CGLThread<Person> base_cgl_thread;
    base_cgl_thread.init_cglthread();
    base_cgl_thread.set_object(NULL);

    Person *per1 = new Person("Abhishek", 31);
    Person *per2 = new Person("Shivani", 30);
    Person *per3 = new Person("Ram", 30);
    Person *per4 = new Person("Kranthi", 30);

    base_cgl_thread.cglthread_add_next(&per1->cgl_thread);
    base_cgl_thread.cglthread_add_next(&per2->cgl_thread);
    base_cgl_thread.cglthread_add_next(&per3->cgl_thread);
    base_cgl_thread.cglthread_add_next(&per4->cgl_thread);
   
    for(CGLThread<Person>::citerator it = base_cgl_thread.begin(); it != base_cgl_thread.end(); it++){
        Person *person  = *it; 
        cout << "Person name = " << person->name << endl;
    }
    
    for(CGLThread<Person>::citerator it = base_cgl_thread.begin(); it != base_cgl_thread.end(); it++){
       CGLThread<Person> *cgl_thread  =  it.get_embedded_address();
       Person *person = (Person *) ((unsigned char *)(cgl_thread) - offsetof (Person, cgl_thread)); 
        cout << "Person name = " << person->name << endl;
    }
    return 0;
}
