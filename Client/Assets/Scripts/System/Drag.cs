using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drag : MonoBehaviour
{
    [SerializeField] private float maxSpeed = 1.0f;
    [SerializeField] private float maxDragDistance = 20.0f;
    [SerializeField] private float minDragDistance = 1.0f;
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
        float angle = -1;
        if (this.gameObject.tag == "Red") 
            angle = 0;
        if (this.gameObject.tag == "Blue")
            angle = 180;


        if (angle == -1) return;

        // 마우스 포지션과 오브젝트 거리 저장
        Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);
        Vector3 offset = new Vector3(scrSpace.x - Input.mousePosition.x, 0, scrSpace.y - Input.mousePosition.y);


        float distance = Mathf.Sqrt(offset.x * offset.x + offset.z * offset.z); // 벡터의 크기 계산
        offset /= distance; // 정규화

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
    //    // 속도 제한
    //    Vector3 mousePosition = Input.mousePosition;
    //    Vector3 objectPosition = this.transform.position;
        
    //    // SqrMagnitude : 벡터의 크기(혹은 길이)를 반환하는 메서드
    //    // 마우스 포지션과 알과의 거리를 계산한다.
    //    float Distance = (mousePosition - Camera.main.WorldToScreenPoint(objectPosition)).sqrMagnitude;

    //    if (Distance >= maxDragDistance)
    //    {

    //    }
    //    else if (Distance < minDragDistance)
    //        return; // 최소 거리보다 드래그를 하지 않았다면 다시 할 수 있게 리턴
    //    else
    //    {
    //        rigidbody.AddForce(objectPosition * hitPower);
    //    }
    //}
}
