import socket

host = "arduino.local"
port = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((host, port))

client.send("from nadechin")

response = client.recv(4096)

print response