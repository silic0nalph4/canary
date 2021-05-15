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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_COMBAT_SPELL_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_COMBAT_SPELL_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class SpellFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "Spell", "", luaSpellCreate);
		registerMetaMethod(L, "Spell", "__eq", luaUserdataCompare);

		registerMethod(L, "Spell", "onCastSpell", luaSpellOnCastSpell);
		registerMethod(L, "Spell", "register", luaSpellRegister);
		registerMethod(L, "Spell", "name", luaSpellName);
		registerMethod(L, "Spell", "id", luaSpellId);
		registerMethod(L, "Spell", "group", luaSpellGroup);
		registerMethod(L, "Spell", "cooldown", luaSpellCooldown);
		registerMethod(L, "Spell", "groupCooldown", luaSpellGroupCooldown);
		registerMethod(L, "Spell", "level", luaSpellLevel);
		registerMethod(L, "Spell", "magicLevel", luaSpellMagicLevel);
		registerMethod(L, "Spell", "mana", luaSpellMana);
		registerMethod(L, "Spell", "manaPercent", luaSpellManaPercent);
		registerMethod(L, "Spell", "soul", luaSpellSoul);
		registerMethod(L, "Spell", "range", luaSpellRange);
		registerMethod(L, "Spell", "isPremium", luaSpellPremium);
		registerMethod(L, "Spell", "isEnabled", luaSpellEnabled);
		registerMethod(L, "Spell", "needTarget", luaSpellNeedTarget);
		registerMethod(L, "Spell", "needWeapon", luaSpellNeedWeapon);
		registerMethod(L, "Spell", "needLearn", luaSpellNeedLearn);
		registerMethod(L, "Spell", "isSelfTarget", luaSpellSelfTarget);
		registerMethod(L, "Spell", "isBlocking", luaSpellBlocking);
		registerMethod(L, "Spell", "isAggressive", luaSpellAggressive);
		registerMethod(L, "Spell", "vocation", luaSpellVocation);

		// Only for InstantSpell.
		registerMethod(L, "Spell", "words", luaSpellWords);
		registerMethod(L, "Spell", "needDirection", luaSpellNeedDirection);
		registerMethod(L, "Spell", "hasParams", luaSpellHasParams);
		registerMethod(L, "Spell", "hasPlayerNameParam", luaSpellHasPlayerNameParam);
		registerMethod(L, "Spell", "needCasterTargetOrDirection", luaSpellNeedCasterTargetOrDirection);
		registerMethod(L, "Spell", "isBlockingWalls", luaSpellIsBlockingWalls);

		// Only for RuneSpells.
		registerMethod(L, "Spell", "runeId", luaSpellRuneId);
		registerMethod(L, "Spell", "charges", luaSpellCharges);
		registerMethod(L, "Spell", "allowFarUse", luaSpellAllowFarUse);
		registerMethod(L, "Spell", "blockWalls", luaSpellBlockWalls);
		registerMethod(L, "Spell", "checkFloor", luaSpellCheckFloor);
	}

private:
	static int luaSpellCreate(lua_State* L);

	static int luaSpellOnCastSpell(lua_State* L);
	static int luaSpellRegister(lua_State* L);
	static int luaSpellName(lua_State* L);
	static int luaSpellId(lua_State* L);
	static int luaSpellGroup(lua_State* L);
	static int luaSpellCooldown(lua_State* L);
	static int luaSpellGroupCooldown(lua_State* L);
	static int luaSpellLevel(lua_State* L);
	static int luaSpellMagicLevel(lua_State* L);
	static int luaSpellMana(lua_State* L);
	static int luaSpellManaPercent(lua_State* L);
	static int luaSpellSoul(lua_State* L);
	static int luaSpellRange(lua_State* L);
	static int luaSpellPremium(lua_State* L);
	static int luaSpellEnabled(lua_State* L);
	static int luaSpellNeedTarget(lua_State* L);
	static int luaSpellNeedWeapon(lua_State* L);
	static int luaSpellNeedLearn(lua_State* L);
	static int luaSpellSelfTarget(lua_State* L);
	static int luaSpellBlocking(lua_State* L);
	static int luaSpellAggressive(lua_State* L);
	static int luaSpellVocation(lua_State* L);

	// Only for InstantSpells.
	static int luaSpellWords(lua_State* L);
	static int luaSpellNeedDirection(lua_State* L);
	static int luaSpellHasParams(lua_State* L);
	static int luaSpellHasPlayerNameParam(lua_State* L);
	static int luaSpellNeedCasterTargetOrDirection(lua_State* L);
	static int luaSpellIsBlockingWalls(lua_State* L);

	// Only for RuneSpells.
	static int luaSpellRuneId(lua_State* L);
	static int luaSpellCharges(lua_State* L);
	static int luaSpellAllowFarUse(lua_State* L);
	static int luaSpellBlockWalls(lua_State* L);
	static int luaSpellCheckFloor(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_COMBAT_SPELL_FUNCTIONS_HPP_
