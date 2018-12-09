#ifndef PERCUSSION_H
#define PERCUSSION_H

#include "mus_instrument.h"

class Percussion : public Mus_Instrument
{
private:
    string type;
public:
    Percussion();
	void create_new ();
    void set_type (string&);
    string get_type ();
	void to_file(ofstream &);
    void show ();
};

#endif //PERCUSSION_H

