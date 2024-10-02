//01/10/2024 by Matteo Fava
//funzione per gestire input

#pragma once
#include "vect.h"

int count_file_elements(const char* file_name);

Vect file_to_vect(const char* file_name, int n);

//print to terminal
void print(Vect& v);

//print to file
void print(Vect& v, const char* file_name);