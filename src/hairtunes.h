#ifndef _HAIRTUNES_H_
#define _HAIRTUNES_H_

int hairtunes_init(char *pAeskey, char *pAesiv, char *pFmtpstr, int pCtrlPort, int pTimingPort,
         int pDataPort, char *pRtpHost, char*pPipeName, char *pLibaoDriver, char *pLibaoDeviceName, char *pLibaoDeviceId);
void hairtunes_setvolume(float vol);
void hairtunes_flush(void);
void hairtunes_cleanup(void);

// default buffer size
#define BUFFER_FRAMES  320

#endif 
