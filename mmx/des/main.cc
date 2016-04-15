#include "des.h"

int main(int argc, char *argv[])
{
    DES des;
    des.setKey("!2bcde<~");
    des.setPlainText("ABs5EFGH");
    des.genEncKey();
    des.encryption();
    des.decryption();
    des.showResult();
    return 0;
}
