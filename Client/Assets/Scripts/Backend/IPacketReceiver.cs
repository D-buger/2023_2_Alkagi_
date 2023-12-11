﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IPacketReceiver
{
    unsafe void OnPacketReceived(Packet packet);
}
enum ERROR_CODE : ushort
{
    NONE = 0,

    USER_MGR_INVALID_USER_INDEX = 11,
    USER_MGR_INVALID_USER_UNIQUEID = 12,

    LOGIN_USER_ALREADY = 31,
    LOGIN_USER_USED_ALL_OBJ = 32,
    LOGIN_USER_INVALID_PW = 33,

    NEW_ROOM_USED_ALL_OBJ = 41,
    NEW_ROOM_FAIL_ENTER = 42,

    ENTER_ROOM_NOT_FINDE_USER = 51,
    ENTER_ROOM_INVALID_USER_STATUS = 52,
    ENTER_ROOM_NOT_USED_STATUS = 53,
    ENTER_ROOM_FULL_USER = 54,

    ROOM_INVALID_INDEX = 61,
    ROOM_NOT_USED = 62,
    ROOM_TOO_MANY_PACKET = 63,

    LEAVE_ROOM_INVALID_ROOM_INDEX = 71,

    CHAT_ROOM_INVALID_ROOM_NUMBER = 81,
};
