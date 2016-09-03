/*
	This source file is part of Rigs of Rods
	Copyright 2013-2016 Petr Ohlidal

	For more information, see http://www.rigsofrods.org/

	Rigs of Rods is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License version 3, as
	published by the Free Software Foundation.

	Rigs of Rods is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/** 
	@file   Application.h
	@author Petr Ohlidal
	@date   05/2014
	@brief  Central state/object manager and communications hub.
*/

#pragma once

#include "RoRPrerequisites.h"
#include "Settings.h"

namespace RoR {
namespace Application {

enum State
{
    APP_STATE_NONE,               ///< Only valid for GVar 'app_state_pending'. Means no change is requested.
    APP_STATE_BOOTSTRAP,          ///< Initial state
    APP_STATE_MAIN_MENU,
    APP_STATE_CHANGE_MAP,         ///< Enter main menu & immediatelly launch singleplayer map selector.
    APP_STATE_SIMULATION,
    APP_STATE_SHUTDOWN,
    APP_STATE_PRINT_HELP_EXIT,
    APP_STATE_PRINT_VERSION_EXIT,
};

enum MpState
{
    MP_STATE_NONE,      ///< Only valid for GVar 'app_state_pending'. Means no change is requested.
    MP_STATE_DISABLED,  ///< Not connected for whatever reason.
    MP_STATE_CONNECTED,
};

void Init();

// Getters
OgreSubsystem*       GetOgreSubsystem();
Settings&            GetSettings();
ContentManager*      GetContentManager();
OverlayWrapper*      GetOverlayWrapper();
SceneMouse*          GetSceneMouse();
GUIManager*          GetGuiManager();
GuiManagerInterface* GetGuiManagerInterface();
Console*             GetConsole();
InputEngine*         GetInputEngine();
CacheSystem*         GetCacheSystem();
MainThread*          GetMainThreadLogic();

State                GetActiveAppState();
State                GetPendingAppState();
std::string          GetActiveTerrain();
std::string          GetPendingTerrain();
MpState              GetActiveMpState();
MpState              GetPendingMpState();
std::string          GetMpServerHost();
std::string          GetMpServerPassword();
int                  GetMpServerPort();
std::string          GetMpPlayerName();
bool                 GetDiagTraceGlobals();

// Setters
void SetActiveAppState   (State               v);
void SetPendingAppState  (State               v);
void SetActiveTerrain    (std::string const & v);
void SetPendingTerrain   (std::string const & v);
void SetActiveMpState    (MpState             v);
void SetPendingMpState   (MpState             v);
void SetMpServerHost     (std::string const & v);
void SetMpServerPassword (std::string const & v);
void SetMpServerPort     (int         const & v);
void SetMpPlayerName     (std::string const & v);
void SetDiagTraceGlobals (bool                v);
void SetMainThreadLogic  (MainThread*       obj);

// Factories
void StartOgreSubsystem();
void ShutdownOgreSubsystem();
void CreateContentManager();
void DestroyContentManager();
void CreateOverlayWrapper();
void DestroyOverlayWrapper();
void CreateSceneMouse();
void DeleteSceneMouse();
void CreateGuiManagerIfNotExists();
void DeleteGuiManagerIfExists();
void CreateConsoleIfNotExists();
void DeleteConsoleIfExists();
void CreateInputEngine();
void CreateCacheSystem();

} // namespace Application
} // namespace RoR
