using ProtoBuf;
using System.CodeDom;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;
using System.Linq;
using System.Text;
using Tutorial;
using UnityEngine;
using Google.Protobuf;

public unsafe class Match : MonoBehaviour, IPacketReceiver
{
    public static Match Current;

    [MarshalAs(UnmanagedType.I4)]
    public int PlayerNum;

    public Dictionary<long, Player> Players;
    

    public GameObject prefabTeamSet;
    public GameObject prefabBlueBall;

    void Awake()
    {
        PlayerNum = 0;
        Debug.Log("Match started");
        Current = this;
        Players = new Dictionary<long, Player>();
        Client.TCP.AddPacketReceiver(this);
        Client.UDP.AddPacketReceiver(this);
    }

    void Start()
    {
        AddPlayer(LocalPlayerInfo.ID, LocalPlayerInfo.Name);
        P_RoomEnterRequest request = new P_RoomEnterRequest()
        {
            roomNumber = 0
        };
        Client.TCP.SendPacket2(E_PACKET.ROOM_ENTER_REQUEST, request);

        P_UserDataLoadRequest dataReq = default;
        Client.TCP.SendPacket2(E_PACKET.USER_DATA_LOAD_REQUEST, dataReq);
    }

    //private void OnGUI()
    //{
    //    foreach (Player player in Players.Values)
    //    {
    //        if (player.ID != LocalPlayerInfo.ID)
    //        {
    //            Vector3 scpos = GameObject.Find("Player Camera").GetComponent<Camera>().WorldToScreenPoint(player.transform.position);
    //            if (scpos.z > 0)
    //            {
    //                GUI.contentColor = Color.cyan;
    //                GUI.Label(new Rect(scpos.x, Screen.height - scpos.y, 100, 25), player.Name);
    //            }
    //        }
    //    }
    //}

    void OnDestroy()
    {
        Client.TCP.RemovePacketReceiver(this);
        Client.UDP.RemovePacketReceiver(this);
    }

    public unsafe void OnPacketReceived(Packet packet)
    {
        ushort packetId = packet.pbase.packet_id;
        switch ((E_PACKET)packetId)
        {
            case E_PACKET.ROOM_ENTER_RESPONSE:
                P_RoomEnterResponse roomEnterResponse = UnsafeCode.ByteArrayToStructure<P_RoomEnterResponse>(packet.data);
                PlayerNum = roomEnterResponse.PlayerNum;
                Debug.Log($"ROOM_ENTER_RESPONSE result={roomEnterResponse.result}");
                Debug.Log($"ROOM_ENTER_RESPONSE PlayerNum={PlayerNum}");
                break;

            case E_PACKET.ROOM_NEW_USER_NTF:
                P_RoomNewUserNotify roomNewUserNotify = UnsafeCode.ByteArrayToStructure<P_RoomNewUserNotify>(packet.data);
                AddPlayer(roomNewUserNotify.userUUID, roomNewUserNotify.userName);
                Debug.Log($"Player {roomNewUserNotify.userName} has joined");
                break;

            case E_PACKET.ROOM_USER_INFO_NTF:
                P_RoomUserInfoNotify roomUserInfoNotify = UnsafeCode.ByteArrayToStructure<P_RoomUserInfoNotify>(packet.data);
                Player newPlayer = AddPlayer(roomUserInfoNotify.userUUID, roomUserInfoNotify.userName);
                if (newPlayer != null)
                {
                    newPlayer.transform.position = roomUserInfoNotify.position;
                    newPlayer.transform.rotation = roomUserInfoNotify.rotation;
                }
                break;

            case E_PACKET.ROOM_LEAVE_USER_NTF:
                P_RoomLeaveUserNotify roomLeaveUserNotify = UnsafeCode.ByteArrayToStructure<P_RoomLeaveUserNotify>(packet.data);
                RemovePlayer(roomLeaveUserNotify.userUUID);
                break;

            case E_PACKET.UPDATE_PLAYER_MOVEMENT:
                P_UpdatePlayerMovement updateMovement = UnsafeCode.ByteArrayToStructure<P_UpdatePlayerMovement>(packet.data);
                if (Players.TryGetValue(updateMovement.player_id, out Player player) && player != null)
                {
                    player.Movement.Move(updateMovement.motion);
                }
                break;
            case E_PACKET.UPDATE_BALL_POSITION:
                P_UpdateBallPosition updateBallPosition = UnsafeCode.ByteArrayToStructure<P_UpdateBallPosition>(packet.data);
                MoveBall(updateBallPosition.child_index, updateBallPosition.ballPos);
                Debug.Log("Update Ball Position : " + updateBallPosition.ballPos);
                break;

            case E_PACKET.USER_DATA_LOAD_RESPONSE:
                P_UserDataLoadResponse dataLoad = UnsafeCode.ByteArrayToStructure<P_UserDataLoadResponse>(packet.data);
                {
                    MemoryStream ms = new MemoryStream();
                    ms.Write(Encoding.Default.GetBytes(dataLoad.message));

                    //User user = User.Parser.ParseFrom(Encoding.Default.GetBytes(dataLoad.message), 0 , Encoding.Default.GetBytes(dataLoad.message).Length * sizeof(byte));
                    //Debug.Log(user.Id);
                }
                break;
            default:
                break;

        }
    }

    private Player AddPlayer(long id, string playerName)
    {
        if (Players == null || Players.ContainsKey(id))
            return null;

        bool local = LocalPlayerInfo.ID == id;
        //GameObject playerObj = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        GameObject playerObj = new GameObject("EmptyObject");

        playerObj.name = playerName;
        if (local)
        {
            // 플레이어 카메라 생성
            //GameObject cameraObject = new GameObject($"Player Camera");
            //Camera playerCamera = cameraObject.AddComponent<Camera>();
            //cameraObject.AddComponent<MouseLook>();
            //playerCamera.transform.parent = playerObj.transform;

            GameObject teamSet = Instantiate(prefabTeamSet);
            // test code
            /*
            float randomX = Random.Range(-25, 26);
            float randomZ = Random.Range(-25, 26);
            Vector3 pos = new Vector3(randomX, 0, randomZ);
            playerObj.transform.position = pos;
            //*/
        }
        //PlayerMovement playerMovement = playerObj.AddComponent<PlayerMovement>();
        //playerMovement.Controller = playerObj.AddComponent<CharacterController>();
        Player player = playerObj.AddComponent<Player>();
        player.ID = id;
        player.Name = playerName;
        //player.Movement = playerMovement;
        player.IsLocal = local;
        Players.Add(id, player);
        return player;
    }

    private void RemovePlayer(long id)
    {
        if (Players != null && Players.TryGetValue(id, out Player player) && player != null)
        {
            Destroy(player.gameObject);
            Players.Remove(id);
        }
    }

    private void MoveBall(int index, Vector3 ballPos)
    {
        // 파란색 오브젝트 생성 후 위치에 옮겨준다.
        GameObject EnemySet = Instantiate(prefabBlueBall);
        EnemySet.transform.position = ballPos;
    }
}
