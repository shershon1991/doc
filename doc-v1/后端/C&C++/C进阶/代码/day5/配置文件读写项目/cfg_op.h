#ifndef __CFG_OP_H__
#define __CFG_OP_H__

#ifdef __cplusplus
extern "C"
{
#endif

          //获取配置项
          int getCfgItem(char *pFileName /*in*/, char *pKey /*in*/, char *pValue /*out*/, int *pValueLen /*out*/);

          //写配置项
          int writeCfgItem(char *pFileName /*in*/, char *pItemName /*in*/, char *pItemValue /*in*/, int itemValueLen /*in*/);

#ifdef __cplusplus
}
#endif

#endif
