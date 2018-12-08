#ifndef PERCUSSION_H
#define PERCUSSION_H

#include "mus_instrument.h"
#include <fstream>

class Percussion : public Mus_Instrument
{
private:
    string type;
public:
    Percussion();
	void create_new ();
    void set_type (const string&);
    string get_type () const;
	void to_file(ofstream &) const;
    friend ostream& operator<< (ostream&, const Percussion&);
};

#endif //PERCUSSION_H
