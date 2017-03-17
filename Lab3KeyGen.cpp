// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <WS2tcpip.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "IPHLPAPI.lib")

int main()
{
	int i = 0;
	//Password Number 1
	char psw[] = { 'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '\0'};
	for (i = 0; i < 12; i++) {
		psw[i] += 5;
	}
	fprintf(stderr, "Password 1:\n%s\n", psw);

	//Password Number 2
	char psw2[] = { 'A', 'R', 'C', 'H', 'I', 'E', 'M', 'I', 'L', 'L', 'E', 'R', '\0' };
	for (i = 0; i < 12; i++) {
		psw2[i] = psw2[i] - i;
	}
	fprintf(stderr, "Password 2:\n%s\n", psw2);

	//Password Number 3

	char psw3[] = { 'G', 'O', ' ', 'F', 'L', 'Y', 'E', 'R', 'S', '!', '!', '!', '\0'};
	for (i = 0; i < 12; i++) {
		psw3[i] = psw3[i] ^ i;
	}

	fprintf(stderr, "Password 3:\n%s\n", psw3);

    // Password Number 4
	DWORD snum = 0;
	GetVolumeInformation(_T("C:\\"), NULL, NULL, &snum, NULL, NULL, NULL, NULL);

	fprintf(stderr, "Password 4:\n%d\n", snum);

	// Password Number 5
	PIP_ADAPTER_ADDRESSES addresses = NULL;
	ULONG buffLen = 15000;

	addresses = (PIP_ADAPTER_ADDRESSES)malloc(buffLen);
	GetAdaptersAddresses(2, NULL, NULL, addresses, &buffLen);
	
	fprintf(stderr,"Password 5:\n%02X%02X%02X%02X\n", addresses->PhysicalAddress[3], 
		addresses->PhysicalAddress[2], addresses->PhysicalAddress[1], addresses->PhysicalAddress[0]);
	
	system("pause");
}

