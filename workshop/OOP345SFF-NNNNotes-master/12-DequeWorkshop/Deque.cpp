#include <utility>
#include "Deque.h"

unsigned int Deque::m_serial = 0;
unsigned int Deque::serial() {
  return m_serial;
}
Qnode::Qnode(const double& data, Qnode* prev, Qnode* next):
  m_data(data), m_next(next),m_prev(prev){}


Deque::Deque(){
  m_serial++;
}
Deque::Deque(unsigned int size) : Deque(size, {}) {
  m_serial++;
}
Deque::Deque(unsigned int size, const double& data){
  while (size--) {
    (push_back(data));
  }
  m_serial++;
}
Deque::Deque(const Deque& Q){
  operator=(Q);
  m_serial++;

}
Deque::Deque(Deque&& Q){
  operator=(std::move(Q));
  m_serial++;
}
Deque::~Deque(){
  clear();
  m_serial--;
}
Deque& Deque::operator=(const Deque& Q) {
  clear();
  for (unsigned int i = {}; i < Q.size(); push_back(Q[i++]));
  return *this;
}
Deque& Deque::operator=(Deque&& Q){
  clear();
  m_head = Q.m_head;
  m_tail = Q.m_tail;
  m_size = Q.m_size;
  Q.m_head = Q.m_tail = nullptr;
  Q.m_size = 0;
  return *this;
}
unsigned int Deque::size()const{
  return m_size;
}
bool Deque::empty()const{
  return m_head == nullptr;
}
double& Deque::operator[](unsigned int index){
  if (empty())push_back({});
  index %= size();
  Qnode* cur = m_head;
  for (unsigned int i = 0; i < index; i++, cur = cur->m_next);
  return cur->m_data;
}
const double& Deque::operator[](unsigned int index)const{
  index %= size();
  Qnode* cur = m_head;
  for (unsigned int i = 0; i < index; i++, cur = cur->m_next);
  return cur->m_data;
}
double& Deque::front(){
  return m_head->m_data;
}
const double& Deque::front()const{
  return m_head->m_data;
}
double& Deque::back(){
  return m_tail->m_data;
}
const double& Deque::back()const{
  return m_tail->m_data;
}
void Deque::push_back(const double& data){
  Qnode* new_tail = new Qnode(data, m_tail);
  if (m_head)  // not empty, at least one
    m_tail = m_tail->m_next = new_tail;
  else
    m_head = m_tail = new_tail;

  m_size++;
}
void Deque::push_front(const double& data){
  Qnode* new_head = new Qnode(data, nullptr, m_head);
  if (m_tail)
    m_head = m_head->m_prev = new_head;
  else
    m_tail = m_head = new_head;
  m_size++;
}
void Deque::pop_back(){
  if (m_tail) { // if (!empty()){
    if (m_tail == m_head) m_head = nullptr;
    Qnode* toDelete = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = nullptr;
    delete toDelete;
    m_size--;
  }
}
void Deque::pop_front(){
  if (m_head) { // if (!empty()){
    if (m_tail == m_head) m_tail = nullptr;
    Qnode* toDelete = m_head;
    m_head = m_head->m_next;
    m_head->m_prev = nullptr;
    delete toDelete;
    m_size--;
  }
}
void Deque::clear(){
  Qnode* toDel = m_head;
  while (toDel){
    m_head = m_head->m_next;
    delete toDel;
    toDel = m_head;
  }
  m_size = 0;
}


