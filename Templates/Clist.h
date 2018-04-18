/*
 * =====================================================================================
 *
 *       Filename:  helloworld.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Wednesday 18 April 2018 05:43:08  IST
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

#ifndef __CLIST__
#define __CLIST__

template <class T>
class Clistnode{

    private:
    public:
        T *data;
        Clistnode *next;
        Clistnode();
        ~Clistnode();
} ;

template <class T>
class Clist{
    private:
        unsigned int count;      
        Clistnode<T> *head;
        void (*print_data_cb)(T *);
        int (*compare_fn)(T *, T *);
    public:
        Clist(void (*print_data)(T *));
        virtual ~Clist();
        void add(Clistnode<T> *node);
        void print_list();
        /*Callbacks registeration fn*/
        void register_compare_callback(int (*compare_fn)(T *, T *));
};


#include "Clist_impl.h"

#endif 
