// restituisce la mediana di un insieme ordinato di double
// data: array di double
// used: int che indica il num di elementi usati
double mediana_double(double data[], int used);

// dev. std. di array di double con int used come numero di dati usati
// data: array di dati
// used: numero di dati usati nell'array
double devstd_double(double data[], int used);

// dev. std. di array di double con double used come numero di dati usati
// data: array di dati
// used: numero di dati usati nell'array
double media_double(double data[], int used);

// Funzione che restituisca l'index del valore minimo.
// data: array di dati double
// i: index del primo elemento da cui parte la ricerca
// j: index dell'ultimo elemento in cui finisce la ricerca
int pos_of_min_double(double data[], int i, int j);

// Algoritmo che implementa il selection sort.
// data: array di dati double
// used: int che indica il numero di elementi usati nell'array
void selection_sort_double(double data[], int used);

// conta il numero di elementi in un file
// file_name: const char* path/to/file
int count_file_elements(const char *file_name);

// funzione per stampare i dati da array double su file
void print(const char *file_name, double *data, int n_dati);

// funzione per stampare gli elementi di un array di double a video
void print(const double *, int);