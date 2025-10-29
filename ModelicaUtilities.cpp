
#include "ModelicaUtilities.h"
#include "importer.h"
#include <cstdlib>

extern "C" {

void ModelicaMessage(const char *str)
{
    auto ptr=tryImportSymbol<void (*)(const char *)>("ModelicaMessage");
    if(ptr!=nullptr) ptr(str);
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
    auto ptr=tryImportSymbol<void (*)(const char *, va_list)>("ModelicaVFormatMessage");
    if(ptr!=nullptr) ptr(str, args);
}

void ModelicaError(const char *str)
{
    auto ptr=tryImportSymbol<void (*)(const char *)>("ModelicaError");
    if(ptr!=nullptr) ptr(str);
    //ModelicaError must not return even if the pointer is null
    std::abort();
}

void ModelicaWarning(const char *str)
{
    auto ptr=tryImportSymbol<void (*)(const char *)>("ModelicaWarning");
    if(ptr!=nullptr) ptr(str);
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
    auto ptr=tryImportSymbol<void (*)(const char *, va_list)>("ModelicaVFormatWarning");
    if(ptr!=nullptr) ptr(str, args);
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
    auto ptr=tryImportSymbol<void (*)(const char *, va_list)>("ModelicaVFormatError");
    if(ptr!=nullptr) ptr(str, args);
    //ModelicaVFormatError must not return even if the pointer is null
    std::abort();
}

char* ModelicaAllocateString(size_t len)
{
    auto ptr=tryImportSymbol<char *(*)(size_t)>("ModelicaAllocateString");
    if(ptr!=nullptr) return ptr(len);
    else return nullptr;
}

char* ModelicaDuplicateString(const char *str)
{
    auto ptr=tryImportSymbol<char *(*)(const char *)>("ModelicaDuplicateString");
    if(ptr!=nullptr) return ptr(str);
    else return nullptr;
}

char* ModelicaAllocateStringWithErrorReturn(size_t len)
{
    auto ptr=tryImportSymbol<char *(*)(size_t)>("ModelicaAllocateStringWithErrorReturn");
    if(ptr!=nullptr) return ptr(len);
    else return nullptr;
}
    
} //extern "C"
