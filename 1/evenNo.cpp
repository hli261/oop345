//evenNo.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "evenNo.h"

namespace sdds{

    EvenNumber::EvenNumber():evenNo(0){}
    EvenNumber::EvenNumber(int even1){
        if(even1 % 2 == 0){
            evenNo = even1;
        }
        else{
            evenNo = 0;
        }       
    }
    int EvenNumber::getValue(){
        return evenNo;
    }
    EvenNumber EvenNumber::getNext(){
        EvenNumber temp;
        temp.evenNo = evenNo + 2;
        return temp;
    }
    EvenNumber EvenNumber::getPrevious(){
        EvenNumber temp;
        temp.evenNo = evenNo - 2;
        return temp;
    }

}