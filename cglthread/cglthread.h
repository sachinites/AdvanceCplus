/*
 * =====================================================================================
 *
 *       Filename:  cglthread.h
 *
 *    Description:  glue thread implementation in C++
 *
 *        Version:  1.0
 *        Created:  Saturday 21 April 2018 03:20:54  IST
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

#ifndef __CGL_THREAD__
#define __CGL_THREAD__

template <class T>
class CGLThread{

    private:
        T *object_ptr;
    public:
        CGLThread *right;
        CGLThread *left;
        void init_cglthread();
        void cglthread_add_next(CGLThread *new_cglthread);
        void cglthread_add_before(CGLThread *new_cglthread);
        void remove_cglthread();
        CGLThread<T>* get_embedded_address();
        void set_object(T *object_ptr);
        T *get_object();
        CGLThread();
        virtual ~CGLThread();

        /*Implementing STL like Iterator*/
        class citerator{
            private:
                CGLThread<T> *ptr;
            public:
                citerator(CGLThread<T> *ptr){
                    this->ptr = ptr;
                }
                T *GET_DATA(){
                    return ptr->get_object();
                }
                citerator operator++(int){
                    ptr = ptr->right;
                    return *this;
                }
                bool operator==(citerator curr){
                    return curr.ptr == ptr;
                }
                bool operator!=(citerator curr){
                    return curr.ptr != ptr;
                }
                T* operator*() {
                    return GET_DATA();
                }
                CGLThread<T>* get_embedded_address() {
                    return ptr;
                }
        };
         
        citerator begin();
        citerator end();
};

#include "cglthread_impl.h"

#endif /* __CGL_THREAD__ */
