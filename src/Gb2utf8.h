#ifndef Gb2utf8_H
#define Gb2utf8_H

#ifdef __cplusplus
extern "C" {
#endif

int UTF8ToGB(const char *inbuf, int inlen, char *outbuf, int outlen);
int GBToUTF8(const char *inbuf, int inlen, char *outbuf, int outlen);

#ifdef __cplusplus
}
#endif

#endif /*MD5_H*/
