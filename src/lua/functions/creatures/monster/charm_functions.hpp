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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_MONSTER_CHARM_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_MONSTER_CHARM_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class CharmFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "Charm", "", luaCharmCreate);
		registerMetaMethod(L, "Charm", "__eq", luaUserdataCompare);

		registerMethod(L, "Charm", "name", luaCharmName);
		registerMethod(L, "Charm", "description", luaCharmDescription);
		registerMethod(L, "Charm", "type", luaCharmType);
		registerMethod(L, "Charm", "points", luaCharmPoints);
		registerMethod(L, "Charm", "damageType", luaCharmDamageType);
		registerMethod(L, "Charm", "percentage", luaCharmPercentage);
		registerMethod(L, "Charm", "chance", luaCharmChance);
		registerMethod(L, "Charm", "cancelMessage", luaCharmCancelMessage);
		registerMethod(L, "Charm", "logMsg", luaCharmLogMsg);
		registerMethod(L, "Charm", "effect", luaCharmEffect);
	}

private:
	static int luaCharmCreate(lua_State* L);
	static int luaCharmName(lua_State* L);
	static int luaCharmDescription(lua_State* L);
	static int luaCharmType(lua_State* L);
	static int luaCharmPoints(lua_State* L);
	static int luaCharmDamageType(lua_State* L);
	static int luaCharmPercentage(lua_State* L);
	static int luaCharmChance(lua_State* L);
	static int luaCharmCancelMessage(lua_State* L);
	static int luaCharmLogMsg(lua_State* L);
	static int luaCharmEffect(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_MONSTER_CHARM_FUNCTIONS_HPP_
