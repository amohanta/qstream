#ifndef DATA_H_
#define DATA_H_

#include <string>
#include <vector>

typedef long long int _i64;

class CWData
{
public:
	char* getDataPtr(void);
	unsigned long getDataSize(void);

	void addInt(int ta);
	void addUInt(unsigned int ta);
	void addInt64(_i64 ta);
	void addFloat(float ta);
	void addUShort(unsigned short ta);
	void addString(std::string ta);
	void addChar(char ta);
	void addUChar(unsigned char ta);
	void addVoidPtr(void *ptr);
	void addBuffer(const char* buffer, size_t bsize);

private:
	std::vector<char> data;
};

class CRData
{
public:
	CRData(const char* c,size_t datalength, bool pCopy=false);
	CRData(const std::string *str);
	CRData(void);
	~CRData();
	
	void set(const char* c,size_t datalength, bool pCopy=false);

	bool getInt(int *ret);
	bool getInt64(_i64 *ret);
	bool getUInt(unsigned int *ret);
	bool getFloat(float *ret);
	bool getUShort( unsigned short *ret);
	bool getStr(std::string *ret);
	bool getChar(char *ret);
	bool getUChar(unsigned char *ret);
	bool getVoidPtr(void **ret);

	unsigned int getSize(void);
	unsigned int getLeft(void);
	unsigned int getStreampos(void);
	void setStreampos(unsigned int spos);
	const char *getDataPtr(void);
	const char *getCurrDataPtr(void);

private:

	const char* data;
	size_t streampos;
	size_t datalen;
	
	bool copy;
};


#endif //DATA_H_
