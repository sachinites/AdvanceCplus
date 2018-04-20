/*
 * =====================================================================================
 *
 *       Filename:  NestedTemplateUse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 19 April 2018 03:13:29  IST
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
#include "Clist.h"
#include <iostream>

class Person{

    public:
        string name;
        unsigned int height;
        Person(string name, unsigned int height){
            this->name = name;
            this->height = height;
        }
} ;

int
main(int argc, char **argv){

    /*Nested List*/
    Clist< Clist<Person> > *nested_lst = new Clist< Clist<Person> >(NULL);

    /*Creating a list of engineering team*/
    Clist<Person> *engg = new Clist<Person>(NULL);
    Clistnode<Person> *node = new Clistnode<Person>();
    Person *person = new Person("Abhishek", 0);
    node->data = person;
    node->next = NULL;
    engg->add(node);
    person = new Person("Ram", 0);
    node = new Clistnode<Person>();
    node->data = person;
    node->next = NULL;
    engg->add(node);
   
    Clistnode<Clist<Person> > *NODE = new Clistnode<Clist<Person> >();
    NODE->data = engg;
    NODE->next = NULL;
    nested_lst->add(NODE);
    return 0;
}
