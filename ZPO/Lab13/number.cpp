//
// Created by lukas on 10.01.2024.
//

#include "number.h"
Number::Number(int n1)
{
n=n1;
}
int Number::inc(){
  return n+1;
  }
 int Number::getN(){
  return n;

  }
 void Number::setN(int n1){
  n=n1;
  }
