/*
 * =====================================================================================
 *
 *       Filename:  dict.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Thursday 19 April 2018 01:19:23  IST
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

#include "Clist.h"
#include <string>
#include <iostream>
using namespace std;
class Node{

    public:
    string node_name;
    Clist<unsigned int> *sids;

    Node(string node_name){
        this->node_name = node_name;
        sids = new Clist<unsigned int>(NULL);
    }
    void add_sid(unsigned int sid){
        Clistnode<unsigned int> *node = new Clistnode<unsigned int>();
        node->data = (unsigned int *)sid;
        sids->add(node);
    }
    void print_sids(){
        for(Clist<unsigned int>::citerator it = sids->begin(); it!= sids->end(); it++){
            unsigned int sid = (unsigned int)it.GET_DATA();
            cout << "sid = " << sid << endl;
        }

    }
};

class Graph{

    public:
    Clist<Node> *graph;
    Graph(){
        graph = new Clist<Node>(NULL);
    }
    Node *add_node(string node_name){
        Clistnode<Node> *node = new Clistnode<Node>();
        Node *gnode = new Node(node_name);
        node->data = gnode;
        node->next = NULL;
        graph->add(node);
        return gnode;
    }
    void print_graph(){
        for(Clist<Node>::citerator it = graph->begin(); it!= graph->end(); it++){
            Node *node = it.GET_DATA();
            cout << "Node : " << node->node_name << endl;
            node->print_sids();
        }
    }
};

int
main(int argc, char **argv){

    Graph *g = new Graph();
    Node *node = g->add_node("R0");
    node->add_sid(1);
    node->add_sid(2);

    g->print_graph();

    return 0;
}
