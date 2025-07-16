#ifndef SSD_CONTROL_H
#define SSD_CONTROL_H

void SSD_Init(void);
void SSD_Disable(void);
void SSD_Enable(u8 digit);
void SSD_Write(u8 number);
void SSD_SendPattern(u8 digit);
void SSD_Refresh(u8 number);

#endif
