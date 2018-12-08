#ifndef STRINGED_H
#define STRINGED_H

#include "mus_instrument.h"
#include <fstream>

class Stringed : public Mus_Instrument
{
private:
    string manufacturer;
    string description;
public:
    Stringed();
	void create_new ();
    void set_description (const string&);
    string get_description () const;
    void set_manufacturer (const string&);
    string get_manufacturer () const;
	void to_file(ofstream &) const;
    friend ostream& operator<< (ostream&, const Stringed&);
};

#endif //STRINGED_H
