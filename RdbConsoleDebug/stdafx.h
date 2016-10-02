// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <set>

//boost
#include "boost\thread.hpp"
#include "boost\chrono.hpp"

//Util
#include "ColorUtil.h"
#include "rgb.h"
#include "hsv.h"

//base
#include "SDKDLL.h"

//colorcontrol
#include "FadeInOutEffect.h"
#include "CycleColorsEffect.h"
#include "RgbController.h"
