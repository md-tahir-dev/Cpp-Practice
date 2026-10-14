#ifndef MEMBER_H
#define MEMBER_H
#include "Person.h"
class Member:public Person { protected: string type; public: Member(string id="",string name="",string type="General"); string getType()const; };
#endif
