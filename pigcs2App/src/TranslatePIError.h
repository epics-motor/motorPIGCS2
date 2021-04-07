#ifndef _TRANSLATE_PI_ERROR_H
#define _TRANSLATE_PI_ERROR_H

#include <string>

std::string TranslatePIError(int32_t error);
bool TranslatePIError(int32_t error, char* szBuffer, uint32_t maxlen);

#endif // _TRANSLATE_PI_ERROR_H
