#include "func.h"

double get_gc_content(const string& dna)
{
    int gc_count = 0;
    for (char nucleotide : dna)
    {
        if (nucleotide == 'C' || nucleotide == 'G')
        {
            gc_count++;
        }
    }

    return static_cast<double>(gc_count) / dna.size();
}

string get_reverse_string(string dna)
{
    string reversed = "";
    for (int i = dna.size() - 1; i >= 0; i--)
    {
        reversed += dna[i];
    }
    return reversed;
}

string get_dna_complement(string dna)
{
    string reversed_dna = get_reverse_string(dna);
    for (char &nucleotide : reversed_dna)
    {
        switch (nucleotide)
        {
        case 'A':
            nucleotide = 'T';
            break;
        case 'T':
            nucleotide = 'A';
            break;
        case 'C':
            nucleotide = 'G';
            break;
        case 'G':
            nucleotide = 'C';
            break;
        }
    }
    return reversed_dna;
}
