/*#################################################################*\

Copyright 2020 Jakob Föger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

\*#################################################################*/

enum MenuItemType
{
    MENU_HOME,
    MENU_BACK,
    MENU_STATUS,

    MENU_BROWSE,
    MENU_BROWSE_SOURCE,
    MENU_BROWSE_PLAYLIST,
    MENU_BROWSE_FOLDER,
    MENU_BROWSE_SONG,
    MENU_BROWSE_RADIOCATEGORY,
    MENU_BROWSE_WEBRADIO,
    MENU_BROWSE_STREAMINGCATEGORY,

    MENU_BROWSE_FOLDER_PLAY,
    MENU_BROWSE_FOLDER_ADDTOQUEUE,
    MENU_BROWSE_FOLDER_CLEARANDPLAY,
    MENU_BROWSE_FOLDER_ADDTOPLAYLIST,
    MENU_BROWSE_FOLDER_ADDTOFAVORITES,

    MENU_BROWSE_SONG_PLAY,
    MENU_BROWSE_SONG_ADDTOQUEUE,
    MENU_BROWSE_SONG_CLEARANDPLAY,
    MENU_BROWSE_SONG_ADDTOPLAYLIST,
    MENU_BROWSE_SONG_ADDTOFAVORITES,

    MENU_BROWSE_WEBRADIO_PLAY,
    MENU_BROWSE_WEBRADIO_ADDTOQUEUE,
    MENU_BROWSE_WEBRADIO_CLEARANDPLAY,
    MENU_BROWSE_WEBRADIO_ADDTOPLAYLIST,
    MENU_BROWSE_WEBRADIO_ADDTOFAVORITES,

    MENU_PLAYBACK,
    MENU_PLAYBACK_PREV,
    MENU_PLAYBACK_NEXT,
    MENU_PLAYBACK_PLAY,
    MENU_PLAYBACK_PAUSE,
    MENU_PLAYBACK_TOGGLE,
    MENU_PLAYBACK_STOP,
    MENU_PLAYBACK_RANDOM_SET,
    MENU_PLAYBACK_RANDOM_RESET,
    MENU_PLAYBACK_RANDOM_SET_RESET,
    MENU_PLAYBACK_REPEAT_SET,
    MENU_PLAYBACK_REPEAT_RESET,
    MENU_PLAYBACK_REPEAT_SET_RESET,
    MENU_PLAYBACK_FAVORITE_SET,
    MENU_PLAYBACK_FAVORITE_RESET,
    MENU_PLAYBACK_FAVORITE_SET_RESET,
    MENU_PLAYBACK_PLAYLIST_ADD,
    MENU_PLAYBACK_MUTE_SET,
    MENU_PLAYBACK_MUTE_RESET,
    MENU_PLAYBACK_MUTE_SET_RESET,

    MENU_QUEUE,
    MENU_QUEUE_CLEAR,
    MENU_QUEUE_RANDOM,
    MENU_QUEUE_REPEAT,
    MENU_QUEUE_TRACK,
    MENU_QUEUE_TRACK_DELETE,
    MENU_QUEUE_TRACK_PLAY,

    MENU_SETTINGS,
    MENU_SETTINGS_PLUGIN,
    MENU_SETTINGS_MODAL,
    MENU_SETTINGS_URL,

    MENU_DARK,
};