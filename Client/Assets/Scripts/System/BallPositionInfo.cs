using UnityEngine;

public class BallPositionInfo : MonoBehaviour
{
    GameObject myBall;
    int childCount;
    Vector3[] myPosition;

    public void SendBallPosition()
    {
        Debug.Log("SendBallPosition Function Active");

        myBall = GameObject.Find("MyTeam");
        childCount = myBall.transform.childCount;
        myPosition = new Vector3[childCount];

        // �ڽ� ��ü�� ��ġ���� ����
        for (int i = 0; i < childCount; i++)
        {
            Transform childTransform = transform.GetChild(i);
            myPosition[i] = childTransform.position;
        }

        P_BallPosition ballPosition = default;

        for(int i = 0; i < childCount; i++)
        {
            ballPosition.player_id = LocalPlayerInfo.ID;
            ballPosition.child_index = i;
            ballPosition.ballPos = myPosition[i];

            Client.TCP.SendPacket2(E_PACKET.BALL_POSITION, ballPosition);
        }
    }
}
