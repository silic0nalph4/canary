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

#ifndef SRC_LUA_FUNCTIONS_ITEMS_ITEM_TYPE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_ITEMS_ITEM_TYPE_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class ItemTypeFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "ItemType", "", luaItemTypeCreate);
		registerMetaMethod(L, "ItemType", "__eq", luaUserdataCompare);

		registerMethod(L, "ItemType", "isCorpse", luaItemTypeIsCorpse);
		registerMethod(L, "ItemType", "isDoor", luaItemTypeIsDoor);
		registerMethod(L, "ItemType", "isContainer", luaItemTypeIsContainer);
		registerMethod(L, "ItemType", "isFluidContainer", luaItemTypeIsFluidContainer);
		registerMethod(L, "ItemType", "isMovable", luaItemTypeIsMovable);
		registerMethod(L, "ItemType", "isRune", luaItemTypeIsRune);
		registerMethod(L, "ItemType", "isStackable", luaItemTypeIsStackable);
		registerMethod(L, "ItemType", "isReadable", luaItemTypeIsReadable);
		registerMethod(L, "ItemType", "isWritable", luaItemTypeIsWritable);
		registerMethod(L, "ItemType", "isBlocking", luaItemTypeIsBlocking);
		registerMethod(L, "ItemType", "isGroundTile", luaItemTypeIsGroundTile);
		registerMethod(L, "ItemType", "isMagicField", luaItemTypeIsMagicField);
		registerMethod(L, "ItemType", "isUseable", luaItemTypeIsUseable);
		registerMethod(L, "ItemType", "isPickupable", luaItemTypeIsPickupable);
		registerMethod(L, "ItemType", "isKey", luaItemTypeIsKey);

		registerMethod(L, "ItemType", "getType", luaItemTypeGetType);
		registerMethod(L, "ItemType", "getId", luaItemTypeGetId);
		registerMethod(L, "ItemType", "getClientId", luaItemTypeGetClientId);
		registerMethod(L, "ItemType", "getName", luaItemTypeGetName);
		registerMethod(L, "ItemType", "getPluralName", luaItemTypeGetPluralName);
		registerMethod(L, "ItemType", "getArticle", luaItemTypeGetArticle);
		registerMethod(L, "ItemType", "getDescription", luaItemTypeGetDescription);
		registerMethod(L, "ItemType", "getSlotPosition", luaItemTypeGetSlotPosition);

		registerMethod(L, "ItemType", "getCharges", luaItemTypeGetCharges);
		registerMethod(L, "ItemType", "getFluidSource", luaItemTypeGetFluidSource);
		registerMethod(L, "ItemType", "getCapacity", luaItemTypeGetCapacity);
		registerMethod(L, "ItemType", "getWeight", luaItemTypeGetWeight);

		registerMethod(L, "ItemType", "getHitChance", luaItemTypeGetHitChance);
		registerMethod(L, "ItemType", "getShootRange", luaItemTypeGetShootRange);

		registerMethod(L, "ItemType", "getAttack", luaItemTypeGetAttack);
		registerMethod(L, "ItemType", "getDefense", luaItemTypeGetDefense);
		registerMethod(L, "ItemType", "getExtraDefense", luaItemTypeGetExtraDefense);
		registerMethod(L, "ItemType", "getImbuingSlots", luaItemTypeGetImbuingSlots);
		registerMethod(L, "ItemType", "getArmor", luaItemTypeGetArmor);
		registerMethod(L, "ItemType", "getWeaponType", luaItemTypeGetWeaponType);

		registerMethod(L, "ItemType", "getElementType", luaItemTypeGetElementType);
		registerMethod(L, "ItemType", "getElementDamage", luaItemTypeGetElementDamage);

		registerMethod(L, "ItemType", "getTransformEquipId", luaItemTypeGetTransformEquipId);
		registerMethod(L, "ItemType", "getTransformDeEquipId", luaItemTypeGetTransformDeEquipId);
		registerMethod(L, "ItemType", "getDestroyId", luaItemTypeGetDestroyId);
		registerMethod(L, "ItemType", "getDecayId", luaItemTypeGetDecayId);
		registerMethod(L, "ItemType", "getRequiredLevel", luaItemTypeGetRequiredLevel);
		registerMethod(L, "ItemType", "getAmmoType", luaItemTypeGetAmmoType);
		registerMethod(L, "ItemType", "getCorpseType", luaItemTypeGetCorpseType);

		registerMethod(L, "ItemType", "getDecayTime", luaItemTypeGetDecayTime);
		registerMethod(L, "ItemType", "getShowDuration", luaItemTypeGetShowDuration);
		registerMethod(L, "ItemType", "getWrapableTo", luaItemTypeGetWrapableTo);
		registerMethod(L, "ItemType", "getSpeed", luaItemTypeGetSpeed);
		registerMethod(L, "ItemType", "getBaseSpeed", luaItemTypeGetBaseSpeed);

		registerMethod(L, "ItemType", "hasSubType", luaItemTypeHasSubType);
	}

