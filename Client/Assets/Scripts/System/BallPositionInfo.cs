using UnityEngine;

public class BallPositionInfo : MonoBehaviour
{
    GameObject myBall;
    int childCount;
    Vector3[] myPosition;

    void Start()
    {
        myBall = GameObject.Find("MyTeam");
        childCount = myBall.transform.childCount;
        myPosition = new Vector3[childCount];
    }

    public void InitPosition()
    {
        // 자식 객체의 위치값을 저장
        for(int i = 0; i < childCount; i++) 
        {
            Transform childTransform = transform.GetChild(i);
            myPosition[i] = childTransform.position;
        }
    }

    public void SendBallPosition()
    {
        P_BallPosition ballPosition = default;

        for(int i = 0; i < childCount; i++)
        {
            ballPosition.player_id = LocalPlayerInfo.ID;
            ballPosition.child_index = i;
            ballPosition.dx = myPosition[i].x;
            ballPosition.dz = myPosition[i].z;

            Client.TCP.SendPacket2(E_PACKET.BALL_POSITION, ballPosition);
        }
    }
}
