import Server
import Client

serv = Server.server(8889, 10)
serv.start_main()
some_client = Client.client(8889)

for i in range(1000):
    some_client.receive_response()
