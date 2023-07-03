/* -*- mode: c; tab-width: 4; c-basic-offset: 4; c-file-style: "linux" -*- */
//
// Copyright (c) 2009-2011, Wei Mingzhi <whistler_wmz@users.sf.net>.
// Copyright (c) 2011-2023, SDLPAL development team.
// All rights reserved.
//
// This file is part of SDLPAL.
//
// SDLPAL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 3
// as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include "main.h"

static int input_event_filter(const SDL_Event *lpEvent, volatile PALINPUTSTATE *state)
{
	if (lpEvent->type == SDL_JOYBUTTONDOWN)
	{
		int button = lpEvent->jbutton.button;
		switch (button)
		{
			case JOY_UP:
            	state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : g_InputState.dir);
            	state->dir = kDirNorth;
            	g_InputState.dwKeyPress = kKeyUp;
				break;
			case JOY_DOWN:
            	state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : g_InputState.dir);
            	state->dir = kDirSouth;
            	state->dwKeyPress = kKeyDown;
				break;
			case JOY_LEFT:
         		state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : g_InputState.dir);
            	state->dir = kDirWest;
            	state->dwKeyPress = kKeyLeft;
				break;
			case JOY_RIGHT:
            	state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : g_InputState.dir);
            	state->dir = kDirEast;
            	state->dwKeyPress = kKeyRight;
				break;
			case JOY_A:
				state->dwKeyPress |= kKeySearch;
				break;
			case JOY_B:
				state->dwKeyPress |= kKeyMenu;
				break;
			case JOY_PLUS:
				state->dwKeyPress |= kKeyMenu;
				break;
		}
		return 1;
	}

	if (lpEvent->type == SDL_JOYBUTTONUP)
	{
		int button = lpEvent->jbutton.button;
		switch (button)
		{
			case JOY_UP:
				if(state->dir == kDirNorth || state->dir == kDirUnknown) {
					state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
					state->dir = kDirUnknown;
					state->dwKeyPress = kKeyNone;
				}
				break;
			case JOY_DOWN:
				if(state->dir == kDirSouth || state->dir == kDirUnknown) {
					state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
					state->dir = kDirUnknown;
					state->dwKeyPress = kKeyNone;
				}
				break;
			case JOY_LEFT:
				if(state->dir == kDirWest || state->dir == kDirUnknown) {
					state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
					state->dir = kDirUnknown;
					state->dwKeyPress = kKeyNone;
				}
				break;
			case JOY_RIGHT:
				if(state->dir == kDirEast || state->dir == kDirUnknown) {
					state->prevdir = (gpGlobals->fInBattle ? kDirUnknown : state->dir);
					state->dir = kDirUnknown;
					state->dwKeyPress = kKeyNone;
				}
				break;
		}
		return 1;
	}

	return 0;
}

BOOL
UTIL_GetScreenSize(
	DWORD *pdwScreenWidth,
	DWORD *pdwScreenHeight
)
{
	return FALSE;
}

BOOL
UTIL_IsAbsolutePath(
	LPCSTR  lpszFileName
)
{
	return FALSE;
}

INT
UTIL_Platform_Init(
	int argc,
	char* argv[]
)
{
	PAL_RegisterInputFilter(NULL, input_event_filter, NULL);
	gConfig.fLaunchSetting = FALSE;
   	socketInitializeDefault();
	nxlinkStdio();
	romfsInit();
	return 0;
}

VOID
UTIL_Platform_Quit(
	VOID
)
{
	romfsExit();
	// TODO: deinitialize most stuff here
}
