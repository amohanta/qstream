#include <memory.h>
#include "data.h"


char* CWData::getDataPtr(void)
{
	if(data.size()>0)
		return &data[0];
	else
		return NULL;
}

unsigned long CWData::getDataSize(void)
{
	return (unsigned long)data.size();
}

void CWData::addInt(int ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(int) );
	memcpy(&data[cpos],&ta,sizeof(int) );
}

void CWData::addUInt(unsigned int ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(unsigned int) );
	memcpy(&data[cpos],&ta,sizeof(unsigned int) );
}

void CWData::addInt64(_i64 ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(_i64) );
	memcpy(&data[cpos],&ta,sizeof(_i64) );
}

void CWData::addFloat(float ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(float) );
	memcpy(&data[cpos],&ta,sizeof(float) );
}

void CWData::addUShort(unsigned short ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(unsigned short) );
	memcpy(&data[cpos],&ta,sizeof(unsigned short) );
}	

void CWData::addString(std::string ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(unsigned int)+ta.size() );
	unsigned int len=(unsigned int)ta.size();
	memcpy(&data[cpos], &len, sizeof(unsigned int) );
	cpos+=sizeof(unsigned int);
	memcpy(&data[cpos],ta.c_str(), ta.size() );
}

void CWData::addChar(char ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(char) );
	data[cpos]=ta;
}

void CWData::addUChar(unsigned char ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(unsigned char) );
	data[cpos]=ta;
}

void CWData::addVoidPtr(void* ta)
{
	size_t cpos=data.size();
	data.resize(cpos+sizeof(void*) );
	memcpy(&data[cpos],&ta,sizeof(void*) );
}

void CWData::addBuffer(const char* buffer, size_t bsize)
{
	size_t cpos=data.size();
	data.resize(cpos+bsize);
	memcpy(&data[cpos], buffer, bsize);
}

CRData::CRData(const char* c,size_t datalength, bool pCopy)
{
	data=NULL;
	set(c,datalength, pCopy);
}

CRData::CRData(void)
{
	data=NULL;
	streampos=0;
	datalen=0;
}

void CRData::set(const char* c,size_t datalength, bool pCopy)
{
	copy=pCopy;
	if( copy==false )
	{
		data=c;
	}
	else
	{
		if( data!=NULL )
			delete [] data;
		data=new char[datalength];
		memcpy((void*)data, c, datalength);
	}
	streampos=0;
	datalen=datalength;
}

CRData::CRData(const std::string *str)
{
	set(str->c_str(), str->size(), false);
}

CRData::~CRData()
{
	if( copy==true )
		delete []data;
}

bool CRData::getInt(int *ret)
{
	if(streampos+sizeof(int)>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(int) );
	streampos+=sizeof(int);
	return true;
}

bool CRData::getInt64(_i64 *ret)
{
	if(streampos+sizeof(_i64)>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(_i64) );
	streampos+=sizeof(_i64);
	return true;
}

bool CRData::getUInt(unsigned int *ret)
{
	if(streampos+sizeof(unsigned int )>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(unsigned int ) );
	streampos+=sizeof(unsigned int);
	return true;
}
	
bool CRData::getFloat(float *ret)
{
	if(streampos+sizeof(float)>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(float) );
	streampos+=sizeof(float);
	return true;
}

bool CRData::getUShort( unsigned short *ret)
{
	if(streampos+sizeof(unsigned short)>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(unsigned short) );
	streampos+=sizeof(unsigned short);
	return true;	
}

bool CRData::getStr(std::string *ret)
{
	if(streampos+sizeof(unsigned int)>datalen )
	{
		return false;
	}

	unsigned int strlen;
	memcpy(&strlen,&data[streampos], sizeof(unsigned int) );
	streampos+=sizeof(unsigned int);

	if(streampos+strlen>datalen )
	{
		return false;
	}

	ret->resize(strlen);
	memcpy((char*)ret->c_str(), &data[streampos], strlen);
	streampos+=strlen;
	return true;
}

bool CRData::getChar(char *ret)
{
	if(streampos+sizeof(char)>datalen )
	{
		return false;
	}

	(*ret)=data[streampos];
	streampos+=sizeof(char);

	return true;
}

bool CRData::getUChar(unsigned char *ret)
{
	if(streampos+sizeof(unsigned char)>datalen )
	{
		return false;
	}

	(*ret)=data[streampos];
	streampos+=sizeof(unsigned char);

	return true;
}

bool CRData::getVoidPtr(void **ret)
{
	if(streampos+sizeof(void*)>datalen )
	{
		return false;
	}

	memcpy(ret, &data[streampos], sizeof(void*) );
	streampos+=sizeof(void*);
	return true;
}

unsigned int CRData::getSize(void)
{
	return (unsigned int)datalen;
}

unsigned int CRData::getLeft(void)
{
	return (unsigned int)(datalen-streampos);
}

unsigned int CRData::getStreampos(void)
{
	return (unsigned int)streampos;
}

const char *CRData::getDataPtr(void)
{
	return data;
}

const char *CRData::getCurrDataPtr(void)
{
	return data+streampos;
}

void CRData::setStreampos(unsigned int spos)
{
	if( spos <= datalen )
	{
		streampos=spos;
	}
}
