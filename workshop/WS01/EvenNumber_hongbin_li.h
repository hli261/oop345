Name: Honbin Li
Student Number£º119177178

#ifndef EVENTNUMBER
#define EVENTNUMBER

namespace sdds {
   class EvenNumber {
      int even;
   public:
      EvenNumber();
      EvenNumber(int n);
      int getValue() const;
      EvenNumber getNext();
      EvenNumber getPrevious();
   };
}
#endif // !EVENTNUMBER

