/**
 * Canary - A free and open-source MMORPG server emulator
 * Copyright (C) 2021 OpenTibiaBR <opentibiabr@outlook.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef SRC_LUA_FUNCTIONS_MAP_HOUSE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_MAP_HOUSE_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class HouseFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "House", "", luaHouseCreate);
		registerMetaMethod(L, "House", "__eq", luaUserdataCompare);

		registerMethod(L, "House", "getId", luaHouseGetId);
		registerMethod(L, "House", "getName", luaHouseGetName);
		registerMethod(L, "House", "getTown", luaHouseGetTown);
		registerMethod(L, "House", "getExitPosition", luaHouseGetExitPosition);
		registerMethod(L, "House", "getRent", luaHouseGetRent);

		registerMethod(L, "House", "getOwnerGuid", luaHouseGetOwnerGuid);
		registerMethod(L, "House", "setOwnerGuid", luaHouseSetOwnerGuid);
		registerMethod(L, "House", "startTrade", luaHouseStartTrade);

		registerMethod(L, "House", "getBeds", luaHouseGetBeds);
		registerMethod(L, "House", "getBedCount", luaHouseGetBedCount);

		registerMethod(L, "House", "getDoors", luaHouseGetDoors);
		registerMethod(L, "House", "getDoorCount", luaHouseGetDoorCount);
		registerMethod(L, "House", "getDoorIdByPosition", luaHouseGetDoorIdByPosition);

		registerMethod(L, "House", "getTiles", luaHouseGetTiles);
		registerMethod(L, "House", "getItems", luaHouseGetItems);
		registerMethod(L, "House", "getTileCount", luaHouseGetTileCount);

		registerMethod(L, "House", "canEditAccessList", luaHouseCanEditAccessList);
		registerMethod(L, "House", "getAccessList", luaHouseGetAccessList);
		registerMethod(L, "House", "setAccessList", luaHouseSetAccessList);

		registerMethod(L, "House", "kickPlayer", luaHouseKickPlayer);
		registerMethod(L, "House", "isInvited", luaHouseIsInvited);
	}

private:
	static int luaHouseCreate(lua_State* L);

	static int luaHouseGetId(lua_State* L);
	static int luaHouseGetName(lua_State* L);
	static int luaHouseGetTown(lua_State* L);
	static int luaHouseGetExitPosition(lua_State* L);
	static int luaHouseGetRent(lua_State* L);

	static int luaHouseGetOwnerGuid(lua_State* L);
	static int luaHouseSetOwnerGuid(lua_State* L);
	static int luaHouseStartTrade(lua_State* L);

	static int luaHouseGetBeds(lua_State* L);
	static int luaHouseGetBedCount(lua_State* L);

	static int luaHouseGetDoors(lua_State* L);
	static int luaHouseGetDoorCount(lua_State* L);
	static int luaHouseGetDoorIdByPosition(lua_State* L);

	static int luaHouseGetTiles(lua_State* L);
	static int luaHouseGetItems(lua_State* L);
	static int luaHouseGetTileCount(lua_State* L);

	static int luaHouseCanEditAccessList(lua_State* L);
	static int luaHouseGetAccessList(lua_State* L);
	static int luaHouseSetAccessList(lua_State* L);

	static int luaHouseKickPlayer(lua_State* L);
	static int luaHouseIsInvited(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_MAP_HOUSE_FUNCTIONS_HPP_
