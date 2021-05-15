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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_CREATURE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_CREATURE_FUNCTIONS_HPP_

#include <set>

#include "lua/functions/creatures/combat/combat_functions.hpp"
#include "lua/functions/creatures/monster/monster_functions.hpp"
#include "lua/functions/creatures/npc/npc_functions.hpp"
#include "lua/functions/creatures/player/player_functions.hpp"
#include "lua/scripts/luascript.h"

class CreatureFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "Creature", "", luaCreatureCreate);
		registerMetaMethod(L, "Creature", "__eq", luaUserdataCompare);
		registerMethod(L, "Creature", "getEvents", luaCreatureGetEvents);
		registerMethod(L, "Creature", "registerEvent", luaCreatureRegisterEvent);
		registerMethod(L, "Creature", "unregisterEvent", luaCreatureUnregisterEvent);
		registerMethod(L, "Creature", "isRemoved", luaCreatureIsRemoved);
		registerMethod(L, "Creature", "isCreature", luaCreatureIsCreature);
		registerMethod(L, "Creature", "isInGhostMode", luaCreatureIsInGhostMode);
		registerMethod(L, "Creature", "isHealthHidden", luaCreatureIsHealthHidden);
		registerMethod(L, "Creature", "isImmune", luaCreatureIsImmune);
		registerMethod(L, "Creature", "canSee", luaCreatureCanSee);
		registerMethod(L, "Creature", "canSeeCreature", luaCreatureCanSeeCreature);
		registerMethod(L, "Creature", "getParent", luaCreatureGetParent);
		registerMethod(L, "Creature", "getId", luaCreatureGetId);
		registerMethod(L, "Creature", "getName", luaCreatureGetName);
		registerMethod(L, "Creature", "getTarget", luaCreatureGetTarget);
		registerMethod(L, "Creature", "setTarget", luaCreatureSetTarget);
		registerMethod(L, "Creature", "getFollowCreature", luaCreatureGetFollowCreature);
		registerMethod(L, "Creature", "setFollowCreature", luaCreatureSetFollowCreature);
		registerMethod(L, "Creature", "getMaster", luaCreatureGetMaster);
		registerMethod(L, "Creature", "setMaster", luaCreatureSetMaster);
		registerMethod(L, "Creature", "reload", luaCreatureReload);
		registerMethod(L, "Creature", "getLight", luaCreatureGetLight);
		registerMethod(L, "Creature", "setLight", luaCreatureSetLight);
		registerMethod(L, "Creature", "getSpeed", luaCreatureGetSpeed);
		registerMethod(L, "Creature", "getBaseSpeed", luaCreatureGetBaseSpeed);
		registerMethod(L, "Creature", "changeSpeed", luaCreatureChangeSpeed);
		registerMethod(L, "Creature", "setDropLoot", luaCreatureSetDropLoot);
		registerMethod(L, "Creature", "setSkillLoss", luaCreatureSetSkillLoss);
		registerMethod(L, "Creature", "getPosition", luaCreatureGetPosition);
		registerMethod(L, "Creature", "getTile", luaCreatureGetTile);
		registerMethod(L, "Creature", "getDirection", luaCreatureGetDirection);
		registerMethod(L, "Creature", "setDirection", luaCreatureSetDirection);
		registerMethod(L, "Creature", "getHealth", luaCreatureGetHealth);
		registerMethod(L, "Creature", "setHealth", luaCreatureSetHealth);
		registerMethod(L, "Creature", "addHealth", luaCreatureAddHealth);
		registerMethod(L, "Creature", "getMaxHealth", luaCreatureGetMaxHealth);
		registerMethod(L, "Creature", "setMaxHealth", luaCreatureSetMaxHealth);
		registerMethod(L, "Creature", "setHiddenHealth", luaCreatureSetHiddenHealth);
		registerMethod(L, "Creature", "isMoveLocked", luaCreatureIsMoveLocked);
		registerMethod(L, "Creature", "setMoveLocked", luaCreatureSetMoveLocked);
		registerMethod(L, "Creature", "getSkull", luaCreatureGetSkull);
		registerMethod(L, "Creature", "setSkull", luaCreatureSetSkull);
		registerMethod(L, "Creature", "getOutfit", luaCreatureGetOutfit);
		registerMethod(L, "Creature", "setOutfit", luaCreatureSetOutfit);
		registerMethod(L, "Creature", "getCondition", luaCreatureGetCondition);
		registerMethod(L, "Creature", "addCondition", luaCreatureAddCondition);
		registerMethod(L, "Creature", "removeCondition", luaCreatureRemoveCondition);
		registerMethod(L, "Creature", "hasCondition", luaCreatureHasCondition);
		registerMethod(L, "Creature", "remove", luaCreatureRemove);
		registerMethod(L, "Creature", "teleportTo", luaCreatureTeleportTo);
		registerMethod(L, "Creature", "say", luaCreatureSay);
		registerMethod(L, "Creature", "getDamageMap", luaCreatureGetDamageMap);
		registerMethod(L, "Creature", "getSummons", luaCreatureGetSummons);
		registerMethod(L, "Creature", "hasBeenSummoned", luaCreatureHasBeenSummoned);
		registerMethod(L, "Creature", "getDescription", luaCreatureGetDescription);
		registerMethod(L, "Creature", "getPathTo", luaCreatureGetPathTo);
		registerMethod(L, "Creature", "move", luaCreatureMove);
		registerMethod(L, "Creature", "getZone", luaCreatureGetZone);

		CombatFunctions::init(L);
		MonsterFunctions::init(L);
		NpcFunctions::init(L);
		PlayerFunctions::init(L);
	}

