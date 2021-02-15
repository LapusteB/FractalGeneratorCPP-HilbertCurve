#include <iostream>
#include <unordered_map>
#include <cstring>
#include <math.h>

using namespace std;

#include "hilbert.h"
#include "turtle.h"

/*
THIS CPP IS FOR DRAWING A HILBERT CURVE WITH 1 MAIN CONSTRUCTOR
First create 2 new class objects for Instruction List. The Oddlists and EvenLists will append 
odd and even instructions

the level determines how many times a substitution will occur
the size determines how big(in pixels the hilbert curve will be)
turtle(size,size) is nessisary for the turtle.cpp implementation and drawing of the curve
Once rules has been added as odd, and oddlist and even list is appended, A map is created with even lists
and odd lists.
The map is substituted (level) ammount of times
turtle.follow(rules) gives way to how to draw the cruve based on complexity and size.
*/

HilbertCurve::HilbertCurve(int level, int size): turtle(size,size), rules(){
  
  
  InstructionList* oddList = new InstructionList();
  InstructionList* evenList = new InstructionList();

   rules.setDistance(size*pow(0.5,level));
    //O -> L, E, F, R, O, F, O, R, F, E, L;
    //E -> R, O, F, L, E, F, E, L, F, O, R;

  rules.append(ODD);
  //rules.append(EVEN);


  oddList->append(TURN_LEFT);
  oddList->append(EVEN);
  oddList->append(FORWARD);
  oddList->append(TURN_RIGHT);
  oddList->append(ODD);
  oddList->append(FORWARD);
  oddList->append(ODD);
  oddList->append(TURN_RIGHT);
  oddList->append(FORWARD);
  oddList->append(EVEN);
  oddList->append(TURN_LEFT);


  evenList->append(TURN_RIGHT);
  evenList->append(ODD);
  evenList->append(FORWARD);
  evenList->append(TURN_LEFT);
  evenList->append(EVEN);
  evenList->append(FORWARD);
  evenList->append(EVEN);
  evenList->append(TURN_LEFT);
  evenList->append(FORWARD);
  evenList->append(ODD);
  evenList->append(TURN_RIGHT);

  unordered_map<hilbert_t, const InstructionList*> map = { {ODD, oddList}, {EVEN, evenList} };
  
   
  for(int i = 0; i<level; i++)
  {
    rules.substitute(map);
  } 
  cout << rules << endl;

   turtle.follow(rules);
   
    
}



    


