/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 2002         SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

**** emWin/GSC Grafical user interface for embedded applications ****
emWin is protected by international copyright laws. Knowledge of the
source code may not be used to write a similar product. This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : GUI_SetTextMode.c
Purpose     : Implementation of optional routines
---------------------------END-OF-HEADER------------------------------
*/


#include "GUI_Protected.H"


int GUI_SetTextMode(int Mode) {
  int r;
  GUI_LOCK();
  r = GUI_Context.TextMode;
  GUI_Context.TextMode = Mode;
  GUI_UNLOCK();
  return r;
}



