#ifndef BRASS_H
#define BRASS_H

#include "mus_instrument.h"

class Brass : public Mus_Instrument
{
private:
    string defects;
    string manufacturer;
public:
    Brass();
	void create_new ();
    void set_defects (string&);
    string get_defects ();
    void set_manufacturer (string&);
    string get_manufacturer ();
	void to_file (ofstream &);
    void show ();
};

#endif //BRASS_H
