/**
   \file PIC24H.c
   \brief Functions relating to Microchip PIC24H (16-bit).
          For use with xc16 compiler.
   \author Andy Gock
 */
/*
	Copyright (c) 2013, Andy Gock

	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
		* Redistributions of source code must retain the above copyright
		  notice, this list of conditions and the following disclaimer.
		* Redistributions in binary form must reproduce the above copyright
		  notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
		* Neither the name of Andy Gock nor the
		  names of its contributors may be used to endorse or promote products
		  derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL ANDY GOCK BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef GLCD_PINOUTS_PIC24F_H_
#define GLCD_PINOUTS_PIC24F_H_

#if defined(GLCD_DEVICE_USER)
	#include "glcd_user_config.h"
	#include "glcd_user_config.c"
#else
	#if defined(GLCD_DEVICE_PIC24F)
		#include <stdint.h>
		#include <xc.h>
		#include <libpic30.h>

		#if defined(GLCD_CONTROLLER_PCD8544)
			/* Pin configuration for Microstick II board, PGE* switch in 'A' position */

			/**
			 * \name SPI port and pins. SPI1 port is used in \file PIC24F.c. Define
			 * the TRIS and PIN registers.
			 * @{
			 */
			#define CONTROLLER_MOSI_TRIS  _TRISB14
			#define CONTROLLER_MOSI_PIN   _LATB14
			#define CONTROLLER_SCK_TRIS   _TRISB15
			#define CONTROLLER_SCK_PIN    _LATAB15

			/* Output mapping for SPI1 (should be the same as above pins) */
			#define REGISTER_MAP_SPI_DO  _RP14R
			#define REGISTER_MAP_SPI_SCK _RP15R

			/**@}*/

			/**
			 * \name Other pins needed for serial LCD controller
			 * @{
			 */
			#define CONTROLLER_SS_TRIS   _TRISB2
			#define CONTROLLER_SS_PIN    _LATB2
			#define CONTROLLER_DC_TRIS   _TRISB3
			#define CONTROLLER_DC_PIN    _LATB3
			#define CONTROLLER_RST_TRIS  _TRISA2
			#define CONTROLLER_RST_PIN   _LATA2
			/**@}*/

		#elif defined(GLCD_CONTROLLER_ST7565R)
			//#error "ST7565R not supported on PIC24F"
			#if defined(GLCD_USE_SPI)
				/**
				 * \name SPI port and pins. SPI1 port is used in \file PIC24F.c. Define
				 * the TRIS and PIN registers.
				 * @{
				 */
				#define CONTROLLER_MOSI_TRIS  _TRISB14
				#define CONTROLLER_MOSI_PIN   _LATB14
				#define CONTROLLER_SCK_TRIS   _TRISB15
				#define CONTROLLER_SCK_PIN    _LATB15

				/* Output mapping for SPI1 (should be the same as above pins) */
				#define REGISTER_MAP_SPI_DO  _RP14R
				#define REGISTER_MAP_SPI_SCK _RP15R

				/**@}*/

				/**
				 * \name Other pins needed for serial LCD controller
				 * @{
				 */
				#define CONTROLLER_SS_TRIS   _TRISB2
				#define CONTROLLER_SS_PIN    _LATB2
				#define CONTROLLER_A0_TRIS   _TRISB3
				#define CONTROLLER_A0_PIN    _LATB3
				#define CONTROLLER_RST_TRIS  _TRISA2
				#define CONTROLLER_RST_PIN   _LATA2

				/**@}*/

			#elif defined(GLCD_USE_PARALLEL)
				/**
				 * \name port and pins for parallel mode
				 * @{
				 */
				#define CONTROLLER_DATA_DDR     TRISB
				#define CONTROLLER_DATA_PIN     PORTB
				#define CONTROLLER_DATA_PORT    LATB
                #define MASK_CON_DATA_PORT      0x00FF

                /**@}*/
	
				/**
				 * \name Other pins needed for LCD controller
				 * @{
				 */
				#if !defined(GLCD_DO_NOT_USE_CS)
					#define CONTROLLER_SS_DDR    _TRISA4	/**< DDR register for GLCD CS1 pin. */
					#define CONTROLLER_SS_PIN    _RA4   	/**< PIN register for GLCD CS1 pin. */
					#define CONTROLLER_SS_PORT   _LATA4     /**< PORT register for GLCD CS1 pin. */
				#endif
				#define CONTROLLER_RST_DDR   _TRISB8	/**< DDR register for GLCD RST pin. */
				#define CONTROLLER_RST_PIN   _RB8       /**< PIN register for GLCD RST pin. */
				#define CONTROLLER_RST_PORT  _LATB8     /**< PORT register for GLCD RST pin. */
				#define CONTROLLER_A0_DDR    _TRISB9	/**< DDR register for GLCD A0 pin. */
				#define CONTROLLER_A0_PIN    _RB9       /**< PIN register for GLCD A0 pin. */
				#define CONTROLLER_A0_PORT   _LATB9     /**< Pin number for A0 pin. */
				#define CONTROLLER_WR_DDR    _TRISB10	/**< DDR register for GLCD WR pin. */
				#define CONTROLLER_WR_PIN    _RB10      /**< PIN register for GLCD WR pin. */
				#define CONTROLLER_WR_PORT   _LATB10    /**< PORT register for GLCD WR pin. */
				#define CONTROLLER_RD_DDR    _TRISB11	/**< DDR register for GLCD RD pin. */
				#define CONTROLLER_RD_PIN    _RB11      /**< PIN register for GLCD RD pin. */
				#define CONTROLLER_RD_PORT   _LATB11 	/**< PORT register for GLCD RD pin. */
	
				/**@}*/

			#else
				#error "Not defined GLCD interface (SPI/PARALLEL)! Add definition for compiler - GLCD_USE_SPI or GLCD_USE_PARALLEL"
			#endif /* GLCD_MODE SPI/PARALLEL */

        #endif

	/**
	 * \name Macros for control lines
	 * @{
	 */
	#if defined(GLCD_DO_NOT_USE_CS)
		#define GLCD_SELECT()
		#define GLCD_DESELECT()
	#else
		#define GLCD_SELECT()     CONTROLLER_SS_PORT = 0
		#define GLCD_DESELECT()   CONTROLLER_SS_PORT = 1
	#endif
	#define GLCD_DC_LOW()     CONTROLLER_DC_PORT = 0
	#define GLCD_DC_HIGH()    CONTROLLER_DC_PORT = 1
	#define GLCD_RESET_LOW()  CONTROLLER_RST_PORT = 0
	#define GLCD_RESET_HIGH() CONTROLLER_RST_PORT = 1
	#define GLCD_A0_LOW()     CONTROLLER_A0_PORT = 0
	#define GLCD_A0_HIGH()    CONTROLLER_A0_PORT = 1
	#define GLCD_WR_LOW()     CONTROLLER_WR_PORT = 0
	#define GLCD_WR_HIGH()    CONTROLLER_WR_PORT = 1
	#define GLCD_RD_LOW()     CONTROLLER_RD_PORT = 0
	#define GLCD_RD_HIGH()    CONTROLLER_RD_PORT = 1

	/**@}*/

	#else
		#error "Controller not supported or defined in PIC24F module"
	#endif /* GLCD_DEVICE_PIC24F */

#endif /* GLCD_DEVICE_USER */

#endif /* GLCD_PINOUTS_PIC24H_H_ */
