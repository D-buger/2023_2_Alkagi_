using System.Runtime.InteropServices;
using UnityEngine;

public enum E_PACKET
{
    LOGON_REQUEST = 200,
    LOGON_RESPONSE = 201,

    LOGIN_REQUEST = 202, // LOGIN_REQ = 201,
    LOGIN_RESPONSE = 203, // LOGIN_RES = 202,

    // Enter
    ROOM_ENTER_REQUEST = 206, // PLAYER_JOINED
    ROOM_ENTER_RESPONSE = 207,
    ROOM_NEW_USER_NTF = 208, // PLAYER_JOINED (일단 자기 자신에도 전송하고 사용된다)
    ROOM_USER_INFO_NTF = 209, // CREATE_MATCH_PLAYER,Zone 안에 있는 유저 정보

    // Leave
    ROOM_LEAVE_REQUEST = 215,
    ROOM_LEAVE_RESPONSE = 216,
    ROOM_LEAVE_USER_NTF = 217, // PLAYER_LEFT


    // Move
    PLAYER_MOVEMENT,
    UPDATE_PLAYER_MOVEMENT,

    // Ball Position
    BALL_POSITION,
    UPDATE_BALL_POSITION,

    // 현재 무슨 플레이어의 턴인지를 알려줍니다.
    PLAYER_TURN_NOTIFY,

    // Chat
    ROOM_CHAT_REQUEST = 230, // SEND_CHAT_MESSAGE
    ROOM_CHAT_RESPONSE = 231,
    ROOM_CHAT_NOTIFY = 232, // RECEIVE_CHAT_MESSAGE

    USER_DATA_SAVE,
    USER_DATA_LOAD_REQUEST,
    USER_DATA_LOAD_RESPONSE
}

[StructLayout(LayoutKind.Sequential, Size = 16)]
struct P_PlayerName
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string userName;
}

[StructLayout(LayoutKind.Sequential, Size = 66)]
struct P_LogonReq
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userID;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userPW;
}


[StructLayout(LayoutKind.Sequential, Size = 2)]
struct P_LogonRes
{
    // UInt16 Result;
    [MarshalAs(UnmanagedType.U2)]
    public ushort result;

}

[StructLayout(LayoutKind.Sequential, Size = 66)]
struct P_LoginReq
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userID;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userPW;
}


[StructLayout(LayoutKind.Sequential, Size = 4)]
struct P_LoginRes
{
    [MarshalAs(UnmanagedType.U2)]
    public ushort result;

    [MarshalAs(UnmanagedType.U2)]
    public ushort isSucceed;
}

[StructLayout(LayoutKind.Sequential, Size = 24)]
struct P_PlayerJoined
{
    [MarshalAs(UnmanagedType.I8)]
    public long id;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string userName;
}

[StructLayout(LayoutKind.Sequential, Size = 4)]
struct P_RoomEnterRequest
{
    [MarshalAs(UnmanagedType.I4)]
    public int roomNumber;
}

[StructLayout(LayoutKind.Sequential, Size = 6)]
struct P_RoomEnterResponse
{
    [MarshalAs(UnmanagedType.I2)]
    public short result;

    [MarshalAs(UnmanagedType.I4)]
    public int PlayerNum;
}

[StructLayout(LayoutKind.Sequential, Size = 41)]
struct P_RoomNewUserNotify
{
    [MarshalAs(UnmanagedType.I8)]
    public long userUUID;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userName;
}

[StructLayout(LayoutKind.Sequential, Size = 56)]
struct P_CreateMatchPlayer
{
    [MarshalAs(UnmanagedType.I8)]
    public long id;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string userName;

    [MarshalAs(UnmanagedType.Struct)]
    public Vector3 position;

    [MarshalAs(UnmanagedType.Struct)]
    public Quaternion rotation;
}

[StructLayout(LayoutKind.Sequential, Size = 69)]
struct P_RoomUserInfoNotify
{
    [MarshalAs(UnmanagedType.I8)]
    public long userUUID;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userName;

    [MarshalAs(UnmanagedType.Struct)]
    public Vector3 position;

    [MarshalAs(UnmanagedType.Struct)]
    public Quaternion rotation;
}

[StructLayout(LayoutKind.Sequential, Size = 41)]
struct P_RoomLeaveUserNotify
{
    [MarshalAs(UnmanagedType.I8)]
    public long userUUID;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userName;
}

[StructLayout(LayoutKind.Sequential, Size = 32)]
struct P_PlayerMovement
{
    [MarshalAs(UnmanagedType.I8)]
    public long player_id;

    [MarshalAs(UnmanagedType.R4)]
    public float dx;

    [MarshalAs(UnmanagedType.R4)]
    public float dy;

    [MarshalAs(UnmanagedType.Struct)]
    public Quaternion rotation;
}

[StructLayout(LayoutKind.Sequential, Size = 36)]
struct P_UpdatePlayerMovement
{
    [MarshalAs(UnmanagedType.I8)]
    public long player_id;

    [MarshalAs(UnmanagedType.Struct)]
    public Quaternion rotation;

    [MarshalAs(UnmanagedType.Struct)]
    public Vector3 motion;

}

[StructLayout(LayoutKind.Sequential, Size = 26)]
struct P_BallPosition
{
    [MarshalAs(UnmanagedType.I8)]
    public long player_id;

    [MarshalAs(UnmanagedType.I4)]
    public int child_index;

    [MarshalAs(UnmanagedType.Struct)]
    public Vector3 ballPos;
}

[StructLayout(LayoutKind.Sequential, Size = 26)]
struct P_UpdateBallPosition
{
    [MarshalAs(UnmanagedType.I8)]
    public long player_id;

    [MarshalAs(UnmanagedType.I4)]
    public int child_index;

    [MarshalAs(UnmanagedType.Struct)]
    public Vector3 ballPos;
}

[StructLayout(LayoutKind.Sequential, Size = 294)]
struct  P_PlayerTurnNotify
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userID;

    [MarshalAs(UnmanagedType.I4)]
    public int curTurn;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 257)]
    public string message;
}

[StructLayout(LayoutKind.Sequential, Size = 257)]
struct P_RoomChatRequest
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 257)]
    public string message;
}

[StructLayout(LayoutKind.Sequential, Size = 290)]
struct P_RoomChatNotify
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 33)]
    public string userID;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 257)]
    public string message;
}

[StructLayout(LayoutKind.Sequential, Size = 265)]
struct P_UserDataSaveRequest
{
    [MarshalAs(UnmanagedType.I8)]
    public long dataType;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 257)]
    public string message;
}
[StructLayout(LayoutKind.Sequential, Size = 0)]
struct P_UserDataLoadRequest
{
}

[StructLayout(LayoutKind.Sequential, Size = 257)]
struct P_UserDataLoadResponse
{
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 257)]
    public string message;
}