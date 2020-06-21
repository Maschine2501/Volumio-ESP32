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

#include "Volumio.h"

#include "LibDebug.h"
#if (DEBUGLEVEL_VOLUMIO >= 1)
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINT(x) Serial.print(x)
#else
#define DEBUG_PRINTLN(x)
#define DEBUG_PRINT(x)
#endif

void Volumio::connect(String hostname, int port)
{
  lastTime = millis();

  if (!socketIoClient.connect(hostname, port))
    DEBUG_PRINTLN("Volumio: connect(): connection failed");

  if (socketIoClient.getConnected())
    DEBUG_PRINTLN("Volumio: connect(): connected");
}

bool Volumio::getConnected()
{
  return socketIoClient.getConnected();
}

bool Volumio::readPushToastMessage()
{
  if (pushType != pushToastMessage)
  {
    DEBUG_PRINTLN("Volumio: readPushToastMessage(): ERROR, no data avaliable");
    return false;
  }

  CurrentToastItem.message = "";
  CurrentToastItem.title = "";
  CurrentToastItem.type = "";

  while (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readPushToastMessage(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());

    if (jsonParser.getNode(2) == "message")
      CurrentToastItem.message = jsonParser.getValue();
    if (jsonParser.getNode(2) == "title")
      CurrentToastItem.title = jsonParser.getValue();
    if (jsonParser.getNode(2) == "type")
      CurrentToastItem.type = jsonParser.getValue();

    if (jsonParser.getBlockEnd())
    {
      while (jsonParser.next())
        ;

      return true;
    }
  }

  return false;
}

bool Volumio::readNextSourceItem()
{
  if (pushType != pushBrowseSources)
  {
    DEBUG_PRINTLN("Volumio: readNextSourceItem(): ERROR, no data avaliable");
    return false;
  }

  CurrentSourceItem.albumart = "";
  CurrentSourceItem.name = "";
  CurrentSourceItem.uri = "";
  CurrentSourceItem.plugin_type = "";
  CurrentSourceItem.plugin_name = "";
  CurrentSourceItem.icon = "";

  while (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readNextSourceItem(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());

    if (jsonParser.getNode(3) == "albumart")
      CurrentSourceItem.albumart = jsonParser.getValue();
    if (jsonParser.getNode(3) == "name")
      CurrentSourceItem.name = jsonParser.getValue();
    if (jsonParser.getNode(3) == "uri")
      CurrentSourceItem.uri = jsonParser.getValue();
    if (jsonParser.getNode(3) == "plugin_type")
      CurrentSourceItem.plugin_type = jsonParser.getValue();
    if (jsonParser.getNode(3) == "plugin_name")
      CurrentSourceItem.plugin_name = jsonParser.getValue();
    if (jsonParser.getNode(3) == "icon")
      CurrentSourceItem.icon = jsonParser.getValue();

    if (jsonParser.getBlockEnd())
      return true;
  }

  return false;
}

bool Volumio::readNextQueueItem()
{
  if (pushType != pushQueue)
  {
    DEBUG_PRINTLN("Volumio: readNextQueueItem(): ERROR, no data avaliable");
    return false;
  }

  CurrentQueueItem.uri = "";
  CurrentQueueItem.service = "";
  CurrentQueueItem.name = "";
  CurrentQueueItem.artist = "";
  CurrentQueueItem.album = "";
  CurrentQueueItem.type = "";
  CurrentQueueItem.tracknumber = "";
  CurrentQueueItem.albumart = "";
  CurrentQueueItem.duration = "";
  CurrentQueueItem.samplerate = "";
  CurrentQueueItem.bitdepth = "";
  CurrentQueueItem.trackType = "";
  CurrentQueueItem.channels = "";

  while (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readNextQueueItem(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());

    if (jsonParser.getNode(3) == "uri")
      CurrentQueueItem.uri = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "service")
      CurrentQueueItem.service = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "name")
      CurrentQueueItem.name = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "artist")
      CurrentQueueItem.artist = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "album")
      CurrentQueueItem.album = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "type")
      CurrentQueueItem.type = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "tracknumber")
      CurrentQueueItem.tracknumber = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "albumart")
      CurrentQueueItem.albumart = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "duration")
      CurrentQueueItem.duration = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "samplerate")
      CurrentQueueItem.samplerate = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "bitdepth")
      CurrentQueueItem.bitdepth = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "trackType")
      CurrentQueueItem.trackType = jsonParser.getValue();
    else if (jsonParser.getNode(3) == "channels")
      CurrentQueueItem.channels = jsonParser.getValue();

    if (jsonParser.getBlockEnd())
      return true;
  }

  return false;
}

