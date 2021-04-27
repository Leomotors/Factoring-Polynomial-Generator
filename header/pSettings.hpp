#ifndef POLYNOMIAL_SETTINGS
#define POLYNOMIAL_SETTINGS

namespace pSettings
{
    void setNumRange(int);
    void setDenomRange(int);
    int getNumRange();
    int getDenomRange();
    bool cheatModeStatus();
    bool verboseModeStatus();
    void page();
}

#endif