#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person { protected: string id, name; public: Person(string id="", string name=""); virtual ~Person() = default; string getId() const; string getName() const; };
#endif
