#pragma once

#define SDL_MAIN_HANDLED
#ifdef _WIN32
#include "SDL.h" // IWYU pragma: export
#include "SDL_syswm.h" // IWYU pragma: export
#else
#include "SDL.h" // IWYU pragma: export
#include "SDL_syswm.h" // IWYU pragma: export
// Undefine x11 macros that get included by SDL_syswm.h.
#undef None
#undef Status
#undef LockMask
#undef ControlMask
#undef Success
#undef Always
#endif