bool Volumio::readNextLibraryItem()
{
  if (pushType != pushBrowseLibrary)
  {
    DEBUG_PRINTLN("Volumio: readNextLibraryItem(): ERROR, no data avaliable");
    return false;
  }

  CurrentLibraryItem.service = "";
  CurrentLibraryItem.type = "";
  CurrentLibraryItem.title = "";
  CurrentLibraryItem.artist = "";
  CurrentLibraryItem.album = "";
  CurrentLibraryItem.uri = "";
  CurrentLibraryItem.albumart = "";
  CurrentLibraryItem.tracknumber = "";
  CurrentLibraryItem.duration = "";
  CurrentLibraryItem.trackType = "";
  CurrentLibraryItem.icon = "";

  while (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readNextLibraryItem(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());
    if (jsonParser.getLevel() == 7)
    {

      if (jsonParser.getNode(7) == "service")
        CurrentLibraryItem.service = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "type")
        CurrentLibraryItem.type = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "title")
        CurrentLibraryItem.title = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "artist")
        CurrentLibraryItem.artist = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "album")
        CurrentLibraryItem.album = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "uri")
        CurrentLibraryItem.uri = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "albumart")
        CurrentLibraryItem.albumart = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "tracknumber")
        CurrentLibraryItem.tracknumber = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "duration")
        CurrentLibraryItem.duration = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "trackType")
        CurrentLibraryItem.trackType = jsonParser.getValue();
      else if (jsonParser.getNode(7) == "icon")
        CurrentLibraryItem.icon = jsonParser.getValue();

      if (jsonParser.getBlockEnd())
        return true;
    }
    if (jsonParser.getLevel() == 4)
    {
      if (jsonParser.getNode(3) == "prev")
      {
        if (jsonParser.getNode(4) == "uri")
          LibraryPrev.uri = jsonParser.getValue();
      }

      if (jsonParser.getNode(3) == "info")
      {
        if (jsonParser.getNode(4) == "uri")
          LibraryInfo.uri = jsonParser.getValue();
        if (jsonParser.getNode(4) == "title")
          LibraryInfo.title = jsonParser.getValue();
        if (jsonParser.getNode(4) == "service")
          LibraryInfo.service = jsonParser.getValue();
        if (jsonParser.getNode(4) == "type")
          LibraryInfo.type = jsonParser.getValue();
        if (jsonParser.getNode(4) == "albumart")
          LibraryInfo.albumart = jsonParser.getValue();
      }
    }
  }

  return false;
}

bool Volumio::readLibraryPrev()
{
  if (pushType != pushBrowseLibrary)
    return false;

  if (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readLibraryPrev(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());

    if (jsonParser.getNode(3) == "prev")
    {
      if (jsonParser.getNode(4) == "uri")
        LibraryPrev.uri = jsonParser.getValue();
    }

    if (jsonParser.getNode(3) == "info")
    {
      if (jsonParser.getNode(4) == "uri")
        LibraryInfo.uri = jsonParser.getValue();
      if (jsonParser.getNode(4) == "title")
        LibraryInfo.title = jsonParser.getValue();
      if (jsonParser.getNode(4) == "service")
        LibraryInfo.service = jsonParser.getValue();
      if (jsonParser.getNode(4) == "type")
        LibraryInfo.type = jsonParser.getValue();
      if (jsonParser.getNode(4) == "albumart")
        LibraryInfo.albumart = jsonParser.getValue();
    }
    return true;
  }

  return false;
}

