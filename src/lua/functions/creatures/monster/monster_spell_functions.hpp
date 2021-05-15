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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_SPELL_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_SPELL_FUNCTIONS_HPP_

#include "creatures/monsters/monsters.h"
#include "lua/scripts/luascript.h"

class MonsterSpellFunctions final : LuaScriptInterface
{
public:
	static void init(lua_State* L)
	{
		registerClass(L, "MonsterSpell", "", luaCreateMonsterSpell);
		registerMetaMethod(L, "MonsterSpell", "__gc", luaDeleteMonsterSpell);
		registerMethod(L, "MonsterSpell", "delete", luaDeleteMonsterSpell);
		registerMethod(L, "MonsterSpell", "setType", luaMonsterSpellSetType);
		registerMethod(L, "MonsterSpell", "setScriptName", luaMonsterSpellSetScriptName);
		registerMethod(L, "MonsterSpell", "setChance", luaMonsterSpellSetChance);
		registerMethod(L, "MonsterSpell", "setInterval", luaMonsterSpellSetInterval);
		registerMethod(L, "MonsterSpell", "setRange", luaMonsterSpellSetRange);
		registerMethod(L, "MonsterSpell", "setCombatValue", luaMonsterSpellSetCombatValue);
		registerMethod(L, "MonsterSpell", "setCombatType", luaMonsterSpellSetCombatType);
		registerMethod(L, "MonsterSpell", "setAttackValue", luaMonsterSpellSetAttackValue);
		registerMethod(L, "MonsterSpell", "setNeedTarget", luaMonsterSpellSetNeedTarget);
		registerMethod(L, "MonsterSpell", "setCombatLength", luaMonsterSpellSetCombatLength);
		registerMethod(L, "MonsterSpell", "setCombatSpread", luaMonsterSpellSetCombatSpread);
		registerMethod(L, "MonsterSpell", "setCombatRadius", luaMonsterSpellSetCombatRadius);
		registerMethod(L, "MonsterSpell", "setConditionType", luaMonsterSpellSetConditionType);
		registerMethod(L, "MonsterSpell", "setConditionDamage", luaMonsterSpellSetConditionDamage);
		registerMethod(L, "MonsterSpell", "setConditionSpeedChange", luaMonsterSpellSetConditionSpeedChange);
		registerMethod(L, "MonsterSpell", "setConditionDuration", luaMonsterSpellSetConditionDuration);
		registerMethod(L, "MonsterSpell", "setConditionTickInterval", luaMonsterSpellSetConditionTickInterval);
		registerMethod(L, "MonsterSpell", "setCombatShootEffect", luaMonsterSpellSetCombatShootEffect);
		registerMethod(L, "MonsterSpell", "setCombatEffect", luaMonsterSpellSetCombatEffect);
		registerMethod(L, "MonsterSpell", "setOutfitMonster", luaMonsterSpellSetOutfitMonster);
		registerMethod(L, "MonsterSpell", "setOutfitItem", luaMonsterSpellSetOutfitItem);
	}

private:
	static int luaCreateMonsterSpell(lua_State* L);
	static int luaDeleteMonsterSpell(lua_State* L);
	static int luaMonsterSpellSetType(lua_State* L);
	static int luaMonsterSpellSetScriptName(lua_State* L);
	static int luaMonsterSpellSetChance(lua_State* L);
	static int luaMonsterSpellSetInterval(lua_State* L);
	static int luaMonsterSpellSetRange(lua_State* L);
	static int luaMonsterSpellSetCombatValue(lua_State* L);
	static int luaMonsterSpellSetCombatType(lua_State* L);
	static int luaMonsterSpellSetAttackValue(lua_State* L);
	static int luaMonsterSpellSetNeedTarget(lua_State* L);
	static int luaMonsterSpellSetCombatLength(lua_State* L);
	static int luaMonsterSpellSetCombatSpread(lua_State* L);
	static int luaMonsterSpellSetCombatRadius(lua_State* L);
	static int luaMonsterSpellSetConditionType(lua_State* L);
	static int luaMonsterSpellSetConditionDamage(lua_State* L);
	static int luaMonsterSpellSetConditionSpeedChange(lua_State* L);
	static int luaMonsterSpellSetConditionDuration(lua_State* L);
	static int luaMonsterSpellSetConditionTickInterval(lua_State* L);
	static int luaMonsterSpellSetCombatShootEffect(lua_State* L);
	static int luaMonsterSpellSetCombatEffect(lua_State* L);
	static int luaMonsterSpellSetOutfitMonster(lua_State* L);
	static int luaMonsterSpellSetOutfitItem(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_MONSTER_MONSTER_SPELL_FUNCTIONS_HPP_
