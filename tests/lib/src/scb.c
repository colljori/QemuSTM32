/*
 * scb.c
 *
 *  Created on: 12-06-2013
 *      Author: Tomek
 */

#include <scb.h>

/* reset system */
void SCB_Reset(void)
{
	SCB->AIRCR = SCB_AIRCR_VECTKEYSTAT | SCB_AIRCR_SYSRESETREQ;
}
