#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

int main(int argc, char **argv)
{

    Vigenere v;

    v.setExplicitly();
    v.setKey();

    v.encryption();
    v.decryption();
    v.output();

   return 0;
}



