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
// switch/pal_config.h: Nintendo Switch specific header.
//          @Author: Chen Yang <adamyoung1234@outlook.com>, 2023.
//

#ifndef PAL_CONFIG_H
# define PAL_CONFIG_H

# define PAL_PREFIX            "data/"
# define PAL_SAVE_PREFIX       "save/"
# define PAL_CONFIG_PREFIX     "config/"
# define PAL_SCREENSHOT_PREFIX "screenshot/"

# define PAL_AUDIO_DEFAULT_BUFFER_SIZE   2048

# define PAL_HAS_JOYSTICKS     1
# define PAL_HAS_MOUSE         0
# define PAL_HAS_MP3           0
# define PAL_HAS_OGG           0
# define PAL_HAS_OPUS          0
# define PAL_HAS_TOUCH         0

# define PAL_DEFAULT_WINDOW_WIDTH   1280
# define PAL_DEFAULT_WINDOW_HEIGHT  720
# define PAL_DEFAULT_TEXTURE_WIDTH   640
# define PAL_DEFAULT_TEXTURE_HEIGHT  480

# define PAL_VIDEO_INIT_FLAGS  (SDL_WINDOW_SHOWN)

# define PAL_SDL_INIT_FLAGS	   (SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK)

# define PAL_PLATFORM         "Nintendo Switch"
# define PAL_CREDIT           "SoftStar"
# define PAL_PORTYEAR         "2023"

# define PAL_LARGE           static
# define PAL_FORCE_UPDATE_ON_PALETTE_SET

# define PAL_FILESYSTEM_IGNORE_CASE 0

# define PAL_SCALE_SCREEN   FALSE

// Switch buttons
#define JOY_A      0
#define JOY_B      1
#define JOY_X      2
#define JOY_Y      3
#define JOY_STICKL 4
#define JOY_STICKR 5
#define JOY_L      6
#define JOY_R      7
#define JOY_ZL     8
#define JOY_ZR     9
#define JOY_PLUS   10
#define JOY_MINUS  11
#define JOY_LEFT   12
#define JOY_UP     13
#define JOY_RIGHT  14
#define JOY_DOWN   15

# include <switch.h>

#endif
