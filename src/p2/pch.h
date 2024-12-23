#pragma once

#ifdef SFML_STATIC
#define NOMINMAX

#include <SFML/Graphics.hpp>
#endif

#include <windows.h>

#include "resource.h"

#include "cstdio"

#ifdef _DEBUG
#include <crtdbg.h>
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW
#endif
