#include "AuthExample.h"

#include "targetver.h"

#include <Lmcons.h>	// UNLEN constant defined here
#include <array>

using namespace std;

wstring GetLogin()
{
	WCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserNameW(username, &username_len);
	return wstring(username);
}

LPCWSTR __stdcall GetAuthMethodName()
{
	
	return L"XiAuthMethod";

}

int __stdcall GetCredentialString(LPCWSTR strConnString, LPWSTR pCredentials, DWORD dwLength)
{
	wstring login = GetLogin();
	wstring res;

	res.append(login);
	res.append(L":");
	if (0==wcscmp(strConnString,L"prod"))
	{
		res.append(L"123");
	}
	else
	{
		res.append(L"456");
	}

	if (dwLength>wcslen(res.c_str()))
	{
		wcscpy(pCredentials, res.c_str());
		return 0;
	};
	return wcslen(res.c_str());
}
