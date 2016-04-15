#include <iostream>
#include <string>
#include "sdes.h"

using namespace std;

int main(int argc, char **argv)
{
    string key;
    string msg;

    getline(cin, msg);
    getline(cin, key);

    SDES s;
    s.setKey(key);
    s.getKey();
    s.showResult();

    return 0;
}
