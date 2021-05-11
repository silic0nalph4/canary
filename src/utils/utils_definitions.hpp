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

#ifndef SRC_UTILS_UTILS_DEFINITIONS_HPP_
#define SRC_UTILS_UTILS_DEFINITIONS_HPP_

// Enums
enum ThreadState {
	THREAD_STATE_RUNNING,
	THREAD_STATE_CLOSING,
	THREAD_STATE_TERMINATED,
};

enum SpawnType_t
{
	RESPAWN_IN_ALL = 0,
	RESPAWN_IN_DAY = 1,
	RESPAWN_IN_NIGHT = 2,
	RESPAWN_IN_DAY_CAVE = 3,
	RESPAWN_IN_NIGHT_CAVE = 4,
};

enum Cipbia_Elementals_t : uint8_t {
	CIPBIA_ELEMENTAL_PHYSICAL = 0,
	CIPBIA_ELEMENTAL_FIRE = 1,
	CIPBIA_ELEMENTAL_EARTH = 2,
	CIPBIA_ELEMENTAL_ENERGY = 3,
	CIPBIA_ELEMENTAL_ICE = 4,
	CIPBIA_ELEMENTAL_HOLY = 5,
	CIPBIA_ELEMENTAL_DEATH = 6,
	CIPBIA_ELEMENTAL_HEALING = 7,
	CIPBIA_ELEMENTAL_DROWN = 8,
	CIPBIA_ELEMENTAL_LIFEDRAIN = 9,
	CIPBIA_ELEMENTAL_UNDEFINED = 10
};

#endif  // SRC_UTILS_UTILS_DEFINITIONS_HPP_
