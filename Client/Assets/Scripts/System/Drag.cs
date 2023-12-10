using System.Collections;
using UnityEngine;

public class Drag : MonoBehaviour
{
    [SerializeField] private float maxSpeed = 1.0f;
    [SerializeField] private float maxDragDistance = 20.0f;
    [SerializeField] private float minDragDistance = 1.0f;
    [SerializeField] private float hitPower = 0.5f; // ������ ��

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
        float angle = 0;

        // ���콺 �����ǰ� ������Ʈ �Ÿ� ����
        Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);
        Vector3 offset = new Vector3(scrSpace.x - Input.mousePosition.x, 0, scrSpace.y - Input.mousePosition.y);

        float distance = Mathf.Sqrt(offset.x * offset.x + offset.z * offset.z); // ������ ũ�� ���
        offset /= distance; // ����ȭ

        if (offset.z > 0)
            angle += Mathf.Rad2Deg * Mathf.Acos(offset.x);
        else
            angle += 360 - Mathf.Rad2Deg * Mathf.Acos(offset.x);

        offset.x = Mathf.Cos(Mathf.Deg2Rad * angle);
        offset.z = Mathf.Sin(Mathf.Deg2Rad * angle);
        offset *= distance;
        offset.y = 3;

        rigidbody.AddForce(offset * hitPower / 2,ForceMode.Impulse);

        StartCoroutine(Shoot());
    }

    IEnumerator Shoot()
    {
        yield return new WaitForSeconds(0.1f);

        while (rigidbody.velocity.magnitude > 0.5f && transform.position.y >= 0)
            yield return new WaitForSeconds(0.1f);
    }
}
