#include "woke.h"


int main(int argc, const char *argv[])
{
    Translator file;
    file.setFileName(argv[1]);
    file.translator();

    cout << "\nTranslation Finished\nNo Error Encountered"<< endl;
    return 0;
}
