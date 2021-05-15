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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_FUNCTIONS_HPP_

#include <set>

#include "lua/scripts/luascript.h"
#include "lua/functions/creatures/monster/charm_functions.hpp"
#include "lua/functions/creatures/monster/loot_functions.hpp"
#include "lua/functions/creatures/monster/monster_spell_functions.hpp"
#include "lua/functions/creatures/monster/monster_type_functions.hpp"

class MonsterFunctions final : LuaScriptInterface
{
private:
	static void init(lua_State* L)
	{
		registerClass(L, "Monster", "Creature", luaMonsterCreate);
		registerMetaMethod(L, "Monster", "__eq", luaUserdataCompare);
		registerMethod(L, "Monster", "isMonster", luaMonsterIsMonster);
		registerMethod(L, "Monster", "getType", luaMonsterGetType);
		registerMethod(L, "Monster", "setType", luaMonsterSetType);
		registerMethod(L, "Monster", "getSpawnPosition", luaMonsterGetSpawnPosition);
		registerMethod(L, "Monster", "isInSpawnRange", luaMonsterIsInSpawnRange);
		registerMethod(L, "Monster", "isIdle", luaMonsterIsIdle);
		registerMethod(L, "Monster", "setIdle", luaMonsterSetIdle);
		registerMethod(L, "Monster", "isTarget", luaMonsterIsTarget);
		registerMethod(L, "Monster", "isOpponent", luaMonsterIsOpponent);
		registerMethod(L, "Monster", "isFriend", luaMonsterIsFriend);
		registerMethod(L, "Monster", "addFriend", luaMonsterAddFriend);
		registerMethod(L, "Monster", "removeFriend", luaMonsterRemoveFriend);
		registerMethod(L, "Monster", "getFriendList", luaMonsterGetFriendList);
		registerMethod(L, "Monster", "getFriendCount", luaMonsterGetFriendCount);
		registerMethod(L, "Monster", "addTarget", luaMonsterAddTarget);
		registerMethod(L, "Monster", "removeTarget", luaMonsterRemoveTarget);
		registerMethod(L, "Monster", "getTargetList", luaMonsterGetTargetList);
		registerMethod(L, "Monster", "getTargetCount", luaMonsterGetTargetCount);
		registerMethod(L, "Monster", "changeTargetDistance", luaMonsterChangeTargetDistance);
		registerMethod(L, "Monster", "selectTarget", luaMonsterSelectTarget);
		registerMethod(L, "Monster", "searchTarget", luaMonsterSearchTarget);
		registerMethod(L, "Monster", "setSpawnPosition", luaMonsterSetSpawnPosition);
		registerMethod(L, "Monster", "getRespawnType", luaMonsterGetRespawnType);

		CharmFunctions::init(L);
		LootFunctions::init(L);
		MonsterSpellFunctions::init(L);
		MonsterTypeFunctions::init(L);
	}

	static int luaMonsterCreate(lua_State* L);

	static int luaMonsterIsMonster(lua_State* L);

	static int luaMonsterGetType(lua_State* L);
	static int luaMonsterSetType(lua_State* L);

	static int luaMonsterGetSpawnPosition(lua_State* L);
	static int luaMonsterIsInSpawnRange(lua_State* L);

	static int luaMonsterIsIdle(lua_State* L);
	static int luaMonsterSetIdle(lua_State* L);

	static int luaMonsterIsTarget(lua_State* L);
	static int luaMonsterIsOpponent(lua_State* L);
	static int luaMonsterIsFriend(lua_State* L);

	static int luaMonsterAddFriend(lua_State* L);
	static int luaMonsterRemoveFriend(lua_State* L);
	static int luaMonsterGetFriendList(lua_State* L);
	static int luaMonsterGetFriendCount(lua_State* L);

	static int luaMonsterAddTarget(lua_State* L);
	static int luaMonsterRemoveTarget(lua_State* L);
	static int luaMonsterGetTargetList(lua_State* L);
	static int luaMonsterGetTargetCount(lua_State* L);

	static int luaMonsterChangeTargetDistance(lua_State* L);

	static int luaMonsterSelectTarget(lua_State* L);
	static int luaMonsterSearchTarget(lua_State* L);

	static int luaMonsterSetSpawnPosition(lua_State* L);
	static int luaMonsterGetRespawnType(lua_State* L);

	friend class CreatureFunctions;
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_FUNCTIONS_HPP_