bool Volumio::readState()
{
  if (pushType != pushState)
  {
    DEBUG_PRINTLN("Volumio: readState(): ERROR, no data avaliable");
    return false;
  }

  while (jsonParser.next())
  {
    if (jsonParser.getNode(2) == "status")
      State.status = jsonParser.getValue();
    if (jsonParser.getNode(2) == "position")
      State.position = jsonParser.getValue();
    if (jsonParser.getNode(2) == "title")
      State.title = jsonParser.getValue();
    if (jsonParser.getNode(2) == "artist")
      State.artist = jsonParser.getValue();
    if (jsonParser.getNode(2) == "album")
      State.album = jsonParser.getValue();
    if (jsonParser.getNode(2) == "albumart")
      State.albumart = jsonParser.getValue();
    if (jsonParser.getNode(2) == "uri")
      State.uri = jsonParser.getValue();
    if (jsonParser.getNode(2) == "trackType")
      State.trackType = jsonParser.getValue();
    if (jsonParser.getNode(2) == "seek")
      State.seek = atol(jsonParser.getValue().c_str());
    if (jsonParser.getNode(2) == "duration")
      State.duration = atol(jsonParser.getValue().c_str());
    if (jsonParser.getNode(2) == "samplerate")
      State.samplerate = jsonParser.getValue();
    if (jsonParser.getNode(2) == "bitdepth")
      State.bitdepth = jsonParser.getValue();
    if (jsonParser.getNode(2) == "channels")
      State.channels = jsonParser.getValue();
    if (jsonParser.getNode(2) == "random")
      State.random = jsonParser.getValue();
    if (jsonParser.getNode(2) == "repeat")
      State.repeat = jsonParser.getValue();
    if (jsonParser.getNode(2) == "repeatSingle")
      State.repeatSingle = jsonParser.getValue();
    if (jsonParser.getNode(2) == "consume")
      State.consume = jsonParser.getValue();
    if (jsonParser.getNode(2) == "volume")
      State.volume = atoi(jsonParser.getValue().c_str());
    if (jsonParser.getNode(2) == "mute")
      State.mute = jsonParser.getValue();
    if (jsonParser.getNode(2) == "disableVolumeControl")
      State.disableVolumeControl = jsonParser.getValue();
    if (jsonParser.getNode(2) == "stream")
      State.stream = jsonParser.getValue();
    if (jsonParser.getNode(2) == "updatedb")
      State.updatedb = jsonParser.getValue();
    if (jsonParser.getNode(2) == "service")
      State.service = jsonParser.getValue();
    if (jsonParser.getNode(2) == "Streaming")
      State.Streaming = jsonParser.getValue();

    DEBUG_PRINT("Volumio: readState(): ");
    DEBUG_PRINT(jsonParser.getNode(2));
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());
  }

  DEBUG_PRINTLN("");
}

bool Volumio::readMultiRoomDevice()
{
  if (pushType != pushMultiRoomDevices)
  {
    DEBUG_PRINTLN("Volumio: readMultiRoomDevice(): ERROR, no data avaliable");
    return false;
  }

  while (jsonParser.next())
  {
    DEBUG_PRINT("Volumio: readMultiRoomDevice(): ");
    DEBUG_PRINT(jsonParser.getPath());
    DEBUG_PRINT(" = ");
    DEBUG_PRINTLN(jsonParser.getValue());

    if (jsonParser.getBlockEnd())
      return true;
  }

  return false;
}

void Volumio::process()
{
  //cleanup, just in case application didnt read all data
  if (pushType != pushNone)
    while (jsonParser.next())
      ;

  unsigned long now = millis();

  //Calculate seek state if in play
  if (State.status == "play")
    State.seek += (now - lastTime);

  lastTime = now;

  pushType = pushNone;

  if (socketIoClient.process())
  {
    //link messagstream to JSON-parser
    jsonParser.initialize(&socketIoClient);

    //Process data as long as data generates lines
    if (jsonParser.next())
    {
      DEBUG_PRINT("Volumio: process(): Receive: ");
      DEBUG_PRINTLN(jsonParser.getValue());

      if (jsonParser.getValue() == "pushToastMessage")
      {
        pushType = pushToastMessage;
      }
      else if (jsonParser.getValue() == "pushBrowseLibrary")
      {
        pushType = pushBrowseLibrary;

        LibraryInfo.uri = "";
        LibraryInfo.title = "";
        LibraryInfo.service = "";
        LibraryInfo.type = "";
        LibraryInfo.albumart = "";
      }
      else if (jsonParser.getValue() == "pushBrowseSources")
        pushType = pushBrowseSources;
      else if (jsonParser.getValue() == "pushQueue")
        pushType = pushQueue;
      else if (jsonParser.getValue() == "pushState")
        pushType = pushState;
      else if (jsonParser.getValue() == "pushMultiRoomDevices")
        pushType = pushMultiRoomDevices;
      else
      {
        while (jsonParser.next())
        {
          DEBUG_PRINT(jsonParser.getPath());
          DEBUG_PRINT(" = ");
          DEBUG_PRINTLN(jsonParser.getValue());
        }
      }
    }
  }
}