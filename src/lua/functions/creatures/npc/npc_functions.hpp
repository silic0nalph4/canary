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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_FUNCTIONS_HPP_

#include <set>

#include "lua/functions/creatures/npc/npc_type_functions.hpp"
#include "lua/scripts/luascript.h"

class NpcFunctions final : LuaScriptInterface
{
private:
	static void init(lua_State* L)
	{
		registerClass(L, "Npc", "Creature", luaNpcCreate);
		registerMetaMethod(L, "Npc", "__eq", luaUserdataCompare);
		registerMethod(L, "Npc", "isNpc", luaNpcIsNpc);
		registerMethod(L, "Npc", "setMasterPos", luaNpcSetMasterPos);
		registerMethod(L, "Npc", "getCurrency", luaNpcGetCurrency);
		registerMethod(L, "Npc", "getSpeechBubble", luaNpcGetSpeechBubble);
		registerMethod(L, "Npc", "setSpeechBubble", luaNpcSetSpeechBubble);
		registerMethod(L, "Npc", "getName", luaNpcGetName);
		registerMethod(L, "Npc", "setName", luaNpcSetName);
		registerMethod(L, "Npc", "place", luaNpcPlace);
		registerMethod(L, "Npc", "say", luaNpcSay);
		registerMethod(L, "Npc", "turnToCreature", luaNpcTurnToCreature);
		registerMethod(L, "Npc", "setPlayerInteraction", luaNpcSetPlayerInteraction);
		registerMethod(L, "Npc", "removePlayerInteraction", luaNpcRemovePlayerInteraction);
		registerMethod(L, "Npc", "isInteractingWithPlayer", luaNpcIsInteractingWithPlayer);
		registerMethod(L, "Npc", "isInTalkRange", luaNpcIsInTalkRange);
		registerMethod(L, "Npc", "isPlayerInteractingOnTopic", luaNpcIsPlayerInteractingOnTopic);
		registerMethod(L, "Npc", "openShopWindow", luaNpcOpenShopWindow);
		registerMethod(L, "Npc", "closeShopWindow", luaNpcCloseShopWindow);
		registerMethod(L, "Npc", "getShopItem", luaNpcGetShopItem);

		NpcTypeFunctions::init(L);
	}

	static int luaNpcCreate(lua_State* L);

	static int luaNpcIsNpc(lua_State* L);

	static int luaNpcSetMasterPos(lua_State* L);

	static int luaNpcGetCurrency(lua_State* L);
	static int luaNpcGetSpeechBubble(lua_State* L);
	static int luaNpcSetSpeechBubble(lua_State* L);
	static int luaNpcGetName(lua_State* L);
	static int luaNpcSetName(lua_State* L);
	static int luaNpcPlace(lua_State* L);
	static int luaNpcSay(lua_State* L);
	static int luaNpcTurnToCreature(lua_State* L);
	static int luaNpcSetPlayerInteraction(lua_State* L);
	static int luaNpcRemovePlayerInteraction(lua_State* L);
	static int luaNpcIsInteractingWithPlayer(lua_State* L);
	static int luaNpcIsInTalkRange(lua_State* L);
	static int luaNpcIsPlayerInteractingOnTopic(lua_State* L);
	static int luaNpcOpenShopWindow(lua_State* L);
	static int luaNpcCloseShopWindow(lua_State* L);
	static int luaNpcGetShopItem(lua_State* L);

	friend class CreatureFunctions;
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_NPC_NPC_FUNCTIONS_HPP_
