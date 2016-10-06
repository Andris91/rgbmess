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

//base
#include "SDKDLL.h"

//colorcontrol

//base
#include "Effect.h"
#include "ContinuousEffect.h"
#include "FiniteEffect.h"

//impl
#include "CycleColorsEffect.h"

//ctrl
#include "RgbController.h"

//Util
#include "ColorUtil.h"
#include "rgb.h"
#include "hsv.h"
#include "Key.h"
#include "KeyRegion.h"