private:
	static int luaItemTypeCreate(lua_State* L);

	static int luaItemTypeIsCorpse(lua_State* L);
	static int luaItemTypeIsDoor(lua_State* L);
	static int luaItemTypeIsContainer(lua_State* L);
	static int luaItemTypeIsFluidContainer(lua_State* L);
	static int luaItemTypeIsMovable(lua_State* L);
	static int luaItemTypeIsRune(lua_State* L);
	static int luaItemTypeIsStackable(lua_State* L);
	static int luaItemTypeIsReadable(lua_State* L);
	static int luaItemTypeIsWritable(lua_State* L);
	static int luaItemTypeIsBlocking(lua_State* L);
	static int luaItemTypeIsGroundTile(lua_State* L);
	static int luaItemTypeIsMagicField(lua_State* L);
	static int luaItemTypeIsUseable(lua_State* L);
	static int luaItemTypeIsPickupable(lua_State* L);
	static int luaItemTypeIsKey(lua_State* L);

	static int luaItemTypeGetType(lua_State* L);
	static int luaItemTypeGetId(lua_State* L);
	static int luaItemTypeGetClientId(lua_State* L);
	static int luaItemTypeGetName(lua_State* L);
	static int luaItemTypeGetPluralName(lua_State* L);
	static int luaItemTypeGetArticle(lua_State* L);
	static int luaItemTypeGetDescription(lua_State* L);
	static int luaItemTypeGetSlotPosition(lua_State* L);

	static int luaItemTypeGetCharges(lua_State* L);
	static int luaItemTypeGetFluidSource(lua_State* L);
	static int luaItemTypeGetCapacity(lua_State* L);
	static int luaItemTypeGetWeight(lua_State* L);

	static int luaItemTypeGetHitChance(lua_State* L);
	static int luaItemTypeGetShootRange(lua_State* L);
	static int luaItemTypeGetAttack(lua_State* L);
	static int luaItemTypeGetDefense(lua_State* L);
	static int luaItemTypeGetExtraDefense(lua_State* L);
	static int luaItemTypeGetImbuingSlots(lua_State* L);
	static int luaItemTypeGetArmor(lua_State* L);
	static int luaItemTypeGetWeaponType(lua_State* L);

	static int luaItemTypeGetElementType(lua_State* L);
	static int luaItemTypeGetElementDamage(lua_State* L);

	static int luaItemTypeGetTransformEquipId(lua_State* L);
	static int luaItemTypeGetTransformDeEquipId(lua_State* L);
	static int luaItemTypeGetDestroyId(lua_State* L);
	static int luaItemTypeGetDecayId(lua_State* L);
	static int luaItemTypeGetRequiredLevel(lua_State* L);
	static int luaItemTypeGetAmmoType(lua_State* L);
	static int luaItemTypeGetCorpseType(lua_State* L);

	static int luaItemTypeGetSpeed(lua_State* L);
	static int luaItemTypeGetBaseSpeed(lua_State* L);
	static int luaItemTypeGetDecayTime(lua_State* L);
	static int luaItemTypeGetShowDuration(lua_State* L);
	static int luaItemTypeGetWrapableTo(lua_State* L);

	static int luaItemTypeHasSubType(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_ITEMS_ITEM_TYPE_FUNCTIONS_HPP_
