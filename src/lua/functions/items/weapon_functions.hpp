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

#ifndef SRC_LUA_FUNCTIONS_ITEMS_WEAPON_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_ITEMS_WEAPON_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class WeaponFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "Weapon", "", luaCreateWeapon);
		registerMethod(L, "Weapon", "action", luaWeaponAction);
		registerMethod(L, "Weapon", "register", luaWeaponRegister);
		registerMethod(L, "Weapon", "id", luaWeaponId);
		registerMethod(L, "Weapon", "level", luaWeaponLevel);
		registerMethod(L, "Weapon", "magicLevel", luaWeaponMagicLevel);
		registerMethod(L, "Weapon", "mana", luaWeaponMana);
		registerMethod(L, "Weapon", "manaPercent", luaWeaponManaPercent);
		registerMethod(L, "Weapon", "health", luaWeaponHealth);
		registerMethod(L, "Weapon", "healthPercent", luaWeaponHealthPercent);
		registerMethod(L, "Weapon", "soul", luaWeaponSoul);
		registerMethod(L, "Weapon", "breakChance", luaWeaponBreakChance);
		registerMethod(L, "Weapon", "premium", luaWeaponPremium);
		registerMethod(L, "Weapon", "wieldUnproperly", luaWeaponUnproperly);
		registerMethod(L, "Weapon", "vocation", luaWeaponVocation);
		registerMethod(L, "Weapon", "onUseWeapon", luaWeaponOnUseWeapon);
		registerMethod(L, "Weapon", "element", luaWeaponElement);
		registerMethod(L, "Weapon", "attack", luaWeaponAttack);
		registerMethod(L, "Weapon", "defense", luaWeaponDefense);
		registerMethod(L, "Weapon", "range", luaWeaponRange);
		registerMethod(L, "Weapon", "charges", luaWeaponCharges);
		registerMethod(L, "Weapon", "duration", luaWeaponDuration);
		registerMethod(L, "Weapon", "decayTo", luaWeaponDecayTo);
		registerMethod(L, "Weapon", "transformEquipTo", luaWeaponTransformEquipTo);
		registerMethod(L, "Weapon", "transformDeEquipTo", luaWeaponTransformDeEquipTo);
		registerMethod(L, "Weapon", "slotType", luaWeaponSlotType);
		registerMethod(L, "Weapon", "hitChance", luaWeaponHitChance);
		registerMethod(L, "Weapon", "extraElement", luaWeaponExtraElement);

		// exclusively for distance weapons
		registerMethod(L, "Weapon", "ammoType", luaWeaponAmmoType);
		registerMethod(L, "Weapon", "maxHitChance", luaWeaponMaxHitChance);

		// exclusively for wands
		registerMethod(L, "Weapon", "damage", luaWeaponWandDamage);

		// exclusively for wands & distance weapons
		registerMethod(L, "Weapon", "shootType", luaWeaponShootType);
	}

private:
	static int luaCreateWeapon(lua_State* L);
	static int luaWeaponId(lua_State* L);
	static int luaWeaponLevel(lua_State* L);
	static int luaWeaponMagicLevel(lua_State* L);
	static int luaWeaponMana(lua_State* L);
	static int luaWeaponManaPercent(lua_State* L);
	static int luaWeaponHealth(lua_State* L);
	static int luaWeaponHealthPercent(lua_State* L);
	static int luaWeaponSoul(lua_State* L);
	static int luaWeaponPremium(lua_State* L);
	static int luaWeaponBreakChance(lua_State* L);
	static int luaWeaponAction(lua_State* L);
	static int luaWeaponUnproperly(lua_State* L);
	static int luaWeaponVocation(lua_State* L);
	static int luaWeaponOnUseWeapon(lua_State* L);
	static int luaWeaponRegister(lua_State* L);
	static int luaWeaponElement(lua_State* L);
	static int luaWeaponAttack(lua_State* L);
	static int luaWeaponDefense(lua_State* L);
	static int luaWeaponRange(lua_State* L);
	static int luaWeaponCharges(lua_State* L);
	static int luaWeaponDuration(lua_State* L);
	static int luaWeaponDecayTo(lua_State* L);
	static int luaWeaponTransformEquipTo(lua_State* L);
	static int luaWeaponTransformDeEquipTo(lua_State* L);
	static int luaWeaponSlotType(lua_State* L);
	static int luaWeaponHitChance(lua_State* L);
	static int luaWeaponExtraElement(lua_State* L);

	// exclusively for distance weapons
	static int luaWeaponMaxHitChance(lua_State* L);
	static int luaWeaponAmmoType(lua_State* L);

	// exclusively for wands
	static int luaWeaponWandDamage(lua_State* L);

	// exclusively for wands & distance weapons
	static int luaWeaponShootType(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_ITEMS_WEAPON_FUNCTIONS_HPP_
