#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _SCK_HANDLE
{
          char version[64];
          char ip[128];
          int port;
          unsigned char *p;
          int plen;
} SCK_HANDLE;

//-----------------------------------第一套API函数 start-----------------------------------------------//
//客户端初始化
int cltSocketInit(void **handle /*out*/)
{
          int ret = 0;
          SCK_HANDLE *hdl = NULL;

          printf("func cltSocketInit() begin \n");

          hdl = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
          if (hdl == NULL)
          {
                    ret = -1;
                    printf("func cltSocketInit() err:%d \n", ret);
                    return ret;
          }
          memset(hdl, 0, sizeof(SCK_HANDLE)); //把指针指向的内存空间置为0

          strcpy(hdl->ip, "192.168.220.26");
          hdl->port = 8081;
          *handle = hdl;

          printf("func cltSocketInit() end \n");
          return ret;
}

//客户端发报文
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/, int buflen /*in*/)
{
          int ret = 0;
          SCK_HANDLE *hdl = NULL;

          if (handle == NULL || buf == NULL)
          {
                    ret = -1;
                    printf("func cltSocketSend() err(handle or buf is NULL) :%d \n", ret);
                    return ret;
          }

          hdl = (SCK_HANDLE *)handle;

          hdl->p = (unsigned char *)malloc(buflen * sizeof(unsigned char));
          if (hdl->p == NULL)
          {
                    ret = -2;
                    printf("func cltSocketSend() err:%d \n", ret);
                    return ret;
          }
          memcpy(hdl->p, buf, buflen);
          hdl->plen = buflen;

          return ret;
}

//客户端收报文
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
          int ret = 0;
          SCK_HANDLE *hdl = NULL;

          if (handle == NULL || buf == NULL || buflen == NULL)
          {
                    ret = -1;
                    printf("func cltSocketRev() err(handle or buf or buflen is NULL) :%d \n", ret);
                    return ret;
          }
          hdl = (SCK_HANDLE *)handle;

          memcpy(buf, hdl->p, hdl->plen);
          *buflen = hdl->plen;

          return ret;
}

//客户端释放资源
int cltSocketDestory(void *handle /*in*/)
{
          int ret = 0;
          SCK_HANDLE *hdl = NULL;

          if (handle == NULL)
          {
                    ret = -1;
                    printf("func cltSocketDestory() err(handle is NULL) :%d \n", ret);
                    return ret;
          }
          hdl = (SCK_HANDLE *)handle;

          if (hdl->p)
          {
                    free(hdl->p);
          }
          free(hdl);

          return ret;
}
//-----------------------------------第一套API函数 end-----------------------------------------------//

int main1()
{
          int ret = 0;
          void *handle = NULL;
          char buf[128];
          int buflen = 3;
          char outbuf[128];
          int outbuflen = 3;
          strcpy(buf, "asdasdadsadsa");

          //客户端初始化
          ret = cltSocketInit(&handle /*out*/);
          if (ret != 0)
          {
                    printf("func cltSocketInit() err:%d \n", ret);
                    return ret;
          }

          //客户端发报文
          ret = cltSocketSend(handle /*in*/, buf /*in*/, buflen /*in*/);
          if (ret != 0)
          {
                    printf("func cltSocketSend() err:%d \n", ret);
                    return ret;
          }

          //客户端收报文
          ret = cltSocketRev(handle /*in*/, outbuf /*in*/, &outbuflen /*in*/);
          if (ret != 0)
          {
                    printf("func cltSocketSend() err:%d \n", ret);
                    return ret;
          }

          //客户端释放资源
          int cltSocketDestory(handle /*in*/);

          system("pause");
          return ret;
}

//-----------------------------------第二套API函数 start-----------------------------------------------//
int cltSocketInit2(void **handle)
{
          return cltSocketInit(handle);
}

int cltSocketSend2(void *handle, unsigned char *buf, int buflen)
{
          return cltSocketSend(handle, buf, buflen);
}

int cltSocketRev2(void *handle, unsigned char **buf, int *buflen)
{
          int ret = 0;
          SCK_HANDLE *hdl = NULL;
          unsigned char *tmp = NULL;

          if (handle == NULL || buf == NULL || buflen == NULL)
          {
                    ret = -1;
                    printf("func cltSocketRev2() err(handle or buf or buflen is NULL) :%d \n", ret);
                    return ret;
          }
          hdl = (SCK_HANDLE *)handle;

          tmp = (unsigned char *)malloc(hdl->plen);
          if (tmp == NULL)
          {
                    ret = -2;
                    printf("func cltSocketRev2() err(malloc err) :%d \n", ret);
                    return ret;
          }

          memcpy(tmp, hdl->p, hdl->plen);
          *buflen = hdl->plen;
          *buf = tmp;

          return ret;
}

int cltSocketRev2_Free(char **buf)
{
          if (buf == NULL)
          {
                    return -1;
          }
          if (*buf != NULL)
          {
                    free(*buf);
          }
          *buf = NULL;

          return 0;
}

int cltSOcketDestory2(void **handle)
{
          SCK_HANDLE *tmp = NULL;

          if (handle == NULL)
          {
                    return -1;
          }
          tmp = *handle;
          if (tmp != NULL)
          {
                    if (tmp->p)
                    {
                              free(tmp->p);
                              tmp->p = NULL;
                    }
                    free(tmp);
          }
          *handle = NULL;

          return 0;
}
//-----------------------------------第二套API函数 end-----------------------------------------------//

void main()
{
          int ret = 0;
          void *handle = NULL;

          char buf[128];
          int buflen = 3;

          char *pout = NULL;
          int poutlen = 0;
          strcpy(buf, "sadadadaadsasd");

          ret = cltSocketInit2(&handle);

          ret = cltSocketSend2(handle, buf, buflen);

          ret = cltSocketRev2(handle, &pout, &poutlen);
          cltSocketRev2_Free(&pout);

          //ret = cltSocketRev2_Free(&pout);

          ret = cltSOcketDestory2(&handle);

          system("pause");
          return;
}
