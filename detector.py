from cvzone.SerialModule import SerialObject
from time import sleep
import requests

arduino = SerialObject()
server_address = "http://192.168.26.97"

while True:
    arduino.sendData("1")
    requests.get(f"{server_address}/1")
    sleep(1)
    arduino.sendData("0")
    requests.get(f"{server_address}/0")
    sleep(1)
