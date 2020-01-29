//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  1/21/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include<iomanip>
#include<cstring>
#include<fstream>
#include "RecordSet.h"

namespace sdds {
   RecordSet::RecordSet() :recordNumber(0), record(nullptr) {}
   RecordSet::RecordSet(const char* filename) {
      char Record[60]{};
      recordNumber = 0;
      ifstream Open(filename);
      if (Open.is_open()) {           
         while (!Open.fail() && !Open.eof()) {
            Open.get(Record[0]);
            char temp = ' ';
            if (Record[0] == temp) recordNumber++;
         }
         record = new string[recordNumber+1];
         Open.clear();
         Open.seekg(0);
         recordNumber = 0;
         while (!Open.fail() && !Open.eof()) {
            Open.getline(Record, 59, ' ');
            record[recordNumber] = Record;
            recordNumber++;
         }
      }
   }
   RecordSet::RecordSet(const RecordSet& Rset) {
      if (Rset.record != nullptr) {
         recordNumber = Rset.recordNumber;
         record = new string[recordNumber]{};
         for (size_t i = 0; i < recordNumber; i++)
            record[i] = Rset.record[i];
      }
      else {
         record = nullptr;
         recordNumber = 0;
      }
   }
   RecordSet& RecordSet::operator=(const RecordSet& Rset) {
      if (this != &Rset) {        
         if (Rset.record != nullptr) {
            delete[] record;
            recordNumber = Rset.recordNumber;
            record = new string[recordNumber]{};
            for (size_t i = 0; i < recordNumber; i++)
               record[i] = Rset.record[i];
         }
         else {
            record = nullptr;
            recordNumber = 0;
         }
      }
      return *this;
   }
   RecordSet::~RecordSet() {
      delete[] record;
   }
   size_t RecordSet::size() const {
      return recordNumber;
   }
   std::string RecordSet::getRecord(size_t number) const {
      return number < recordNumber ? record[number] : "";
   }
}