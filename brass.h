#ifndef BRASS_H
#define BRASS_H

#include "mus_instrument.h"
#include <fstream>

class Brass : public Mus_Instrument
{
private:
    string defects;
    string manufacturer;
public:
    Brass();
	void create_new ();
    void set_defects (const string&);
    string get_defects () const;
    void set_manufacturer (const string&);
    string get_manufacturer () const;
	void to_file(ofstream &) const;
    friend ostream& operator<< (ostream&, const Brass&);
};

#endif //BRASS_H
