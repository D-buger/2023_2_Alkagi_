using System.Collections;
using UnityEngine;

public class Drag : MonoBehaviour
{
    [SerializeField] private float maxDragDistance = 200.0f;
    [SerializeField] private float hitPower = 1.0f; // 날리는 힘

    private Rigidbody rigidbody;

    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
    }

    void Update()
    {
        transform.rotation = Quaternion.Euler(0f, 0f, 0f);
    }

    private void OnMouseUp()
    {
        if (tag == "Red")
        {
            float angle = 0;

            // 마우스 포지션과 오브젝트 거리 저장
            Vector3 mousePosition = Input.mousePosition;
            Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);
            Vector3 offset = new Vector3(scrSpace.x - mousePosition.x, 0, scrSpace.y - mousePosition.y);

            float distance = Mathf.Sqrt(offset.x * offset.x + offset.z * offset.z); // 벡터의 크기 계산

            if (distance > maxDragDistance)
            {
                offset = offset.normalized * maxDragDistance;
                distance = maxDragDistance;
            }

            offset /= distance; // 정규화

            if (offset.z > 0)
                angle += Mathf.Rad2Deg * Mathf.Acos(offset.x);
            else
                angle += 360 - Mathf.Rad2Deg * Mathf.Acos(offset.x);

            offset.x = Mathf.Cos(Mathf.Deg2Rad * angle);
            offset.z = Mathf.Sin(Mathf.Deg2Rad * angle);
            offset *= distance;
            offset.y = 3;

            rigidbody.AddForce(offset * hitPower / 2, ForceMode.Impulse);

            StartCoroutine(Shoot());
        }
    }

    IEnumerator Shoot()
    {
        yield return new WaitForSeconds(0.1f);

        while (rigidbody.velocity.magnitude > 0.1f && transform.position.y >= 0)
            yield return new WaitForSeconds(0.1f);

        if(GameManager.turn % 2 == 1)
            GameObject.Find("Main Camera").GetComponent<GameManager>().player2Turn();
        else
            GameObject.Find("Main Camera").GetComponent<GameManager>().player1Turn();
    }
}
