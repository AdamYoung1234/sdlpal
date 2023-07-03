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

/*
static const int g_KeyMap[][2] = {
   { SDLK_UP,        kKeyUp },
   { SDLK_DOWN,      kKeyDown },
   { SDLK_LEFT,      kKeyLeft },
   { SDLK_RIGHT,     kKeyRight },
   { SDLK_ESCAPE,    kKeyMenu },
   { SDLK_RETURN,    kKeySearch },
   { SDLK_PAGEUP,    kKeyPgUp },
   { SDLK_PAGEDOWN,  kKeyPgDn },
   { SDLK_HOME,      kKeyHome },
   { SDLK_END,       kKeyEnd },
   { SDLK_r,         kKeyRepeat },
   { SDLK_a,         kKeyAuto },
   { SDLK_d,         kKeyDefend },
   { SDLK_e,         kKeyUseItem },
   { SDLK_w,         kKeyThrowItem },
   { SDLK_q,         kKeyFlee },
   { SDLK_f,         kKeyForce },
   { SDLK_s,         kKeyStatus }
};
*/

/*
// Switch buttons
#define JOY_A     0
#define JOY_B     1
#define JOY_X     2
#define JOY_Y     3
#define JOY_PLUS  10
#define JOY_MINUS 11
#define JOY_LEFT  12
#define JOY_UP    13
#define JOY_RIGHT 14
#define JOY_DOWN  15
*/

static int input_event_filter(const SDL_Event *lpEvent, volatile PALINPUTSTATE *state)
{
	if (lpEvent->type == SDL_JOYBUTTONDOWN)
	{
		int button = lpEvent->jbutton.button;
		switch (button)
		{
			case JOY_UP:
				state->dwKeyPress = kKeyUp;
				break;
			case JOY_DOWN:
				state->dwKeyPress = kKeyDown;
				break;
			case JOY_LEFT:
				state->dwKeyPress = kKeyLeft;
				break;
			case JOY_RIGHT:
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
    chdir("romfs:/");
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