private:
	static int luaCreatureCreate(lua_State* L);

	static int luaCreatureGetEvents(lua_State* L);
	static int luaCreatureRegisterEvent(lua_State* L);
	static int luaCreatureUnregisterEvent(lua_State* L);

	static int luaCreatureIsRemoved(lua_State* L);
	static int luaCreatureIsCreature(lua_State* L);
	static int luaCreatureIsInGhostMode(lua_State* L);
	static int luaCreatureIsHealthHidden(lua_State* L);
	static int luaCreatureIsImmune(lua_State* L);

	static int luaCreatureCanSee(lua_State* L);
	static int luaCreatureCanSeeCreature(lua_State* L);

	static int luaCreatureGetParent(lua_State* L);

	static int luaCreatureGetId(lua_State* L);
	static int luaCreatureGetName(lua_State* L);

	static int luaCreatureGetTarget(lua_State* L);
	static int luaCreatureSetTarget(lua_State* L);

	static int luaCreatureGetFollowCreature(lua_State* L);
	static int luaCreatureSetFollowCreature(lua_State* L);

	static int luaCreatureGetMaster(lua_State* L);
	static int luaCreatureSetMaster(lua_State* L);

	static int luaCreatureReload(lua_State* L);

	static int luaCreatureGetLight(lua_State* L);
	static int luaCreatureSetLight(lua_State* L);

	static int luaCreatureGetSpeed(lua_State* L);
	static int luaCreatureGetBaseSpeed(lua_State* L);
	static int luaCreatureChangeSpeed(lua_State* L);

	static int luaCreatureSetDropLoot(lua_State* L);
	static int luaCreatureSetSkillLoss(lua_State* L);

	static int luaCreatureGetPosition(lua_State* L);
	static int luaCreatureGetTile(lua_State* L);
	static int luaCreatureGetDirection(lua_State* L);
	static int luaCreatureSetDirection(lua_State* L);

	static int luaCreatureGetHealth(lua_State* L);
	static int luaCreatureSetHealth(lua_State* L);
	static int luaCreatureAddHealth(lua_State* L);
	static int luaCreatureGetMaxHealth(lua_State* L);
	static int luaCreatureSetMaxHealth(lua_State* L);
	static int luaCreatureSetHiddenHealth(lua_State* L);

	static int luaCreatureIsMoveLocked(lua_State* L);
	static int luaCreatureSetMoveLocked(lua_State* L);

	static int luaCreatureGetSkull(lua_State* L);
	static int luaCreatureSetSkull(lua_State* L);

	static int luaCreatureGetOutfit(lua_State* L);
	static int luaCreatureSetOutfit(lua_State* L);

	static int luaCreatureGetCondition(lua_State* L);
	static int luaCreatureAddCondition(lua_State* L);
	static int luaCreatureHasCondition(lua_State* L);
	static int luaCreatureRemoveCondition(lua_State* L);

	static int luaCreatureRemove(lua_State* L);
	static int luaCreatureTeleportTo(lua_State* L);
	static int luaCreatureSay(lua_State* L);

	static int luaCreatureGetDamageMap(lua_State* L);

	static int luaCreatureGetSummons(lua_State* L);
	static int luaCreatureHasBeenSummoned(lua_State* L);

	static int luaCreatureGetDescription(lua_State* L);

	static int luaCreatureGetPathTo(lua_State* L);
	static int luaCreatureMove(lua_State* L);

	static int luaCreatureGetZone(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_CREATURE_FUNCTIONS_HPP_
