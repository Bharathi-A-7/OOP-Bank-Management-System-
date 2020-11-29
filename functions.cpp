#include "functions.h"
#include<stdio.h>


using namespace std;

string functions::date()
{
    time_t seconds = time (NULL);

    struct tm * timeinfo = localtime (&seconds);

    ostringstream oss;
    oss << (timeinfo->tm_year + 1900) << "-" << std::setw(2) << std::setfill('0') << (timeinfo->tm_mon + 1) << "-" << std::setw(2) << std::setfill('0') << timeinfo->tm_mday;
    string data = oss.str();

    return data;
}
