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

#ifndef SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PARTY_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PARTY_FUNCTIONS_HPP_

#include "lua/scripts/luascript.h"

class PartyFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "Party", "", luaPartyCreate);
		registerMetaMethod(L, "Party", "__eq", luaUserdataCompare);
		registerMethod(L, "Party", "disband", luaPartyDisband);
		registerMethod(L, "Party", "getLeader", luaPartyGetLeader);
		registerMethod(L, "Party", "setLeader", luaPartySetLeader);
		registerMethod(L, "Party", "getMembers", luaPartyGetMembers);
		registerMethod(L, "Party", "getMemberCount", luaPartyGetMemberCount);
		registerMethod(L, "Party", "getInvitees", luaPartyGetInvitees);
		registerMethod(L, "Party", "getInviteeCount", luaPartyGetInviteeCount);
		registerMethod(L, "Party", "addInvite", luaPartyAddInvite);
		registerMethod(L, "Party", "removeInvite", luaPartyRemoveInvite);
		registerMethod(L, "Party", "addMember", luaPartyAddMember);
		registerMethod(L, "Party", "removeMember", luaPartyRemoveMember);
		registerMethod(L, "Party", "isSharedExperienceActive", luaPartyIsSharedExperienceActive);
		registerMethod(L, "Party", "isSharedExperienceEnabled", luaPartyIsSharedExperienceEnabled);
		registerMethod(L, "Party", "shareExperience", luaPartyShareExperience);
		registerMethod(L, "Party", "setSharedExperience", luaPartySetSharedExperience);
	}

private:
	static int luaPartyCreate(lua_State* L);
	static int luaPartyDisband(lua_State* L);
	static int luaPartyGetLeader(lua_State* L);
	static int luaPartySetLeader(lua_State* L);
	static int luaPartyGetMembers(lua_State* L);
	static int luaPartyGetMemberCount(lua_State* L);
	static int luaPartyGetInvitees(lua_State* L);
	static int luaPartyGetInviteeCount(lua_State* L);
	static int luaPartyAddInvite(lua_State* L);
	static int luaPartyRemoveInvite(lua_State* L);
	static int luaPartyAddMember(lua_State* L);
	static int luaPartyRemoveMember(lua_State* L);
	static int luaPartyIsSharedExperienceActive(lua_State* L);
	static int luaPartyIsSharedExperienceEnabled(lua_State* L);
	static int luaPartyShareExperience(lua_State* L);
	static int luaPartySetSharedExperience(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CREATURES_PLAYER_PARTY_FUNCTIONS_HPP_
