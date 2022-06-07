
// shared definitions and functions
// check SnmpMgr.c SnmpAgent.c

unsigned char errorStatus = 0, errorIndex = 0;
Boolean debug = FALSE;

int gethostaddr(char* hostname, struct sockaddr_in* sin)
{
	struct hostent* he;
	char machine_name[32];

	if (hostname == NULL || hostname[0] == '\x00')
	{
		if (gethostname(machine_name, sizeof(machine_name)))
			return FAIL;
	}
	else
		strcpy(machine_name, hostname);
	he = gethostbyname(machine_name);
	if (he == NULL) return FAIL;
	memset(sin, 0, sizeof(struct sockaddr_in));
	sin->sin_family = AF_INET;
	memmove(&sin->sin_addr, he->h_addr_list[0], he->h_length);
	return SUCCESS;
}