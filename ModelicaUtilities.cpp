
#include "ModelicaUtilities.h"
#include "importer.h"

extern "C" {

//Declaration of functions that need to be exported by tool vendors
//These declarations are required to compile for Linux, for Windows
//they aren't really required
void ModelicaMessageImpl(const char *str);
void ModelicaVFormatMessageImpl(const char *str, va_list args);
void ModelicaErrorImpl(const char *str);
void ModelicaWarningImpl(const char *str);
void ModelicaVFormatWarningImpl(const char *str, va_list args);
void ModelicaVFormatErrorImpl(const char *str, va_list args);
char* ModelicaAllocateStringImpl(size_t len);
char* ModelicaDuplicateStringImpl(const char *str);
char* ModelicaAllocateStringWithErrorReturnImpl(size_t len);

void ModelicaMessage(const char *str)
{
    IMPORT(void (*)(const char *), ModelicaMessageImpl);
    ModelicaMessageImpl(str);
}

void ModelicaFormatMessage(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    ModelicaVFormatMessage(str, args);
    va_end(args);
}

void ModelicaVFormatMessage(const char *str, va_list args)
{
    IMPORT(void (*)(const char *, va_list), ModelicaVFormatMessageImpl);
    ModelicaVFormatMessageImpl(str, args);
}

void ModelicaError(const char *str)
{
    IMPORT(void (*)(const char *), ModelicaErrorImpl);
    ModelicaErrorImpl(str);
}

void ModelicaWarning(const char *str)
{
    IMPORT(void (*)(const char *), ModelicaWarningImpl);
    ModelicaWarningImpl(str);
}

void ModelicaFormatWarning(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    ModelicaVFormatWarning(str, args);
    va_end(args);
}

void ModelicaVFormatWarning(const char *str, va_list args)
{
    IMPORT(void (*)(const char *, va_list), ModelicaVFormatWarningImpl);
    ModelicaVFormatWarningImpl(str, args);
}

void ModelicaFormatError(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    ModelicaVFormatError(str, args);
    va_end(args);
}

void ModelicaVFormatError(const char *str, va_list args)
{
    IMPORT(void (*)(const char *, va_list), ModelicaVFormatErrorImpl);
    ModelicaVFormatErrorImpl(str, args);
}

char* ModelicaAllocateString(size_t len)
{
    IMPORT(char *(*)(size_t), ModelicaAllocateStringImpl);
    return ModelicaAllocateStringImpl(len);
}

char* ModelicaDuplicateString(const char *str)
{
    IMPORT(char *(*)(const char *),ModelicaDuplicateStringImpl);
    return ModelicaDuplicateStringImpl(str);
}

char* ModelicaAllocateStringWithErrorReturn(size_t len)
{
    IMPORT(char *(*)(size_t),ModelicaAllocateStringWithErrorReturnImpl);
    return ModelicaAllocateStringWithErrorReturnImpl(len);
}
    
} //extern "C"
