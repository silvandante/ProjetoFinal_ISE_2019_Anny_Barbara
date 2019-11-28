using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class gyro_receptor : MonoBehaviour {

	private float AmountToMove;
	public float x,y,z;

	SerialPort serial = new SerialPort("COM3",115200);

	void Start () {
		serial.Open();
		serial.ReadTimeout = 2000;
	}
	
	void Update () {
		if (!serial.IsOpen){
			serial.Open();
		}
		
		serial.Write("a");
		float AcX = int.Parse(serial.ReadLine());
		serial.Write("b");
		float AcY = int.Parse(serial.ReadLine());
		serial.Write("c");
		float AcZ = int.Parse(serial.ReadLine());
		serial.Write("d");
		float GyX = int.Parse(serial.ReadLine());
		serial.Write("e");
		float GyY = int.Parse(serial.ReadLine());
		serial.Write("f");
		float GyZ = int.Parse(serial.ReadLine());

		x = AcX/190;
		y+= GyY/3000;
		z+= GyX/3000;

		transform.localEulerAngles = new Vector3(-x,-y,-z);

	}


}
