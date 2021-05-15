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

#ifndef SRC_LUA_FUNCTIONS_CORE_GAME_GAME_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CORE_GAME_GAME_FUNCTIONS_HPP_

#include <set>

#include "lua/scripts/lua_environment.hpp"
#include "lua/scripts/luascript.h"

extern LuaEnvironment g_luaEnvironment;

class GameFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerTable(L, "Game");

		registerMethod(L, "Game", "createNpcType", luaGameCreateNpcType);
		registerMethod(L, "Game", "createMonsterType", luaGameCreateMonsterType);

		registerMethod(L, "Game", "getEventSLoot", luaGamegetEventSLoot);
		registerMethod(L, "Game", "getEventSSkill", luaGamegetEventSSkill);
		registerMethod(L, "Game", "getEventSExp", luaGamegetEventSExp);

		registerMethod(L, "Game", "getSpectators", luaGameGetSpectators);

		registerMethod(L, "Game", "getBoostedCreature", luaGameGetBoostedCreature);
		registerMethod(L, "Game", "getBestiaryList", luaGameGetBestiaryList);

		registerMethod(L, "Game", "getPlayers", luaGameGetPlayers);
		registerMethod(L, "Game", "loadMap", luaGameLoadMap);

		registerMethod(L, "Game", "getMonsterCount", luaGameGetMonsterCount);
		registerMethod(L, "Game", "getPlayerCount", luaGameGetPlayerCount);
		registerMethod(L, "Game", "getNpcCount", luaGameGetNpcCount);
		registerMethod(L, "Game", "getMonsterTypes", luaGameGetMonsterTypes);

		registerMethod(L, "Game", "getTowns", luaGameGetTowns);
		registerMethod(L, "Game", "getHouses", luaGameGetHouses);

		registerMethod(L, "Game", "getGameState", luaGameGetGameState);
		registerMethod(L, "Game", "setGameState", luaGameSetGameState);

		registerMethod(L, "Game", "getWorldType", luaGameGetWorldType);
		registerMethod(L, "Game", "setWorldType", luaGameSetWorldType);

		registerMethod(L, "Game", "getReturnMessage", luaGameGetReturnMessage);

		registerMethod(L, "Game", "createItem", luaGameCreateItem);
		registerMethod(L, "Game", "createContainer", luaGameCreateContainer);
		registerMethod(L, "Game", "createMonster", luaGameCreateMonster);
		registerMethod(L, "Game", "createNpc", luaGameCreateNpc);
		registerMethod(L, "Game", "generateNpc", luaGameGenerateNpc);
		registerMethod(L, "Game", "createTile", luaGameCreateTile);
		registerMethod(L, "Game", "createBestiaryCharm", luaGameCreateBestiaryCharm);

		registerMethod(L, "Game", "getBestiaryCharm", luaGameGetBestiaryCharm);

		registerMethod(L, "Game", "startRaid", luaGameStartRaid);

		registerMethod(L, "Game", "getClientVersion", luaGameGetClientVersion);

		registerMethod(L, "Game", "reload", luaGameReload);

		registerMethod(L, "Game", "getItemIdByClientId", luaGameGetItemByClientId);

		registerMethod(L, "Game", "itemidHasMoveevent", luaGameItemidHasMoveevent);
		registerMethod(L, "Game", "hasDistanceEffect", luaGameHasDistanceEffect);
		registerMethod(L, "Game", "hasEffect", luaGameHasEffect);
		registerMethod(L, "Game", "getOfflinePlayer", luaGameGetOfflinePlayer);
	}

private:
	static int luaGameCreateMonsterType(lua_State* L);
	static int luaGameCreateNpcType(lua_State* L);

	static int luaGamegetEventSLoot(lua_State* L);
	static int luaGamegetEventSSkill(lua_State* L);
	static int luaGamegetEventSExp(lua_State* L);

	static int luaGameGetSpectators(lua_State* L);

	static int luaGameGetBoostedCreature(lua_State* L);
	static int luaGameGetBestiaryList(lua_State* L);

	static int luaGameGetPlayers(lua_State* L);
	static int luaGameLoadMap(lua_State* L);

	static int luaGameGetMonsterCount(lua_State* L);
	static int luaGameGetPlayerCount(lua_State* L);
	static int luaGameGetNpcCount(lua_State* L);
	static int luaGameGetMonsterTypes(lua_State* L);

	static int luaGameGetTowns(lua_State* L);
	static int luaGameGetHouses(lua_State* L);

	static int luaGameGetGameState(lua_State* L);
	static int luaGameSetGameState(lua_State* L);

	static int luaGameGetWorldType(lua_State* L);
	static int luaGameSetWorldType(lua_State* L);

	static int luaGameGetReturnMessage(lua_State* L);

	static int luaGameCreateItem(lua_State* L);
	static int luaGameCreateContainer(lua_State* L);
	static int luaGameCreateMonster(lua_State* L);
	static int luaGameGenerateNpc(lua_State* L);
	static int luaGameCreateNpc(lua_State* L);
	static int luaGameCreateTile(lua_State* L);

	static int luaGameGetBestiaryCharm(lua_State* L);
	static int luaGameCreateBestiaryCharm(lua_State* L);

	static int luaGameStartRaid(lua_State* L);

	static int luaGameGetClientVersion(lua_State* L);

	static int luaGameReload(lua_State* L);

	static int luaGameGetItemByClientId(lua_State* L);
	static int luaGameGetOfflinePlayer(lua_State* L);
	static int luaGameItemidHasMoveevent(lua_State* L);
	static int luaGameHasEffect(lua_State* L);
	static int luaGameHasDistanceEffect(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CORE_GAME_GAME_FUNCTIONS_HPP_
