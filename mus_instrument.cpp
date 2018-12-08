#include "mus_instrument.h"

Mus_Instrument::Mus_Instrument() {
    name = "неизвестно";
    owner = "неизвестно";
    cost = 0;
    quantity = 0;
}

void Mus_Instrument::set_name(const string& s) {
    name = s;
}

void Mus_Instrument::set_owner(const string& s) {
    owner = s;
}

void Mus_Instrument::set_cost(const int a) {
    cost = a;
}

void Mus_Instrument::set_quantity(const int a) {
    quantity = a;
}

string Mus_Instrument::get_name() const {
    return name;
}

string Mus_Instrument::get_owner() const {
    return owner;
}

int Mus_Instrument::get_cost() const {
    return cost;
}

int Mus_Instrument::get_quantity() const {
    return quantity;
}











