/*
 * =====================================================================================
 *
 *       Filename:  cglthread.cpp
 *
 *    Description:  glue thread implementation in C++
 *
 *        Version:  1.0
 *        Created:  Saturday 21 April 2018 03:25:39  IST
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


template <class T>
void CGLThread<T>::init_cglthread(){
    this->right = 0;
    this->left = 0;
    this->object_ptr = 0;
}

template <class T>
void CGLThread<T>::cglthread_add_next(CGLThread *new_cglthread){

    if(!this->right){
        this->right = new_cglthread;
        new_cglthread->left = this;
        return;
    }

    CGLThread *temp = this->right;
    this->right = new_cglthread;
    new_cglthread->left = this;
    new_cglthread->right = temp;
    temp->left = new_cglthread;
}


template <class T>
void CGLThread<T>::cglthread_add_before(CGLThread *new_cglthread){

    if(!this->left){
        new_cglthread->left = NULL;
        new_cglthread->right = this;
        this->left = new_cglthread;
        return;
    }

    CGLThread *temp = this->left;
    temp->right = new_cglthread;
    new_cglthread->left = temp;
    new_cglthread->right = this;
    this->left = new_cglthread;
}


template <class T>
void CGLThread<T>::remove_cglthread(){

    if(!this->left){
        if(this->right){
            this->right->left = NULL;
            this->right = 0;
            return;
        }
        return;
    }
    if(!this->right){
        this->left->right = NULL;
        this->left = NULL;
        return;
    }

    this->left->right = this->right;
    this->right->left = this->left;
    this->left = 0;
    this->right = 0;
}

template <class T>
void
CGLThread<T>::set_object(T *object_ptr){
    this->object_ptr = object_ptr;
}

template <class T>
T* CGLThread<T>::get_object(){
    return this->object_ptr;
}

template <class T>
CGLThread<T>::CGLThread(){
}

template <class T>
CGLThread<T>::~CGLThread(){
    if(this->object_ptr)
        delete this->object_ptr;
}

template <class T>
typename CGLThread<T>::citerator
CGLThread<T>::begin(){
    return citerator(this->right);
}

template <class T>
typename CGLThread<T>::citerator
CGLThread<T>::end(){
    return citerator(NULL);
}

