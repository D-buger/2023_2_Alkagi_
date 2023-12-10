using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RenderLine : MonoBehaviour
{
    private bool clicked = false;
    private LineRenderer lineRenderer;

    void Start()
    {
        lineRenderer = gameObject.AddComponent<LineRenderer>();
        lineRenderer.GetComponent<LineRenderer>();

        lineRenderer.SetPosition(0, Vector3.zero);
        lineRenderer.SetPosition(1, Vector3.zero);

        lineRenderer.SetColors(Color.red, Color.yellow);
        lineRenderer.SetWidth(0.1f, 0.1f);
    }

    private void FixedUpdate()
    {
        if (clicked && GameManager.turn % 2 == 1 && tag == "Red")
        {
            Vector3 mousePosition = Input.mousePosition;

            Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);

            Vector3 offset = new Vector3(scrSpace.x - mousePosition.x, 0, scrSpace.y - mousePosition.y);

            lineRenderer.SetPosition(0, transform.position);
            lineRenderer.SetPosition(1, transform.position + offset / 5);
        }
        else if(clicked && GameManager.turn % 2  == 0 && tag == "Blue")
        {
            Vector3 mousePosition = Input.mousePosition;

            Vector3 scrSpace = Camera.main.WorldToScreenPoint(transform.position);

            Vector3 offset = new Vector3(scrSpace.x - mousePosition.x, 0, scrSpace.y - mousePosition.y);

            lineRenderer.SetPosition(0, transform.position);
            lineRenderer.SetPosition(1, transform.position - offset / 5);
        }
    }

    private void OnMouseDown()
    {
        clicked = true;
    }

    private void OnMouseUp() 
    {
        clicked = false;
        lineRenderer.SetPosition(0, transform.position);
        lineRenderer.SetPosition(1, transform.position);
    }
}
