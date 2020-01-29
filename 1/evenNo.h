#ifndef _EVENNO-SDDS_H
#define _EVENNO-SDDS_H
//evenNo.h

namespace sdds{

    class EvenNumber{
        int evenNo;
    public:
        EvenNumber();
        EvenNumber(int);
        int getValue();
        EvenNumber getNext();
        EvenNumber getPrevious();
    };

}
#endif