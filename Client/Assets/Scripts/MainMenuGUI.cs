using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MainMenuGUI : MonoBehaviour, IPacketReceiver
{
    Text infoText;
    InputField idInput;
    InputField pwInput;
    bool isLogin = true;

    void Awake()
    {
        Client.Start();
    }

    void Start()
    {
        idInput = GameObject.Find("NameInput").GetComponent<InputField>();
        pwInput = GameObject.Find("PasswordInput").GetComponent<InputField>();
        infoText = GameObject.Find("InfoText").GetComponent<Text>();
        isLogin = true;
        ChangeText();

        Client.TCP.AddPacketReceiver(this);
    }

    public unsafe void OnPacketReceived(Packet packet)
    {
        ushort packetId = packet.pbase.packet_id;
        switch ((E_PACKET)packetId)
        {
            case E_PACKET.LOGIN_RESPONSE:
                P_LoginRes loginRes = UnsafeCode.ByteArrayToStructure<P_LoginRes>(packet.data);

                LocalPlayerInfo.ID = loginRes.result;
                LocalPlayerInfo.Name = idInput.text;
                
                SceneManager.LoadSceneAsync("Scenes/MatchScene", LoadSceneMode.Single);
                break;
            case E_PACKET.LOGON_RESPONSE:
                P_LogonRes logonRes = UnsafeCode.ByteArrayToStructure<P_LogonRes>(packet.data);


                break;
        }
    }

    public void OnDestroy()
    {
        Client.TCP.RemovePacketReceiver(this);
    }

    public void OnJoinButtonClick()
    {
        if (isLogin)
        {
            //로그인
            P_LoginReq loginReq = default;
            loginReq.userID = idInput.text;
            loginReq.userPW = pwInput.text;
            Client.TCP.SendPacket2(E_PACKET.LOGIN_REQUEST, loginReq);
        }
        else
        {
            //회원가입
            P_LogonReq logonReq = default;
            logonReq.userID = idInput.text;
            logonReq.userPW = pwInput.text;
            Client.TCP.SendPacket2(E_PACKET.LOGON_REQUEST, logonReq);
        }
    }

    public void OnChangeButtonClick()
    {
        isLogin = !isLogin;
        ChangeText();
    }

    private void ChangeText()
    {
        if (isLogin)
        {
            infoText.text = "로그인";
        }
        else
        {
            infoText.text = "회원가입";
        }
    }
}
