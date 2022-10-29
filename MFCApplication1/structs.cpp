#include "pch.h"
#include "structs.h"

void Account::savings(int32_t amount)
{
	_balance += amount;
}

void Account::withdrawal(int32_t amount)
{
	_balance -= amount;
}

void Account::changePassword(const CString& newPass)
{
	_password = newPass;
}
