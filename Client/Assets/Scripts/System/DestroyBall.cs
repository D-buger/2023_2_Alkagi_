using UnityEngine;

public class DestroyBall : MonoBehaviour
{
    private void FixedUpdate()
    {
        if(tag == "Red" || tag == "Blue")
        {
            if(this.transform.position.x < -25 || this.transform.position.x > 25) 
            {
                Destroy(this.gameObject);
            }
            if(this.transform.position.z < -25 || this.transform.position.z > 25) 
            {
                Destroy(this.gameObject);
            }
        }
    }
}