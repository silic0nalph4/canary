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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_PLAYER_VOCATION_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_PLAYER_VOCATION_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class VocationFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "Vocation", "", luaVocationCreate);
		registerMetaMethod(L, "Vocation", "__eq", luaUserdataCompare);

		registerMethod(L, "Vocation", "getId", luaVocationGetId);
		registerMethod(L, "Vocation", "getClientId", luaVocationGetClientId);
		registerMethod(L, "Vocation", "getName", luaVocationGetName);
		registerMethod(L, "Vocation", "getDescription", luaVocationGetDescription);

		registerMethod(L, "Vocation", "getRequiredSkillTries", luaVocationGetRequiredSkillTries);
		registerMethod(L, "Vocation", "getRequiredManaSpent", luaVocationGetRequiredManaSpent);

		registerMethod(L, "Vocation", "getCapacityGain", luaVocationGetCapacityGain);

		registerMethod(L, "Vocation", "getHealthGain", luaVocationGetHealthGain);
		registerMethod(L, "Vocation", "getHealthGainTicks", luaVocationGetHealthGainTicks);
		registerMethod(L, "Vocation", "getHealthGainAmount", luaVocationGetHealthGainAmount);

		registerMethod(L, "Vocation", "getManaGain", luaVocationGetManaGain);
		registerMethod(L, "Vocation", "getManaGainTicks", luaVocationGetManaGainTicks);
		registerMethod(L, "Vocation", "getManaGainAmount", luaVocationGetManaGainAmount);

		registerMethod(L, "Vocation", "getMaxSoul", luaVocationGetMaxSoul);
		registerMethod(L, "Vocation", "getSoulGainTicks", luaVocationGetSoulGainTicks);

		registerMethod(L, "Vocation", "getAttackSpeed", luaVocationGetAttackSpeed);
		registerMethod(L, "Vocation", "getBaseSpeed", luaVocationGetBaseSpeed);

		registerMethod(L, "Vocation", "getDemotion", luaVocationGetDemotion);
		registerMethod(L, "Vocation", "getPromotion", luaVocationGetPromotion);
	}

private:
	static int luaVocationCreate(lua_State* L);

	static int luaVocationGetId(lua_State* L);
	static int luaVocationGetClientId(lua_State* L);
	static int luaVocationGetName(lua_State* L);
	static int luaVocationGetDescription(lua_State* L);

	static int luaVocationGetRequiredSkillTries(lua_State* L);
	static int luaVocationGetRequiredManaSpent(lua_State* L);

	static int luaVocationGetCapacityGain(lua_State* L);

	static int luaVocationGetHealthGain(lua_State* L);
	static int luaVocationGetHealthGainTicks(lua_State* L);
	static int luaVocationGetHealthGainAmount(lua_State* L);

	static int luaVocationGetManaGain(lua_State* L);
	static int luaVocationGetManaGainTicks(lua_State* L);
	static int luaVocationGetManaGainAmount(lua_State* L);

	static int luaVocationGetMaxSoul(lua_State* L);
	static int luaVocationGetSoulGainTicks(lua_State* L);

	static int luaVocationGetAttackSpeed(lua_State* L);
	static int luaVocationGetBaseSpeed(lua_State* L);

	static int luaVocationGetDemotion(lua_State* L);
	static int luaVocationGetPromotion(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_PLAYER_VOCATION_FUNCTIONS_HPP_
