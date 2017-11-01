import paramiko
from paramiko import SSHClient,AutoAddPolicy
from scp import SCPClient

# HOST = "arduino.local"
# PORT = "22"
# USER = "root"
# PSWD = "Watanabe0428"

# ssh = SSHClient()
# ssh.set_missing_host_key_policy(AutoAddPolicy())
# ssh.connect(HOST, port=PORT, username=USER, password=PSWD)

# scp = SCPClient(ssh.get_transport())
# scp.get("~/hoge.hoge")


def createSSHClient(server, port, user, password):
    client = paramiko.SSHClient()
    client.load_system_host_keys()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(server, port, user, password)
    return client

ssh = createSSHClient("arduino.local", 22,"root" , "Watanabe0428")
scp = SCPClient(ssh.get_transport())
f=open('log.log','r')
for i in range(1,1000):
    scp.get("~/log.log")
    s=f.read()
    print(s)

