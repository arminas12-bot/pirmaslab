#pragma once
#include "mylib.h"

bool failiukasvektorius(vector <Studentas>& Grupe, string failassupavadinimu);
bool failiukassarasas(list <Studentas>& Grupe, string failassupavadinimu);

void atvaizdvektorius(vector <Studentas>& Grupe);
void atvaizdsarasas(list <Studentas>& Grupe);

double galutinis(const Studentas& s, bool imammediana);


void pirmastr_vector(const vector <Studentas>& in, vector<Studentas>& varg, vector <Studentas>& kiet, bool imammediana);
void pirmastr_list(const list <Studentas>& in, list<Studentas>& varg, list <Studentas>& kiet, bool imammediana);
