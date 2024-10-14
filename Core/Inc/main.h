/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#ifdef ESP_AS_SERVER
void ESP_Configuration (void);
void ESP_SendData (void);
#endif
#ifdef ESP_AS_CLIENT
void ESP8266_Init (void);
void ESP8266_SendServer (void);
#endif
char * ESP8266_SendCommand (uint8_t * command, char * moduleResponse);
void ESP8266_Connect_To_WiFi (uint8_t * wifi_name, uint8_t * password);
char * CheckForResponse (uint8_t * command, char * tmprep);
void ESP8266_Receive (void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */


#define DMAMAXCOUNTER 256

#define WIFI_NAME            "TOPNET_5EF0"    //WiFi name
#define WIFI_PASSWORD        "8nzafsn89k"    //WiFi password
                             
#define WIFI_DISCONNECTED    "WIFI DISCONNECT\r\n"
#define WIFI_CONNECTED       "WIFI CONNECTED\r\n"
#define WIFI_GOT_IP          "WIFI GOT IP\r\n"
                             
#define  __AT                "AT\r\n"                                         //Test the module response
#define  __RST               "AT+RST\r\n"                                     //Reset the module
#define  __CWMODE            "AT+CWMODE=3\r\n"                                //This command is used to set the WiFi Mode of \
                                                                              //operation as either Station mode, Soft Access \
                                                                              //Point (AP) or a combination of Station and AP.

#define  __SERVER_IP_WRITE   "GET https://api.thingspeak.com/update?api_key=8HTWNU31DSTD7YQ7&field1"
#define  __CIPSTART          "AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n" //This command is used to establish one \
                                                                              //of the three connections: TCP, UDP \
                                                                              //or SSL. Depending on the type of TCP\
                                                                              //Connection (single or multiple), the\
                                                                              //format of the Set command will vary.
                           
#define __CWMODE_SERVER      "AT+CWMODE=3\r\n"                            
#define __CIFSR              "AT+CIFSR\r\n"                                   //Returns the ip address of the ESP8266
#define __CIPMUUX            "AT+CIPMUX=1\r\n"                                //Allow multiple connections
#define __CIPSERVER          "AT+CIPSERVER=1,80\r\n"                               //AT+CIPSERVER
#define  __CIPCLOSE          "AT+CIPCLOSE\r\n"                                //To close the opened connection

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
