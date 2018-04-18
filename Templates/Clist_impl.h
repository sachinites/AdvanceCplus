/*
 * =====================================================================================
 *
 *       Filename:  helloworld.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 18 April 2018 05:53:56  IST
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

/*Implementation of Clistnode class*/
using namespace std;

template <class T>
Clistnode<T>::Clistnode(){
    data = NULL;
    next = NULL;
}

template <class T>
Clistnode<T>::~Clistnode(){
    data = NULL;
    next = NULL;
}

/*Implementation of Clist class*/
template <class T>
Clist<T>::Clist(void (*print_data)(T *)){
    count = 0;
    head = NULL;
    print_data_cb = print_data;
}

template <class T>
Clist<T>::~Clist(){
    if(!head){
        return;
    }
    Clistnode<T> *temp = head,
                 *next = NULL;
    while(!temp){
        next = temp->next;
        delete temp;
        temp = next;
    }
}

template <class T>
void Clist<T>::add(Clistnode<T> *node){

   if(!head){
        head = node;
        count = 1; 
        return;  
   }
   Clistnode<T> *temp = NULL;
   temp = head;
   while(temp->next){
       temp = temp->next;
       continue;
   }
   temp->next = node;
   node->next = NULL;
   count++;
}

template <class T>
void Clist<T>::print_list(){

    if(!head){
        cout << "Empty List" << endl;
        return;
    }
    
    if(!print_data_cb){
        cout << "print callback not registered" << endl;
        return;
    }

    Clistnode<T> *temp = head;
    while(temp){
        (*print_data_cb)(temp->data);
        temp = temp->next;
    }
}

template <class T>
void Clist<T>::register_compare_callback(int (*compare_fn)(T *, T *)){

    this->compare_fn = compare_fn;
}

#if 0
template <class T>
Clist<T>::citerator Clist<T>::citerator::begin(){
    return Clist<T>::citerator(head);
}

template <class T>
Clist<T>::citerator Clist<T>::citerator::end(){
    return Clist<T>::citerator(NULL);
}
#endif
