using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static int turn = 0;
    public static bool allowShoot = true;
    public BallPositionInfo ballPositionInfo;
    //private Match match;

    private void Start()
    {
        //match = GameObject.Find("Match Object").GetComponent<Match>();
    }

    private void Update()
    {
        if (ballPositionInfo != null)
        {
            ballPositionInfo.SendBallPosition();
        }

        //if (match.PlayerNum == 1)
        //{
        //    Debug.Log("레드팀");
        //    Quaternion newRotation = Quaternion.Euler(transform.rotation.eulerAngles.x, 0, transform.rotation.eulerAngles.z);
        //    transform.rotation = newRotation;
        //}
        //else if (match.PlayerNum == 2)
        //{
        //    Debug.Log("블루팀");
        //    Quaternion newRotation = Quaternion.Euler(transform.rotation.eulerAngles.x, 180, transform.rotation.eulerAngles.z);
        //    transform.rotation = newRotation;
        //}
        //else
        //{
        //    Debug.Log("PlayerNum : " + match.PlayerNum);
        //}
    }

    public void player1Turn()
    {
        turn++;

        // 서버에서 턴과 관련된 내용 처리
        P_PlayerTurnNotify playerTurnNotify = default;
        //playerTurnNotify.player_id = LocalPlayerInfo.ID;
        playerTurnNotify.curTurn = turn;

        Client.TCP.SendPacket2(E_PACKET.PLAYER_TURN_NOTIFY, playerTurnNotify);
    }

    public void player2Turn()
    {
        turn++;

        P_PlayerTurnNotify playerTurnNotify = default;
        //playerTurnNotify.player_id = LocalPlayerInfo.ID;
        playerTurnNotify.curTurn = turn;

        Client.TCP.SendPacket2(E_PACKET.PLAYER_TURN_NOTIFY, playerTurnNotify);
    }
}
