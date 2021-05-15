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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_TYPE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_TYPE_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class NpcTypeFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "NpcType", "", luaNpcTypeCreate);
		registerMetaMethod(L, "NpcType", "__eq", luaUserdataCompare);

		registerMethod(L, "NpcType", "isPushable", luaNpcTypeIsPushable);
		registerMethod(L, "NpcType", "floorChange", luaNpcTypeFloorChange);

		registerMethod(L, "NpcType", "canSpawn", luaNpcTypeCanSpawn);

		registerMethod(L, "NpcType", "canPushItems", luaNpcTypeCanPushItems);
		registerMethod(L, "NpcType", "canPushCreatures", luaNpcTypeCanPushCreatures);

		registerMethod(L, "NpcType", "name", luaNpcTypeName);

		registerMethod(L, "NpcType", "nameDescription", luaNpcTypeNameDescription);

		registerMethod(L, "NpcType", "health", luaNpcTypeHealth);
		registerMethod(L, "NpcType", "maxHealth", luaNpcTypeMaxHealth);

		registerMethod(L, "NpcType", "getVoices", luaNpcTypeGetVoices);
		registerMethod(L, "NpcType", "addVoice", luaNpcTypeAddVoice);

		registerMethod(L, "NpcType", "getCreatureEvents", luaNpcTypeGetCreatureEvents);
		registerMethod(L, "NpcType", "registerEvent", luaNpcTypeRegisterEvent);

		registerMethod(L, "NpcType", "eventType", luaNpcTypeEventType);
		registerMethod(L, "NpcType", "onThink", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onAppear", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onDisappear", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onMove", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onSay", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onPlayerBuyItem", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onPlayerSellItem", luaNpcTypeEventOnCallback);
		registerMethod(L, "NpcType", "onPlayerCheckItem", luaNpcTypeEventOnCallback);

		registerMethod(L, "NpcType", "outfit", luaNpcTypeOutfit);
		registerMethod(L, "NpcType", "baseSpeed", luaNpcTypeBaseSpeed);
		registerMethod(L, "NpcType", "walkInterval", luaNpcTypeWalkInterval);
		registerMethod(L, "NpcType", "walkRadius", luaNpcTypeWalkRadius);
		registerMethod(L, "NpcType", "light", luaNpcTypeLight);

		registerMethod(L, "NpcType", "yellChance", luaNpcTypeYellChance);
		registerMethod(L, "NpcType", "yellSpeedTicks", luaNpcTypeYellSpeedTicks);

		registerMethod(L, "NpcType", "respawnTypePeriod", luaNpcTypeRespawnTypePeriod);
		registerMethod(L, "NpcType", "respawnTypeIsUnderground", luaNpcTypeRespawnTypeIsUnderground);

		registerMethod(L, "NpcType", "addShopItem", luaNpcTypeAddShopItem);
	}

private:
	static int luaNpcTypeCreate(lua_State* L);
	static int luaNpcTypeIsPushable(lua_State* L);
	static int luaNpcTypeFloorChange(lua_State* L);

	static int luaNpcTypeRespawnType(lua_State* L);
	static int luaNpcTypeCanSpawn(lua_State* L);

	static int luaNpcTypeCanPushItems(lua_State* L);
	static int luaNpcTypeCanPushCreatures(lua_State* L);

	static int luaNpcTypeName(lua_State* L);
	static int luaNpcTypeNameDescription(lua_State* L);

	static int luaNpcTypeHealth(lua_State* L);
	static int luaNpcTypeMaxHealth(lua_State* L);

	static int luaNpcTypeGetVoices(lua_State* L);
	static int luaNpcTypeAddVoice(lua_State* L);

	static int luaNpcTypeGetCreatureEvents(lua_State* L);
	static int luaNpcTypeRegisterEvent(lua_State* L);

	static int luaNpcTypeEventOnCallback(lua_State* L);
	static int luaNpcTypeEventType(lua_State* L);

	static int luaNpcTypeOutfit(lua_State* L);
	static int luaNpcTypeBaseSpeed(lua_State* L);
	static int luaNpcTypeWalkInterval(lua_State* L);
	static int luaNpcTypeWalkRadius(lua_State* L);
	static int luaNpcTypeLight(lua_State* L);

	static int luaNpcTypeYellChance(lua_State* L);
	static int luaNpcTypeYellSpeedTicks(lua_State* L);

	static int luaNpcTypeRespawnTypePeriod(lua_State* L);
	static int luaNpcTypeRespawnTypeIsUnderground(lua_State* L);

	static int luaNpcTypeAddShopItem(lua_State* L);

	friend class GameFunctions;
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_TYPE_FUNCTIONS_HPP_
