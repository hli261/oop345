//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  1/21/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <iostream>
#include <string>
using namespace std;

namespace sdds {
   class RecordSet {
      size_t recordNumber{};
      string* record{};
   public:
      RecordSet();
      RecordSet(const char* filename);
      RecordSet(const RecordSet& Rset);
      RecordSet& operator=(const RecordSet& Rset );
      ~RecordSet();

      size_t size() const;
      std::string getRecord(size_t ) const;
   };
}
#endif