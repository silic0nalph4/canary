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

#ifndef SRC_LUA_FUNCTIONS_CORE_NETWORK_NETWORK_MESSAGE_FUNCTIONS_HPP_
#define SRC_LUA_FUNCTIONS_CORE_NETWORK_NETWORK_MESSAGE_FUNCTIONS_HPP_

#include <set>

#include "lua/scripts/lua_environment.hpp"
#include "lua/scripts/luascript.h"

extern LuaEnvironment g_luaEnvironment;

class NetworkMessageFunctions final : LuaScriptInterface {
public:
	static void init(lua_State* L) {
		registerClass(L, "NetworkMessage", "", luaNetworkMessageCreate);
		registerMetaMethod(L, "NetworkMessage", "__eq", luaUserdataCompare);
		registerMetaMethod(L, "NetworkMessage", "__gc", luaNetworkMessageDelete);
		registerMethod(L, "NetworkMessage", "delete", luaNetworkMessageDelete);

		registerMethod(L, "NetworkMessage", "getByte", luaNetworkMessageGetByte);
		registerMethod(L, "NetworkMessage", "getU16", luaNetworkMessageGetU16);
		registerMethod(L, "NetworkMessage", "getU32", luaNetworkMessageGetU32);
		registerMethod(L, "NetworkMessage", "getU64", luaNetworkMessageGetU64);
		registerMethod(L, "NetworkMessage", "getString", luaNetworkMessageGetString);
		registerMethod(L, "NetworkMessage", "getPosition", luaNetworkMessageGetPosition);

		registerMethod(L, "NetworkMessage", "addByte", luaNetworkMessageAddByte);
		registerMethod(L, "NetworkMessage", "addU16", luaNetworkMessageAddU16);
		registerMethod(L, "NetworkMessage", "addU32", luaNetworkMessageAddU32);
		registerMethod(L, "NetworkMessage", "addU64", luaNetworkMessageAddU64);
		registerMethod(L, "NetworkMessage", "addString", luaNetworkMessageAddString);
		registerMethod(L, "NetworkMessage", "addPosition", luaNetworkMessageAddPosition);
		registerMethod(L, "NetworkMessage", "addDouble", luaNetworkMessageAddDouble);
		registerMethod(L, "NetworkMessage", "addItem", luaNetworkMessageAddItem);
		registerMethod(L, "NetworkMessage", "addItemId", luaNetworkMessageAddItemId);

		registerMethod(L, "NetworkMessage", "reset", luaNetworkMessageReset);
		registerMethod(L, "NetworkMessage", "skipBytes", luaNetworkMessageSkipBytes);
		registerMethod(L, "NetworkMessage", "sendToPlayer", luaNetworkMessageSendToPlayer);
	}

private:
	static int luaNetworkMessageCreate(lua_State* L);
	static int luaNetworkMessageDelete(lua_State* L);

	static int luaNetworkMessageGetByte(lua_State* L);
	static int luaNetworkMessageGetU16(lua_State* L);
	static int luaNetworkMessageGetU32(lua_State* L);
	static int luaNetworkMessageGetU64(lua_State* L);
	static int luaNetworkMessageGetString(lua_State* L);
	static int luaNetworkMessageGetPosition(lua_State* L);

	static int luaNetworkMessageAddByte(lua_State* L);
	static int luaNetworkMessageAddU16(lua_State* L);
	static int luaNetworkMessageAddU32(lua_State* L);
	static int luaNetworkMessageAddU64(lua_State* L);
	static int luaNetworkMessageAddString(lua_State* L);
	static int luaNetworkMessageAddPosition(lua_State* L);
	static int luaNetworkMessageAddDouble(lua_State* L);
	static int luaNetworkMessageAddItem(lua_State* L);
	static int luaNetworkMessageAddItemId(lua_State* L);

	static int luaNetworkMessageReset(lua_State* L);
	static int luaNetworkMessageSkipBytes(lua_State* L);
	static int luaNetworkMessageSendToPlayer(lua_State* L);
};

#endif  // SRC_LUA_FUNCTIONS_CORE_NETWORK_NETWORK_MESSAGE_FUNCTIONS_HPP_
