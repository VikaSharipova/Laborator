#ifndef ORCHESTRA_H
#define ORCHESTRA_H

#include "percussion.h"
#include "stringed.h"
#include "brass.h"
#include "List.h"
#include <fstream>

using namespace std;

class Orchestra
{
protected:
	List<Stringed>* data_s;
	List<Brass>* data_b;
	List<Percussion>* data_p;
public:
	Orchestra ();
	void add (Stringed*);
	void add (Brass*);
	void add (Percussion*);
	void remove (const int, const int);
	void show() const;
	void save (const string) const;
	void read (const string);
	~Orchestra ();
};

#endif