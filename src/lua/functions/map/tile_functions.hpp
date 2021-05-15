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

#ifndef SRC_LUA_FUNCTIONS_MAP_TILE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_MAP_TILE_FUNCTIONS_HPP_

#include <set>

#include "lua/scripts/luascript.h"

class TileFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "Tile", "", luaTileCreate);
		registerMetaMethod(L, "Tile", "__eq", luaUserdataCompare);

		registerMethod(L, "Tile", "getPosition", luaTileGetPosition);
		registerMethod(L, "Tile", "getGround", luaTileGetGround);
		registerMethod(L, "Tile", "getThing", luaTileGetThing);
		registerMethod(L, "Tile", "getThingCount", luaTileGetThingCount);
		registerMethod(L, "Tile", "getTopVisibleThing", luaTileGetTopVisibleThing);

		registerMethod(L, "Tile", "getTopTopItem", luaTileGetTopTopItem);
		registerMethod(L, "Tile", "getTopDownItem", luaTileGetTopDownItem);
		registerMethod(L, "Tile", "getFieldItem", luaTileGetFieldItem);

		registerMethod(L, "Tile", "getItemById", luaTileGetItemById);
		registerMethod(L, "Tile", "getItemByType", luaTileGetItemByType);
		registerMethod(L, "Tile", "getItemByTopOrder", luaTileGetItemByTopOrder);
		registerMethod(L, "Tile", "getItemCountById", luaTileGetItemCountById);

		registerMethod(L, "Tile", "getBottomCreature", luaTileGetBottomCreature);
		registerMethod(L, "Tile", "getTopCreature", luaTileGetTopCreature);
		registerMethod(L, "Tile", "getBottomVisibleCreature", luaTileGetBottomVisibleCreature);
		registerMethod(L, "Tile", "getTopVisibleCreature", luaTileGetTopVisibleCreature);

		registerMethod(L, "Tile", "getItems", luaTileGetItems);
		registerMethod(L, "Tile", "getItemCount", luaTileGetItemCount);
		registerMethod(L, "Tile", "getDownItemCount", luaTileGetDownItemCount);
		registerMethod(L, "Tile", "getTopItemCount", luaTileGetTopItemCount);

		registerMethod(L, "Tile", "getCreatures", luaTileGetCreatures);
		registerMethod(L, "Tile", "getCreatureCount", luaTileGetCreatureCount);

		registerMethod(L, "Tile", "getThingIndex", luaTileGetThingIndex);

		registerMethod(L, "Tile", "hasProperty", luaTileHasProperty);
		registerMethod(L, "Tile", "hasFlag", luaTileHasFlag);

		registerMethod(L, "Tile", "queryAdd", luaTileQueryAdd);
		registerMethod(L, "Tile", "addItem", luaTileAddItem);
		registerMethod(L, "Tile", "addItemEx", luaTileAddItemEx);

		registerMethod(L, "Tile", "getHouse", luaTileGetHouse);
	}

private:
	static int luaTileCreate(lua_State* L);

	static int luaTileGetPosition(lua_State* L);
	static int luaTileGetGround(lua_State* L);
	static int luaTileGetThing(lua_State* L);
	static int luaTileGetThingCount(lua_State* L);
	static int luaTileGetTopVisibleThing(lua_State* L);

	static int luaTileGetTopTopItem(lua_State* L);
	static int luaTileGetTopDownItem(lua_State* L);
	static int luaTileGetFieldItem(lua_State* L);

	static int luaTileGetItemById(lua_State* L);
	static int luaTileGetItemByType(lua_State* L);
	static int luaTileGetItemByTopOrder(lua_State* L);
	static int luaTileGetItemCountById(lua_State* L);

	static int luaTileGetBottomCreature(lua_State* L);
	static int luaTileGetTopCreature(lua_State* L);
	static int luaTileGetBottomVisibleCreature(lua_State* L);
	static int luaTileGetTopVisibleCreature(lua_State* L);

	static int luaTileGetItems(lua_State* L);
	static int luaTileGetItemCount(lua_State* L);
	static int luaTileGetDownItemCount(lua_State* L);
	static int luaTileGetTopItemCount(lua_State* L);

	static int luaTileGetCreatures(lua_State* L);
	static int luaTileGetCreatureCount(lua_State* L);

	static int luaTileHasProperty(lua_State* L);
	static int luaTileHasFlag(lua_State* L);

	static int luaTileGetThingIndex(lua_State* L);

	static int luaTileQueryAdd(lua_State* L);
	static int luaTileAddItem(lua_State* L);
	static int luaTileAddItemEx(lua_State* L);

	static int luaTileGetHouse(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_MAP_TILE_FUNCTIONS_HPP_
