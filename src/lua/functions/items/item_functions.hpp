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

#ifndef SRC_LUA_FUNCTIONS_ITEMS_ITEM_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_ITEMS_ITEM_FUNCTIONS_HPP_

#include <set>

#include "lua/functions/items/container_functions.hpp"
#include "lua/functions/items/imbuement_functions.hpp"
#include "lua/functions/items/item_type_functions.hpp"
#include "lua/functions/items/weapon_functions.hpp"
#include "lua/scripts/luascript.h"

class ItemFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "Item", "", luaItemCreate);
		registerMetaMethod(L, "Item", "__eq", luaUserdataCompare);

		registerMethod(L, "Item", "isItem", luaItemIsItem);

		registerMethod(L, "Item", "getParent", luaItemGetParent);
		registerMethod(L, "Item", "getTopParent", luaItemGetTopParent);

		registerMethod(L, "Item", "getId", luaItemGetId);

		registerMethod(L, "Item", "clone", luaItemClone);
		registerMethod(L, "Item", "split", luaItemSplit);
		registerMethod(L, "Item", "remove", luaItemRemove);

		registerMethod(L, "Item", "getUniqueId", luaItemGetUniqueId);
		registerMethod(L, "Item", "getActionId", luaItemGetActionId);
		registerMethod(L, "Item", "setActionId", luaItemSetActionId);

		registerMethod(L, "Item", "getCount", luaItemGetCount);
		registerMethod(L, "Item", "getCharges", luaItemGetCharges);
		registerMethod(L, "Item", "getFluidType", luaItemGetFluidType);
		registerMethod(L, "Item", "getWeight", luaItemGetWeight);

		registerMethod(L, "Item", "getSubType", luaItemGetSubType);

		registerMethod(L, "Item", "getName", luaItemGetName);
		registerMethod(L, "Item", "getPluralName", luaItemGetPluralName);
		registerMethod(L, "Item", "getArticle", luaItemGetArticle);

		registerMethod(L, "Item", "getPosition", luaItemGetPosition);
		registerMethod(L, "Item", "getTile", luaItemGetTile);

		registerMethod(L, "Item", "hasAttribute", luaItemHasAttribute);
		registerMethod(L, "Item", "getAttribute", luaItemGetAttribute);
		registerMethod(L, "Item", "setAttribute", luaItemSetAttribute);
		registerMethod(L, "Item", "removeAttribute", luaItemRemoveAttribute);
		registerMethod(L, "Item", "getCustomAttribute", luaItemGetCustomAttribute);
		registerMethod(L, "Item", "setCustomAttribute", luaItemSetCustomAttribute);
		registerMethod(L, "Item", "removeCustomAttribute", luaItemRemoveCustomAttribute);

		registerMethod(L, "Item", "moveTo", luaItemMoveTo);
		registerMethod(L, "Item", "transform", luaItemTransform);
		registerMethod(L, "Item", "decay", luaItemDecay);

		registerMethod(L, "Item", "serializeAttributes", luaItemSerializeAttributes);
		registerMethod(L, "Item", "moveToSlot", luaItemMoveToSlot);

		registerMethod(L, "Item", "getDescription", luaItemGetDescription);

		registerMethod(L, "Item", "hasProperty", luaItemHasProperty);

		ContainerFunctions::init(L);
		ImbuementFunctions::init(L);
		ItemTypeFunctions::init(L);
		WeaponFunctions::init(L);
	}

private:
	static int luaItemCreate(lua_State* L);

	static int luaItemIsItem(lua_State* L);

	static int luaItemGetParent(lua_State* L);
	static int luaItemGetTopParent(lua_State* L);

	static int luaItemGetId(lua_State* L);

	static int luaItemClone(lua_State* L);
	static int luaItemSplit(lua_State* L);
	static int luaItemRemove(lua_State* L);

	static int luaItemGetUniqueId(lua_State* L);
	static int luaItemGetActionId(lua_State* L);
	static int luaItemSetActionId(lua_State* L);

	static int luaItemGetCount(lua_State* L);
	static int luaItemGetCharges(lua_State* L);
	static int luaItemGetFluidType(lua_State* L);
	static int luaItemGetWeight(lua_State* L);

	static int luaItemGetSubType(lua_State* L);

	static int luaItemGetName(lua_State* L);
	static int luaItemGetPluralName(lua_State* L);
	static int luaItemGetArticle(lua_State* L);

	static int luaItemGetPosition(lua_State* L);
	static int luaItemGetTile(lua_State* L);

	static int luaItemHasAttribute(lua_State* L);
	static int luaItemGetAttribute(lua_State* L);
	static int luaItemSetAttribute(lua_State* L);
	static int luaItemRemoveAttribute(lua_State* L);
	static int luaItemGetCustomAttribute(lua_State* L);
	static int luaItemSetCustomAttribute(lua_State* L);
	static int luaItemRemoveCustomAttribute(lua_State* L);

	static int luaItemMoveTo(lua_State* L);
	static int luaItemTransform(lua_State* L);
	static int luaItemDecay(lua_State* L);

	static int luaItemSerializeAttributes(lua_State* L);
	static int luaItemMoveToSlot(lua_State* L);

	static int luaItemGetDescription(lua_State* L);

	static int luaItemHasProperty(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_ITEMS_ITEM_FUNCTIONS_HPP_
