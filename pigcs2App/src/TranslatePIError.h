#ifndef _TRANSLATE_PI_ERROR_H
#define _TRANSLATE_PI_ERROR_H

#include <string>
#include <epicsTypes.h>

std::string TranslatePIError(epicsInt32 error);
bool TranslatePIError(epicsInt32 error, char* szBuffer, epicsUInt32 maxlen);

#endif // _TRANSLATE_PI_ERROR_H
