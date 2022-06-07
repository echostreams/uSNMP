#ifndef SERIAL_H
#define SERIAL_H


#include <stdio.h>

#define HEX 1

class SoftwareSerial
{
public:
	static inline void print(const char* str)
	{
		printf("%s", str);
	}

	static inline void print(int val)
	{
		printf("%d", val);
	}

	static inline void println(unsigned char byte, int hex)
	{
		if (hex == HEX)
			printf("%02x\n", byte);
		else
			printf("%d\n", byte);
	}

	static inline void print(unsigned char byte, int hex)
	{
		if (hex == HEX)
			printf("%02x", byte);
		else
			printf("%d", byte);
	}

	static inline void println(const char* str = NULL)
	{
		if (str != NULL)
			printf("%s\n", str);
		else
			printf("\n");
	}

	static inline void println(int val)
	{
		printf("%d\n", val);
	}
};

#endif