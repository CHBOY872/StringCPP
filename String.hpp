#ifndef STRING_HPP_SENTRY
#define STRING_HPP_SENTRY

class String {
	static int GetLen(const char *str);
	static void StrCopy(char *destination, const char *from);
	static String* dummy;
	static char* dummy_char;

	char *str;
	int len;
	int size;

public:
	String();
	String(const char *_str);
	String(const String& a);
	~String();
	
	int GetLen() { return len; }

	const char* operator*();
	char& operator[](int idx);
	String& operator=(const String& a);
	String& operator+=(const String& a); 
	String& operator-=(int len);
};

#endif
