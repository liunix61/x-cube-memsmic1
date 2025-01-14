/**
  ******************************************************************************
  * @file    usbd_conf.h
  * @author  SRA
  * @version v1.2.0
  * @date    17-Sep-2021
  * @brief   General low level driver configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF_H
#define __USBD_CONF_H

#ifdef __cplusplus
extern "C" {
#endif


/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Common Config */
#define USBD_MAX_NUM_INTERFACES               1
#define USBD_MAX_NUM_CONFIGURATION            1
#define USBD_MAX_STR_DESC_SIZ                 0x100
#define USBD_SUPPORT_USER_STRING_DESC         1
#define USBD_SELF_POWERED                     1
#define USBD_DEBUG_LEVEL                      0

/* Exported macro ------------------------------------------------------------*/
/* Memory management macros */
#define USBD_malloc               malloc
#define USBD_free                 free
#define USBD_memset               memset
#define USBD_memcpy               memcpy

/* DEBUG macros */
#if (USBD_DEBUG_LEVEL > 0)
#define  USBD_UsrLog(...)   printf(__VA_ARGS__);\
  printf("\n");
#else
#define USBD_UsrLog(...)
#endif /* (USBD_DEBUG_LEVEL > 0) */

#if (USBD_DEBUG_LEVEL > 1)
#define  USBD_ErrLog(...)   printf("ERROR: ") ;\
  printf(__VA_ARGS__);\
  printf("\n");
#else
#define USBD_ErrLog(...)
#endif /* (USBD_DEBUG_LEVEL > 1) */

#if (USBD_DEBUG_LEVEL > 2)
#define  USBD_DbgLog(...)   printf("DEBUG : ") ;\
  printf(__VA_ARGS__);\
  printf("\n");
#else
#define USBD_DbgLog(...)
#endif /* (USBD_DEBUG_LEVEL > 2) */

/* Exported functions ------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* __USBD_CONF_H */


