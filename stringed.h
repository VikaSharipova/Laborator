#ifndef STRINGED_H
#define STRINGED_H

#include "mus_instrument.h"

class Stringed : public Mus_Instrument
{
private:
    string manufacturer;
    string description;
public:
    Stringed();
	void create_new ();
    void set_description (string&);
    string get_description ();
    void set_manufacturer (string&);
    string get_manufacturer ();
	void to_file(ofstream &);
    void show ();
};

#endif //STRINGED_H
