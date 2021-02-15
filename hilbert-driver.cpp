#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

#include "hilbert.h"


const int HILBERT_LEVEL = 9;
const int IMAGE_SIZE = 1000;
const string OUTPUT_FILE = "hilbert.bmp";

int main()
{
 HilbertCurve curve(HILBERT_LEVEL, IMAGE_SIZE);
 curve.writeToFile(OUTPUT_FILE);

  
  InstructionList* temp = new InstructionList();
  InstructionList* oddList = new InstructionList();
  InstructionList* evenList = new InstructionList();

  temp->append(ODD);
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

  unordered_map<hilbert_t, const InstructionList*> substitution = { {ODD, oddList}, {EVEN, evenList} };

  temp->substitute(substitution);
  //cout << temp << endl;
     return 0;
}