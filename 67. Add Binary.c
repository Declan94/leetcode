char* addBinary(char* a, char* b) {
    int p1 = strlen(a), p2 = strlen(b);
    char * c = malloc((p1>p2?p1:p2) + 2);
    int i = 0, carry = 0;
    int l;
    while (p1 > 0 || p2 > 0 || carry > 0) {
    	int v1 = p1 > 0 ? a[--p1] - '0' : 0;
    	int v2 = p2 > 0 ? b[--p2] - '0' : 0;
    	int v = v1 + v2 + carry;
    	carry = v / 2;
    	c[i++] = '0' + v % 2;
    }
    c[i] = '\0';
    l = i;
    for (i = 0; i < l/2; ++i)
    {
    	int j = l-1-i;
    	char temp = c[i];
    	c[i] = c[j];
    	c[j] = temp;
    }
    return c;
}