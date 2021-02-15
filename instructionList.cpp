#include <iostream>

/*
THIS CPP IS FOR THE FIRST 4 FUNCTIONS
operator<< - outputs the list of instructions with <<
append() - adds a new node from the Odd or Even List to the end of the list
substitute() - iterates through the list and then substitutes a temp list based on instructions
~Instruction() - deletes each node in the linked list
*/
#include "instruction_list.h"
#include "hilbert.h"
#include "turtle.h"
using namespace std;

ostream& operator<<(ostream& out, const InstructionList& l)
{
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        if(*it == FORWARD)
        out << "F ";
        else if(*it == TURN_LEFT)
        out << "L ";
        else if(*it == TURN_RIGHT)
        out << "R ";
        else if(*it == ODD)
        out << "O ";
        else
        {out << "E ";}
    }
    return out;
}

void InstructionList::append(hilbert_t add)
{
    if (head == nullptr)//if list is empty
    {
        head = new node_t();
        head->move = add;
        tail = head;
    }
    else//if list is not empty
    {
        node_t* temp = new node_t();
        temp->move = add;
        tail->next = temp;

        tail = temp;
    }
}

/*
iterator to go through instruction list.



it->next = new node_t();
 it = it->next;

*/

void InstructionList::substitute(const unordered_map<hilbert_t, const InstructionList*> &m)
{
    const InstructionList* temp;
    node_t* after = new node_t();//node represents next node pointed to
    //O -> L, E, F, R, O, F, O, R, F, E, L;
    //E -> R, O, F, L, E, F, E, L, F, O, R;

    for(node_t *it = head; it != NULL; it = it->next)
    {
        if(m.find(it->move) != m.end())
        {   
            after = it->next;
            temp = m.at(it->move);
        
            for(node_t *nit = temp->head; nit != NULL; nit = nit->next)
            {
                it->move = nit->move;//start new node iteration
                if(nit->next != NULL)
                {
                it->next = new node_t();
                
                it = it->next;
                }
                it->next = after;//subs in new rule nodes
            }
        if(it == tail)//final node?
        tail = it;//tail now -> nullptr
        }
    }
    

}


InstructionList::~InstructionList()
{
    node_t* currnode = head;
    node_t* nextNode = NULL;

    while(currnode != NULL)
    {
        nextNode = currnode->next;
        delete currnode;
        currnode = nextNode;
    }

}





