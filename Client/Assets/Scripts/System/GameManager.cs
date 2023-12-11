using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static int turn = 0;
    public static bool allowShoot = true;
    private Match match;

    private void Start()
    {
        match = GameObject.Find("Match Object").GetComponent<Match>();
        player1Turn();
    }

    //private void Update()
    //{

    //    if (match.PlayerNum == 1)
    //    {
    //        Debug.Log("∑πµÂ∆¿");
    //        Quaternion newRotation = Quaternion.Euler(transform.rotation.eulerAngles.x, 0, transform.rotation.eulerAngles.z);
    //        transform.rotation = newRotation;
    //    }
    //    else if (match.PlayerNum == 2)
    //    {
    //        Debug.Log("∫Ì∑Á∆¿");
    //        Quaternion newRotation = Quaternion.Euler(transform.rotation.eulerAngles.x, 180, transform.rotation.eulerAngles.z);
    //        transform.rotation = newRotation;
    //    }
    //    else
    //    {
    //        Debug.Log("PlayerNum : " + match.PlayerNum);
    //    }
    //}

    public void player1Turn()
    {
        turn++;
    }

    public void player2Turn()
    {
        turn++;
    }
}
