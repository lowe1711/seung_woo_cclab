using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Playercontroller : MonoBehaviour {

	public float speed;
	private Rigidbody rb;
	public Text countText;
	public int count;

	// Use this for initialization
	void Start () {
		rb = GetComponent<Rigidbody> ();
	}
	
	// Update is called once per frame
	void Update () {
	
	}
	void FixedUpdate (){

		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		rb.AddForce (movement * speed);
	}
	void OnTriggerEnter(Collider other){

		if (other.gameObject.CompareTag ("Pick Up")) {

			other.gameObject.SetActive (false);
			count = count + 1; 
			SetCountText ();

		}

		if (other.gameObject.CompareTag ("Cap")) {

			other.gameObject.SetActive (false);
			count = count - 3; 
			SetCountText ();

		}
	}
	void SetCountText(){

		countText.text = "Count:" + count.ToString ();
		if (count >= 10) {

			countText.text = "You win!";
		}
	}
}
