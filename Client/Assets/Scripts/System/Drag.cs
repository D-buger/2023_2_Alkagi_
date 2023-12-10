using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drag : MonoBehaviour
{
    [SerializeField] private float maxSpeed = 1.0f;
    [SerializeField] private float maxDragDistance = 20.0f;
    [SerializeField] private float minDragDistance = 1.0f;
    [SerializeField] private float hitPower = 1.0f; // ������ ��

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
        float angle = -1;
        if (this.gameObject.tag == "Red") 
            angle = 0;
        if (this.gameObject.tag == "Blue")
            angle = 180;


        if (angle == -1) return;

        // ���콺 �����ǰ� ������Ʈ �Ÿ� ����
        Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);
        Vector3 offset = new Vector3(scrSpace.x - Input.mousePosition.x, 0, scrSpace.y - Input.mousePosition.y);


        float distance = Mathf.Sqrt(offset.x * offset.x + offset.z * offset.z); // ������ ũ�� ���
        offset /= distance; // ����ȭ

        offset.x = Mathf.Cos(Mathf.Deg2Rad * angle);
        offset.z = Mathf.Sin(Mathf.Deg2Rad * angle);
        offset *= distance;
        offset.y = 6;

        rigidbody.AddForce(offset * hitPower,ForceMode.Impulse);

        StartCoroutine(Shoot());
    }

    IEnumerator Shoot()
    {
        yield return new WaitForSeconds(0.1f);

        while (rigidbody.velocity.magnitude > 0.5f && transform.position.y >= 0)
            yield return new WaitForSeconds(0.1f);
    }

    //private void OnMouseDrag()
    //{        
    //    // �ӵ� ����
    //    Vector3 mousePosition = Input.mousePosition;
    //    Vector3 objectPosition = this.transform.position;
        
    //    // SqrMagnitude : ������ ũ��(Ȥ�� ����)�� ��ȯ�ϴ� �޼���
    //    // ���콺 �����ǰ� �˰��� �Ÿ��� ����Ѵ�.
    //    float Distance = (mousePosition - Camera.main.WorldToScreenPoint(objectPosition)).sqrMagnitude;

    //    if (Distance >= maxDragDistance)
    //    {

    //    }
    //    else if (Distance < minDragDistance)
    //        return; // �ּ� �Ÿ����� �巡�׸� ���� �ʾҴٸ� �ٽ� �� �� �ְ� ����
    //    else
    //    {
    //        rigidbody.AddForce(objectPosition * hitPower);
    //    }
    //}
}