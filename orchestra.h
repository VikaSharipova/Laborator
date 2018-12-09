#ifndef ORCHESTRA_H
#define ORCHESTRA_H

#include "percussion.h"
#include "stringed.h"
#include "brass.h"
#include "List.h"

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
	void remove (int, int);
	List<Stringed>* get_s();
	List<Brass>* get_b();
	List<Percussion>* get_p();
	void show();
	void save (string);
	void read (string);
	~Orchestra ();
};

#endif
