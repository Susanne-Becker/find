/***
 * helpers.c
 *
 * Find needle in haystack: Je zegt welk nummer je wilt vinden en vult nummers in.
 * Wanneer je het nummer wat je zoekt staat tussen de nummers die je gevonden hebt,
 * heb je de needle in de haystack gevonden.
 *
 * Gemaakt door: Susanne Becker
 */

// Helper functions

#include <cs50.h>

#include "helpers.h"

// Returns true if value is in array of n values, else false
bool search(int value, int values[], int n)
{
    int left = 0;
    int right = n - 1;

    // Binary search algorithm
    while (left <= right)
    {
        //midden indexeren
        int middle = left + (right - left) / 2;
        // Als middelste value gelijk is aan de gezochte value: return true
        if (values[middle] == value)
        {
            return true;
        }
        // als middelste value groter is dan gezochte value: zoek links
        else if (values[middle] > value)
        {
            right = middle - 1;
        }
        // als middelste value groter is dan gezochte value: zoek rechts
        else
        {
            left = middle + 1;
        }

    }
    // als value niet gevonden wordt, return false
    return false;
}

// Sorts array of n values
void sort(int values[], int n)
{
    //for loop om te sorteren
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1])
            {
                //Swap waarden
                int swap = values[j];
                values[j] = values[j + 1];
                values[j + 1] = swap;
            }
        }
    }
}
