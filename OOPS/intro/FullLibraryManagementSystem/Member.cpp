#include "Member.h"
Member::Member(string i,string n,string t):Person(i,n),type(t){} string Member::getType()const{return type;}
