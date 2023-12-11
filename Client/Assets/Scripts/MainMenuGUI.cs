using System;
using UnityEditor.PackageManager;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MainMenuGUI : MonoBehaviour, IPacketReceiver
{
    Text infoText;
    Text warnText;
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
        warnText = GameObject.Find("WarnText").GetComponent<Text>();
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

                Debug.Log(loginRes.isSucceed);

                if (loginRes.isSucceed > 0)
                {
                    LocalPlayerInfo.ID = loginRes.result;
                    LocalPlayerInfo.Name = idInput.text;

                    SceneManager.LoadSceneAsync("Scenes/MatchScene", LoadSceneMode.Single);
                }
                else
                {
                    Debug.Log(loginRes.result);

                    if ((ERROR_CODE)loginRes.result == ERROR_CODE.USER_MGR_INVALID_USER_INDEX)
                    {
                        warnText.text = "없는 아이디입니다";
                    }
                    else if ((ERROR_CODE)loginRes.result == ERROR_CODE.LOGIN_USER_INVALID_PW)
                    {
                        warnText.text = "비밀번호가 다릅니다";
                    }
                }

                break;
            case E_PACKET.LOGON_RESPONSE:
                P_LogonRes logonRes = UnsafeCode.ByteArrayToStructure<P_LogonRes>(packet.data);

                Debug.Log(logonRes.result);

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
        warnText.text = "";
        if (isLogin)
        {
            infoText.text = "로그인";
            idInput.text = "";
            pwInput.text = "";
        }
        else
        {
            infoText.text = "회원가입";
            idInput.text = "";
            pwInput.text = "";
        }
    }
}
