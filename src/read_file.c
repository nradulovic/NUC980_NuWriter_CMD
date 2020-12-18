#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/**
  * @brief      Load ddr file
  * @param      FilePath	file path
  * @param 	len		ddr length
  * @return     ddr buffer address
  * @details    This function read ddr into buffer.
  */
unsigned char* load_ddr(char *FilePath,unsigned int *len)
{
	FILE *pf;
	unsigned char *buf;
	char tmp[512];
	int tmpbuf_size;
	char *ptmp,cvt[128];
	unsigned int * puint32_t;
	unsigned int val=0;
	buf=malloc(sizeof(char)*512);
	memset(buf,0,512);
	puint32_t=(unsigned int *)buf;
	pf=fopen(FilePath, "rb");
	if(pf==NULL) {
		printf("cannot open %s\n",FilePath);
		*len = 0;
		return NULL;
	}
	tmpbuf_size=0;
	while(fgets(tmp,512,pf) != NULL) {
		ptmp=strchr(tmp,'=');
		strncpy((char *)cvt,(char *)tmp,(unsigned long)ptmp-(unsigned long)tmp);
		cvt[(unsigned long)ptmp-(unsigned long)tmp]='\0';
		val=strtoul(cvt,NULL,0);
		if(val==0xb0000000) continue;
		*puint32_t=val;
		puint32_t++;
		tmpbuf_size+=4;
        ++ptmp;
		strncpy(cvt,ptmp,strlen(ptmp));
		cvt[strlen(ptmp)]='\0';
		val=strtoul(cvt,NULL,0);
		*puint32_t=val;
		puint32_t++;
		tmpbuf_size+=4;
	}

	*len=tmpbuf_size;

	fclose(pf);
	return buf;
}


/**
  * @brief      Load xusb file
  * @param      FilePath	file path
  * @param 	len		xusb length
  * @return     xusb buffer address
  * @details    This function read xusb into buffer.
  */
unsigned char * load_xusb(char *FilePath,int *len)
{
	FILE *fp;
	unsigned char *buf;
	fp=fopen(FilePath, "rb");
	if(fp==NULL) {
		printf("cannot open %s\n",FilePath);
		*len = 0;
		return NULL;
	}
	fseek(fp,0,SEEK_END);
	*len=ftell(fp);
	fseek(fp,0,SEEK_SET);
	buf=malloc(sizeof(char)*(*len));
	fread(buf,1,*len,fp);
	fclose(fp);
	return buf;

}

