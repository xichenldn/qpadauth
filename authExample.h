#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#define _CRT_SECURE_NO_WARNINGS			// wcscpy warning overwise

#include <windows.h>

#define LIBRARY_API extern "C" __declspec(dllexport)

LIBRARY_API LPCWSTR WINAPI GetAuthMethodName();

LIBRARY_API int WINAPI GetCredentialString(LPCWSTR strConnString, LPWSTR pCredentials, DWORD dwLength);
