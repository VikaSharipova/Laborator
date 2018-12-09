#ifndef MUS_INSTRUMENT_H
#define MUS_INSTRUMENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mus_Instrument
{
protected:
    string name;
    string owner;
    int cost;
    int quantity;
public:
    Mus_Instrument ();
    void set_name (const string&);
    void set_owner (const  string&);
    void set_cost (const int);
    void set_quantity (const int);
    string get_name () const;
    string get_owner () const;
    int get_cost () const;
    int get_quantity () const;
 };

#endif //MUS_INSTRUMENT_H
