/*  Name:Keying Zhou
 *  USC NetID:1935-0418-72
 *  CS 455 Spring 2017
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int lastIndexOf(ListType list, int val) {
    int resultIndex = -1;               //Use to store the result index
    int index = -1;                     //Count the index
    while(list != NULL){
        index++;
        if (list->data == val){         //If find the target number
            resultIndex = index;        //record the index of the target
        }
        list = list->next;              //Move to the next node
    }
    return resultIndex;
}

void removeFollowingEvens(ListType &list) {
    Node * p = list;
    while (p != NULL){
        if(p->next != NULL){
            if(p->data % 2 == 0 && p->next->data %2 == 0){      //If there are two consecutive even
                Node * temp = p->next;                          //numbers, change the next pointer of
                if (p->next->next != NULL){                     //the current node, then delete the next
                    p->next = p->next->next;                    //node
                }else{
                    p->next = NULL;
                }
                delete temp;
            }else{
                p = p->next;                                    //If it's not the above situation,
            }                                                   //move the pointer to the next node.
        }else{
            p = p->next;
        }
    }
}

void mirrorList(ListType & list) {
    Node * p = list;
    Node * q = list;
    if(p != NULL){                                          //Move pointer p to the end of the list
        while(p->next != NULL){
            p = p->next;
        }
        while(q != p->next){                                //While q doesn't move out of the original
            if(p->next == NULL){                            //list
                Node * newNode = new Node(q->data);         //First, copy the first node append to the
                p->next = newNode;                          // list
            }else{
                Node * newNode = new Node(q->data, p->next);    //For the nodes following, we need to
                p->next = newNode;                              //insert them before the new node
            }
            q = q->next;                                     //Move pointer q to the next node
        }
    }
    
}

void rotateRight(ListType &list, int k) {
    int count = 0;                                  //Count the number of nodes
    Node * c = list;                                //in the list
    while(c != NULL){
        count++;
        c = c->next;
    }
    //If k <=0 or k>=list length, the list remain unchanged
    while(k > 0 && k < count){                      //while k is in the range
        Node * p = list;                            //new a pointer every time start a loop
        if(p != NULL){
            if(p->next != NULL){
                while (p->next->next != NULL){
                    p = p->next;                    //Move the pointer to the penultimate node of the
                }                                   //list
                p->next->next = list;               //The next pointer of the last node point to the
                                                    //head of the list
                list = p->next;                     //the head pointer point to the last node
                p->next = NULL;                     //the next pointer of the current node change to
                                                    //NULL
            }
        }
        k--;
    }
}
